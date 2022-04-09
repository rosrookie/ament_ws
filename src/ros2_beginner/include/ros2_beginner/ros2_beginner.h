/*
 * @Author: Loren
 * @Date: 2022-04-09 20:17:50
 * @LastEditTime: 2022-04-09 21:13:40
 * @FilePath: /ament_ws/src/ros2_beginner/include/ros2_beginner/ros2_beginner.h
 * @Description: ROS2 Beginner Head File.
 *
 * Copyright (c) 2022 by Loren, All Rights Reserved.
 */
#include <chrono>
#include <functional>
#include <iostream>
#include <memory>
#include <rclcpp/rclcpp.hpp>
#include <std_msgs/msg/string.hpp>

using namespace std::chrono_literals;

class MinimalPublisher : public rclcpp::Node {
 public:
  MinimalPublisher();
  ~MinimalPublisher() = default;

 private:
  void timer_callback();
  rclcpp::TimerBase::SharedPtr timer_;
  rclcpp::Publisher<std_msgs::msg::String>::SharedPtr str_publisher_;
  size_t count_;
};

class MinimalSubscriber : public rclcpp::Node {
 public:
  MinimalSubscriber();
  ~MinimalSubscriber() = default;

 private:
  void topic_callback(const std_msgs::msg::String::SharedPtr msg) const;
  rclcpp::Subscription<std_msgs::msg::String>::SharedPtr str_subscriber_;
};