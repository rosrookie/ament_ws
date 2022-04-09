/*
 * @Author: Loren
 * @Date: 2022-04-09 20:54:54
 * @LastEditTime: 2022-04-09 21:14:43
 * @FilePath: /ament_ws/src/ros2_beginner/src/subscriber.cpp
 * @Description: ROS2 Subscribe Demo.
 *
 * Copyright (c) 2022 by Loren, All Rights Reserved.
 */
#include "ros2_beginner/ros2_beginner.h"

using std::placeholders::_1;

// Constructor
MinimalSubscriber::MinimalSubscriber() : Node("subscrib") {
  str_subscriber_ = this->create_subscription<std_msgs::msg::String>(
      "str_tpoic", 10, std::bind(&MinimalSubscriber::topic_callback, this, _1));
}

/**
 * @description: Receive String message and put it on the screen.
 * @param {String message[std_msgs::msg::String]}
 * @return {None}
 */

void MinimalSubscriber::topic_callback(
    const std_msgs::msg::String::SharedPtr msg) const {
  RCLCPP_INFO(this->get_logger(), "I recevied: %s messages.",
              msg->data.c_str());
}

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalSubscriber>());
  rclcpp::shutdown();
  return 0;
}