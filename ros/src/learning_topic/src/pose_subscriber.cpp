#include <ros/ros.h>
#include <turtlesim/Pose.h>

void poseCallback(const turtlesim::Pose::ConstPtr &msg) {
    ROS_INFO("turtle pose x:%0.2f y:%0.2f", msg->x, msg->y);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "psoe_subscriber");
    ros::NodeHandle n;
    ros::Subscriber pose_sub{n.subscribe("/turtle1/pose", 10, poseCallback)};
    ros::spin();  //循环等待回调函数
    return 0;
}
