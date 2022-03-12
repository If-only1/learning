#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <std_srvs/Trigger.h>
bool pub_command = false;
ros::Publisher pub;

bool call_back_fn(std_srvs::Trigger::Request &req, std_srvs::Trigger::Response &res) {
    pub_command = !pub_command;
    ROS_INFO("pub_command %d", pub_command);
    res.success = true;
    if (pub_command) {
        res.message = "change the state to pub";
    } else {
        res.message = "change the state to stop";
    }
    return true;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "turtle_command_server");
    ros::NodeHandle nh;
    ros::ServiceServer command_service = nh.advertiseService("/turtle_command", call_back_fn);
    pub = nh.advertise<geometry_msgs::Twist>("/turtle1/cmd_vel", 10);
    ros::Rate loop_rate(10);
    while (ros::ok()) {
        ros::spinOnce();
        if (pub_command) {
            geometry_msgs::Twist vel_msg;
            vel_msg.linear.x = 1;
            vel_msg.angular.z = 0.2;
            pub.publish(vel_msg);
        }
        loop_rate.sleep();
    }

    return 0;
}