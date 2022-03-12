#include <learning_service/Person.h>
#include <ros/ros.h>

bool call_back_fn(learning_service::Person::Request &req, learning_service::Person::Response &res) {
    ROS_INFO("get the request name: %s  age: %d sex%d", req.name.c_str(), req.age, req.sex);
    res.result = "ok";
    return true;
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "person_server");
    ros::NodeHandle nh;
    ros::ServiceServer person_service = nh.advertiseService("/show_person", call_back_fn);
    ROS_INFO("wait for the req");
    ros::spin();
    return 0;
}