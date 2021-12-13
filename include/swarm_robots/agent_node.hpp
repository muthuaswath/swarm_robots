/**
 * @file agent.h
 * @author Kavyashree Devadiga (kavya@umd.edu), Aswath Muthuselvam
 * (aswath@umd.edu)
 * @brief The header file for coordinate system used in the project
 * @version 0.1
 * @date 2021-12-05
 * @copyright BSD3 Copyright (c) 2021
 *
 */

#ifndef INCLUDE_SWARM_ROBOTS_AGENT_NODE_HPP_
#define INCLUDE_SWARM_ROBOTS_AGENT_NODE_HPP_

#include <ros/ros.h>
#include <std_msgs/String.h>

#include <string>
#include <vector>

#include "agent.hpp"
#include "state.hpp"  //  NOLINT
#include "swarm_robots/service.h"


using std::string;
using std::vector;

class AgentNode : public Agent {
   public:  //  NOLINT
    /**
     * @brief AgentNode parameterized constructor,
     * initializes agent with given id
     * @param id : id of the agent - assigned to initialized
     * Agent Node object
     */
    explicit AgentNode(std::string id);

    /**
     * @brief AgentNode destructor
     */
    ~AgentNode();

    /**
     * @brief Path planner method for agent node
     */
    void PlanPath();

    /**
     * @brief Fetched and initialized current position of agent
     */
    void PosCallback(const nav_msgs::Odometry::ConstPtr& msg);

    /**
     * @brief Invokes IK method from agent class
     */
    void PerformInverseKinematics();

    /**
     * @brief Invokes FK method from agent class
     */
    void PerformForwardKinematics();

    /**
     * @brief Checks if ROS::OK and invokes methods in loop
     */
    void Loop();

    /**
    * @brief Service function that is called with /service, this function changes
    * the message according to the user's input.
    * @param req : Request object reference from service file, it contains the
    * parameters related to the service input.
    * @param res : Response object reference from service file, it contains the
    * parameteres of the service output.
    * @return bool flag indicating success or failure of service method.
    */
    bool SwarmService(swarm_robots::service::Request &req,    // NOLINT
               swarm_robots::service::Response &res);  // NOLINT

    /**
    * @brief Service function that is called with /service, this function changes
    * the message according to the user's input.
    * @param req : Request object reference from service file, it contains the
    * parameters related to the service input.
    * @param res : Response object reference from service file, it contains the
    * parameteres of the service output.
    */

   private:                           // NOLINT
    int krate_;                       ///< Variable to store ros loop rate
    ros::NodeHandlePtr nh_;             ///< Variable to store ros node handle for executing node // NOLINT
    ros::Publisher vel_pub_;          ///< Variable to store velocity publisher
    ros::Subscriber pos_sub_;         ///< Variable to store position subscriber
    geometry_msgs::Twist twist_msg_;  ///< Variable to store velocity twist message to pass to publisher // NOLINT
    std::string agent_id;             ///< Variable to store object agent id
    ros::ServiceServer service_;  ///< Service object

};

#endif  // INCLUDE_SWARM_ROBOTS_AGENT_NODE_HPP_
