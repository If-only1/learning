#include <ros/ros.h>
#include <turtlesim/Spawn.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "turtle_spawn");
    ros::NodeHandle nh;
    ros::service::waitForService("/spawn");
    ros::ServiceClient add_turtle = nh.serviceClient<turtlesim::Spawn>("/spawn");
    turtlesim::Spawn srv;
    srv.request.x = 2.;
    srv.request.y = 2.;
    srv.request.name = "turtle2";
    ROS_INFO("call service to spwan turtle %s", srv.request.name.c_str());
    add_turtle.call(srv);
    ROS_INFO("succees %s", srv.response.name.c_str());
    return 0;
}