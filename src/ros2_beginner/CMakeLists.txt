cmake_minimum_required(VERSION 3.5)
project(ros2_beginner)

# Default to C99
if(NOT CMAKE_C_STANDARD)
  set(CMAKE_C_STANDARD 99)
endif()

# Default to C++14
if(NOT CMAKE_CXX_STANDARD)
  set(CMAKE_CXX_STANDARD 14)
endif()

if(CMAKE_COMPILER_IS_GNUCXX OR CMAKE_CXX_COMPILER_ID MATCHES "Clang")
  add_compile_options(-Wall -Wextra -Wpedantic)
endif()

# find dependencies
find_package(ament_cmake REQUIRED)
find_package(rclcpp REQUIRED)
find_package(std_msgs REQUIRED)
find_package(ros2_beginner REQUIRED)
find_package(rosidl_default_generators REQUIRED)



include_directories(
  include
  ${ament_LIBRARIES}
)

if(BUILD_TESTING)
  find_package(ament_lint_auto REQUIRED)
  # the following line skips the linter which checks for copyrights
  # uncomment the line when a copyright and license is not present in all source files
  #set(ament_cmake_copyright_FOUND TRUE)
  # the following line skips cpplint (only works in a git repo)
  # uncomment the line when this package is not in a git repo
  #set(ament_cmake_cpplint_FOUND TRUE)
  ament_lint_auto_find_test_dependencies()
endif()

rosidl_generate_interfaces(${PROJECT_NAME}
  "msg/Person.msg"
  "srv/AddTwoInts.srv"
)

add_executable(publisher src/publisher.cpp)
ament_target_dependencies(publisher rclcpp std_msgs)

add_executable(subscriber src/subscriber.cpp)
ament_target_dependencies(subscriber rclcpp std_msgs)

add_executable(server_pop src/server_pop.cpp)
ament_target_dependencies(server_pop rclcpp std_msgs ros2_beginner)

add_executable(client_pop src/client_pop.cpp)
ament_target_dependencies(client_pop rclcpp std_msgs ros2_beginner)

add_executable(parameter_node src/cpp_parameters_node.cpp)
ament_target_dependencies(parameter_node rclcpp)

install(TARGETS
  publisher
  subscriber
  server_pop
  client_pop
  parameter_node
  DESTINATION lib/${PROJECT_NAME})
<<<<<<< HEAD
  
install(
    DIRECTORY launch
    DESTINATION share/${PROJECT_NAME}
  )
ament_package()
=======
ament_package()
>>>>>>> a0953c482514c2f408bc5a85ba58401aaa5f413f
