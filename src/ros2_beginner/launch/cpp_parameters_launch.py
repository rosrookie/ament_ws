from launch import LaunchDescription
from launch_ros.actions import Node


def generate_launch_description():
    return LaunchDescription(
        [
            Node(
                package="ros2_beginner",
                executable="parameter_node",
                name="custom_parameter_node",
                output="screen",
                emulate_tty=True,
                parameters=[
                    {"my_parameter": "earth"}
                ]
            )
        ]
    )
