#include <chrono>
#include <functional>  // std::bind
#include <rclcpp/rclcpp.hpp>
#include <string>

using namespace std::chrono_literals;

class ParametersClass : public rclcpp::Node {
 public:
  ParametersClass() : Node("parameter_node") {
    // Create parameter name: my_parameter, value: world.
    this->declare_parameter<std::string>("my_parameter", "world");
    timer_ = this->create_wall_timer(
        1000ms,
        std::bind(&ParametersClass::respond,
                  this));  // respond function,can get parameter from this node
                           // and store parameter into object parameter_string_
  }
  void respond() {
    this->get_parameter("my_parameter", parameter_string_);
    RCLCPP_INFO(this->get_logger(), "Hello %s", parameter_string_.c_str());
  }

 private:
  std::string parameter_string_;
  rclcpp::TimerBase::SharedPtr timer_;
};

int main(int argc, char** argv) {
  rclcpp::init(argc, argv);
  rclcpp::spin(std::make_shared<ParametersClass>());
  rclcpp::shutdown();
  return 0;
}