// Copyright 2014 Open Source Robotics Foundation, Inc.
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//     http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

// #include <sstream>
#include <iostream>

// #include "ros/ros.h"
#include <rclcpp/rclcpp.hpp>

// #include "std_msgs/String.h"
#include <simple_msgs/String.h>

int main(int argc, char * argv[])
{
  // ros::init(argc, argv, "talker");
  rclcpp::init(argc, argv);

  // ros::NodeHandle n;
  auto node = rclcpp::node::Node::make_shared("talker");

  // ros::Publisher chatter_pub = n.advertise<std_msgs::String>("chatter", 7);
  auto chatter_pub = node->create_publisher<simple_msgs::String>("chatter", 7);

  // ros::Rate loop_rate(10);
  rclcpp::WallRate loop_rate(2);

  // std_msgs::String msg;
  auto msg = std::make_shared<simple_msgs::String>();
  // int count = 0;
  auto i = 1;

  // while (ros::ok())
  while (rclcpp::ok()) {
    // std::stringstream ss;
    // ss << "hello world " << count;
    // msg.data = ss.str();
    msg->data = "Hello World: " + std::to_string(i++);  // ++count;
    // ROS_INFO("%s", msg.data.c_str());
    std::cout << "Publishing: '" << msg->data << "'" << std::endl;
    // chatter_pub.publish(msg);
    chatter_pub->publish(msg);
    // ros::spinOnce();
    rclcpp::spin_some(node);
    // loop_rate.sleep();
    loop_rate.sleep();
  }

  return 0;
}
