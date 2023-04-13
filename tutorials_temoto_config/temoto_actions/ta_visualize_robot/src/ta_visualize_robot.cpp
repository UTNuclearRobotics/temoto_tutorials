
/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 *
 *  The basis of this file has been automatically generated
 *  by the TeMoto action package generator. Modify this file
 *  as you wish but please note:
 *
 *    WE HIGHLIY RECOMMEND TO REFER TO THE TeMoto ACTION
 *    IMPLEMENTATION TUTORIAL IF YOU ARE UNFAMILIAR WITH
 *    THE PROCESS OF CREATING CUSTOM TeMoto ACTION PACKAGES
 *    
 *  because there are plenty of components that should not be
 *  modified or which do not make sence at the first glance.
 *
 *  See TeMoto documentation & tutorials at: 
 *    https://github.com/temoto-framework
 *
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

#include <class_loader/class_loader.hpp>
#include "ta_visualize_robot/temoto_action.h"
#include "temoto_visualization_manager/visualization_manager_interface.h"

/* 
 * ACTION IMPLEMENTATION of TaVisualizeRobot 
 */
class TaVisualizeRobot : public TemotoAction
{
public:

/*
 * Function that gets invoked only once (when the action is initialized) throughout the action's lifecycle
 */
void initializeTemotoAction()
{
  TEMOTO_INFO_STREAM("Action initialized");
}

/*
 * Function that gets invoked when the action is executed (REQUIRED)
 */
void executeTemotoAction()
{
  getInputParameters();
  vmi_.initialize();

  TEMOTO_INFO_STREAM("Showing robot '" << in_param_robot_name << "' in RViz ...");
  std::string robot_description_rviz_config = "{Robot Description: " + in_param_robot_description + "}";
  vmi_.loadRvizPlugin("rviz/RobotModel", "", robot_description_rviz_config, in_param_robot_name + " model");
  TEMOTO_INFO_STREAM("Robot '" << in_param_robot_name << "' visualized");
}

// Destructor
~TaVisualizeRobot()
{
  TEMOTO_INFO("Action instance destructed");
}

// Loads in the input parameters
void getInputParameters()
{
  in_param_robot_name = GET_PARAMETER("robot_name", std::string);
  in_param_robot_description = GET_PARAMETER("robot_description", std::string);
}

/* * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * 
 * Class members
 * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * * */

temoto_visualization_manager::VisualizationManagerInterface vmi_;

// Declaration of input parameters
std::string in_param_robot_name;
std::string in_param_robot_description;


}; // TaVisualizeRobot class

/* REQUIRED BY CLASS LOADER */
CLASS_LOADER_REGISTER_CLASS(TaVisualizeRobot, ActionBase);
