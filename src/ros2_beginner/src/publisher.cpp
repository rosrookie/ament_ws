/*
 * @Author: Loren
 * @Date: 2022-04-09 19:59:28
 * @LastEditTime: 2022-04-09 21:14:10
 * @FilePath: /ament_ws/src/ros2_beginner/src/publisher.cpp
 * @Description: ROS2 Publisher Demo.
 *
 * Copyright (c) 2022 by Loren, All Rights Reserved.
 */

#include "ros2_beginner/ros2_beginner.h"

// Constructor
MinimalPublisher::MinimalPublisher() : Node("publisher"), count_(0) {
  str_publisher_ =
      this->create_publisher<std_msgs::msg::String>("str_tpoic", 10);
  timer_ = create_wall_timer(
      500ms, std::bind(&MinimalPublisher::timer_callback, this));
  RCLCPP_INFO(this->get_logger(), "Constructor Initalized.");
}

void MinimalPublisher::timer_callback() {
  auto message = std_msgs::msg::String();
  message.data = "Hello, world!" + std::to_string(count_++);
  str_publisher_->publish(message);
  RCLCPP_INFO(this->get_logger(), "Publisheing: %s", message.data.c_str());
}

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<MinimalPublisher>());
  rclcpp::shutdown();
}