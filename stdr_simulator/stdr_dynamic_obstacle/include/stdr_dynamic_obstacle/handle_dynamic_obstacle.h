#include <ros/ros.h>
#include <stdr_msgs/DynamicObstacleVector.h>
#include <stdr_msgs/AddDynamicObstacle.h>
#include <stdr_msgs/DeleteDynamicObstacle.h>
#include <stdr_dynamic_obstacle/exceptions.h>

#ifndef HANDLE_DYNAMIC_OBSTACLE_H
#define HANDLE_DYNAMIC_OBSTACLE_H

/**
@namespace stdr_dynamic_obstacle
@brief The main namespace for STDR dynamic obstacles
**/ 
namespace stdr_dynamic_obstacle {

  /**
  @class HandleDynamicObstacle
  @brief Handles the manipulation of dynamic obstacles (creation, deletion)
  **/ 
  class HandleDynamicObstacle {
    //------------------------------------------------------------------------//
    private:

    ros::NodeHandle _node;
    
    ros::ServiceClient _addDynamicObstacleClient;
    ros::ServiceClient _deleteDynamicObstacleClient;
      
    //------------------------------------------------------------------------//
    public:

      /**
      @brief Default constructor
      @return void
      **/
      HandleDynamicObstacle();
      
      /**
      @brief Spawns a new robot
      @param msg [const stdr_msgs::DynamicObstacleMsg]
      @return stdr_msgs::RobotIndexedMsgDynamicObstacleVector
      **/
      stdr_msgs::DynamicObstacleVector addNewDynamicObstacle(const stdr_msgs::DynamicObstacleMsg msg);
      
      /**
      @brief Deletes a robot by frame_id
      @param name [const std::string&] The robot frame_id to be deleted
      @return bool : True if deletion was successful
      **/
      bool deleteDynamicObstacle(const std::string& name);
  };
}

#endif
