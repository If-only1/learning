#include <learning_topic/Person.h>
#include <ros/ros.h>

void personCallback(const learning_topic::Person &msg) {
    ROS_INFO("person name:%s age:%d", msg.name.c_str(), msg.age);
}

int main(int argc, char **argv) {
    ros::init(argc, argv, "person_subscriber");
    ros::NodeHandle nh;
    ros::Subscriber person_sub{nh.subscribe("/person_info", 10, personCallback)};
    ros::spin();
    return 0;
}
