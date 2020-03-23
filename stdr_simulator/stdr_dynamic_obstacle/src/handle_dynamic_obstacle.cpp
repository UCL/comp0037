#include <stdr_dynamic_obstacle/handle_dynamic_obstacle.h>

namespace stdr_dynamic_obstacle {

  /**
  @brief Default constructor
  @return void
  **/
  HandleDynamicObstacle::HandleDynamicObstacle()
  {
    //ros::ServiceClient
    _addDynamicObstacleClient = _node.serviceClient<stdr_msgs::AddDynamicObstacle>("stdr_server/add_dynamic_obstacle");
    _deleteDynamicObstacleClient = _node.serviceClient<stdr_msgs::DeleteDynamicObstacle>("stdr_server/delete_dynamic_obstacle");
  }

  /**
  @brief Spawns a new robot
  @param msg [const stdr_msgs::RobotMsg] The robot message from which the robot is created
  @return stdr_msgs::RobotIndexedMsg : The robot message with the proper frame_id
  **/
  stdr_msgs::DynamicObstacleVector HandleDynamicObstacle::addNewDynamicObstacle(
    const stdr_msgs::DynamicObstacleMsg msg) 
  {
    stdr_msgs::AddDynamicObstacle srv;
    srv.request.newObstacle.name = "a";
    srv.request.newObstacle.probability_of_existence = 1.0f;
    srv.request.newObstacle.start_when_first_observed = false;
    srv.request.newObstacle.mean_wait_time = 5;
    srv.request.newObstacle.footprint.radius = 1;
      
    while (!ros::service::waitForService("stdr_server/add_dynamic_obstacle", ros::Duration(1)) && ros::ok()) {
      ROS_WARN("Could not find stdr_server/add_dynamic_obstacle service.");
    }
    bool success = _addDynamicObstacleClient.call(srv);

    ROS_WARN_STREAM("success=" << success);
    
#if 0    
    /*
    bool success = _spawnDynamicObstacleClient.waitForResult(ros::Duration(10));
    if (!success) {
      throw ConnectionException("Could not add dynamic obstacle...");
    }
    
    actionlib::SimpleClientGoalState state = _spawnDynamicObstacleClient.getState();
    if(state.toString() == "ABORTED")
    {
      std::string msg = std::string("Could not  add dynamic obstacle. ") + 
        _spawnDynamicObstacleClient.getResult()->message;
      throw DoubleFrameIdException(msg);
    }
    
    ROS_INFO("New robot spawned successfully, with name %s.", 
      _spawnDynamicObstacleClient.getResult()->indexedDescription.name.c_str());
    
    return _spawnDynamicObstacleClient.getResult()->indexedDescription;
    */
    #endif
  }

  /**
  @brief Deletes a robot by frame_id
  @param name [const std::string&] The robot frame_id to be deleted
  @return bool : True if deletion was successful
  **/
  bool HandleDynamicObstacle::deleteDynamicObstacle(const std::string& name) 
  {
    /*
    stdr_msgs::DeleteRobotGoal goal;
    goal.name = name;
    
    while (!_deleteDynamicObstacleClient.waitForServer(ros::Duration(1)) && ros::ok()) {
      ROS_WARN("Could not find stdr_server/delete_robot action.");
    }
    
    _deleteDynamicObstacleClient.sendGoal(goal);
    
    bool success = _deleteDynamicObstacleClient.waitForResult(ros::Duration(10));
    
    if (!success) {
      throw ConnectionException("Could not delete robot, connection error...");
    }
    
    return _deleteDynamicObstacleClient.getResult()->success;
    */
  }
    
} // end of namespace stdr_dynamic_obstacle
