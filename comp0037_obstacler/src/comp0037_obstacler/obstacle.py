# -*- coding: utf-8 -*-
import rospy
from std_msgs.msg import Int32
from numpy.random import exponential
from numpy.random import uniform
import random
from time import sleep

# This class stores an obstacle

class Obstacle(object):

    def __init__(self, id, waitBeta, probabilityOfBeingPresent):
        self.id = int(id)
        # Documentation at https://docs.scipy.org/doc/numpy-1.15.0/reference/generated/numpy.random.exponential.html
        # is wrong. The equation suggests that beta=1/lambda whereas, in fact, beta=lambda
        self.waitLambda = waitBeta
        self.probabilityOfBeingPresent = probabilityOfBeingPresent
        self.isInSimulation = False
        self.hasBeenDetected = False
        self.addObstacleToSimulationPublisher = \
            rospy.Publisher("/add_obstacle_to_simulation", Int32, queue_size=1)
        self.removeObstacleFromSimulationPublisher = \
            rospy.Publisher("/remove_obstacle_from_simulation", Int32, queue_size=1)
        self.addObstacleToMapPublisher = \
            rospy.Publisher("/add_obstacle_to_map", Int32, queue_size=1)
        self.removeObstacleFromMapPublisher = \
            rospy.Publisher("/remove_obstacle_from_map", Int32, queue_size=1)
        rospy.logwarn('Added obstacle {} with waitLamba={}, probabilityOfBeingPresent={}'.format(self.id, self.waitLambda, self.probabilityOfBeingPresent))
        
        sleep(1)

    def sameID(self, id):
        return abs(self.id - id) < 1e-3

    def detectedByLaser(self):

        # If the obstacle has been detected, there's nothing to do
        if self.hasBeenDetected is True:
            return

        self.hasBeenDetected = True
        
        # From the exponential distribution, sample the sleep until time
        visibleTime = exponential(self.waitLambda)
        self.sleepUntilTime = rospy.Time.now() + rospy.Duration.from_sec(visibleTime)

        rospy.logwarn('Obstacle {} detected and will persist for {} seconds'.format(self.id, visibleTime))

        self.addObstacleToMapPublisher.publish(self.id)

    def update(self):

        # If the object is currently visible, check if the time has expired. If it
        # has, hide the object and disable it from showing again
        if self.hasBeenDetected is False:
            return

        if self.isInSimulation is False:
            return

        if rospy.Time.now() < self.sleepUntilTime:
            return

        # Send hide message
        rospy.logwarn('Object {} hiding'.format(self.id))
        self.isInSimulation = False
        self.removeObstacleFromSimulationPublisher.publish(self.id)
        self.removeObstacleFromMapPublisher.publish(self.id)

    # Reset the object state
    def reset(self):
 
        # If currently being shown, remove it 
        if self.isInSimulation is True:
            self.removeObstacleFromSimulationPublisher.publish(self.id)
            self.removeObstacleFromMapPublisher.publish(self.id)

        self.hasBeenDetected = False
        
        # Check the probability that the obstacle is present; if not return
        if (uniform() > self.probabilityOfBeingPresent):
            rospy.logwarn('Obstacle {} not present'.format(self.id))
            self.isInSimulation = False
            return

        self.isInSimulation = True
        rospy.logwarn('Obstacle {} is present; registering it with the simulation'.format(self.id))
        self.addObstacleToSimulationPublisher.publish(self.id)


