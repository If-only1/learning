#include <geometry_msgs/Twist.h>
#include <ros/ros.h>

int main(int argc, char **argv) {
    //节点初始化
    ros::init(argc, argv, "velocity_publisher");
    //创建节点句柄：用于管理节点资源
    ros::NodeHandle n;
    //创建发布者,话题名、队列长度
    ros::Publisher turtle_vel_pub{n.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10)};
    ros::Rate loop_rate(10);
    int count{0};
    while (ros::ok()) {
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.x = 0.5;
        vel_msg.angular.z = 0.2;
        turtle_vel_pub.publish(vel_msg);
        ROS_INFO("pubulish the message %0.2f m/s %0.2f rad/s", vel_msg.linear.x, vel_msg.angular.z);
        loop_rate.sleep();
    }
    return 0;
}
