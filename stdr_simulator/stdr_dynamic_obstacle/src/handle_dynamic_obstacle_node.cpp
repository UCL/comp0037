#include <stdr_dynamic_obstacle/handle_dynamic_obstacle.h>
#include <stdr_parser/stdr_parser.h>

#define USAGE "USAGE: robotdynamic_object_handler add <description.yaml> <x> <y> <theta>\n" \
"OR: robot_handler delete <robot_name>\n"\
"OR: robot_handler replace <robot_name> <new_x> <new_y> <new_theta>"

/**
@brief Main function of the server node
@param argc [int] Number of input arguments
@param argv [char**] Input arguments
@return int
**/
int main(int argc, char** argv) {
  
  ros::init(argc, argv, "dynamic_object_spawner", ros::init_options::AnonymousName);
  ROS_WARN_STREAM("dynamic_object_handler: " << __LINE__);
  
  stdr_dynamic_obstacle::HandleDynamicObstacle handler;
  ROS_WARN_STREAM("dynamic_object_handler: " << __LINE__);
  
  //!< add
  if (std::string(argv[1]) == "add") {
    
    stdr_msgs::DynamicObstacleMsg msg;
  ROS_WARN_STREAM("dynamic_object_handler: " << __LINE__);

    try {
      //msg = stdr_parser::Parser::createMessage
      //   <stdr_msgs::DynamicObstacleMsg>(std::string(argv[2]));
  ROS_WARN_STREAM("dynamic_object_handler: " << __LINE__);
    }
    catch(stdr_parser::ParserException& ex)
    {
      ROS_ERROR("[STDR_PARSER] %s", ex.what());
      return -1;
    }
    
  ROS_WARN_STREAM("dynamic_object_handler: " << __LINE__);
    stdr_msgs::DynamicObstacleVector namedRobot;
  ROS_WARN_STREAM("dynamic_object_handler: " << __LINE__);

     ROS_WARN_STREAM("add: invoked");
    
    try {
  ROS_WARN_STREAM("dynamic_object_handler: " << __LINE__);
      namedRobot = handler.addNewDynamicObstacle(msg);
  ROS_WARN_STREAM("dynamic_object_handler: " << __LINE__);
      return 0;
    }
    catch (stdr_dynamic_obstacle::ConnectionException& ex) {
      ROS_ERROR("%s", ex.what());
      return -1;
    }
    
  }
  #if 0
  //!< delete
  else if ((argc == 3) && (std::string(argv[1]) == "delete")) {
    
    std::string name(argv[2]);
    
    try {
      if (handler.deleteRobot(name)) {
        ROS_INFO("Robot %s deleted successfully", name.c_str());
      }
      else {
        ROS_ERROR("Could not delete robot %s", name.c_str());
      }
      
      return 0;
    }
    catch (stdr_dynamic_obstacle::ConnectionException& ex) {
      ROS_ERROR("%s", ex.what());
      return -1;
    }
    
  }
  
  //!< replacement
  else if ((argc == 6) && (std::string(argv[1]) == "replace")) {
    
    std::string name(argv[2]);
    
    geometry_msgs::Pose2D newPose;
    newPose.x = atof(argv[3]);
    newPose.y = atof(argv[4]);
    newPose.theta = atof(argv[5]);
    
    if (handler.moveRobot(name, newPose)) {
      ROS_INFO("%s moved to new pose with x: %f, y: %f, theta: %f", 
        name.c_str(), newPose.x, newPose.y, newPose.theta);
      return 0;
    }
    
    ROS_ERROR("Could not move %s", name.c_str());
    return -1;
  }
  // wrong args
  else {
    ROS_ERROR("%s", USAGE);
    exit(-1);
  }
  #endif
}
