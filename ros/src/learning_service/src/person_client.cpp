#include <learning_service/Person.h>
#include <ros/ros.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "person_client");
    ros::NodeHandle nh;
    ros::service::waitForService("/show_person");
    ros::ServiceClient person_client = nh.serviceClient<learning_service::Person>("/show_person");
    learning_service::Person srv;
    srv.request.name = "li";
    srv.request.age = 18;
    srv.request.sex = learning_service::Person::Request::male;
    ROS_INFO("call service  %s ...", srv.request.name.c_str());
    person_client.call(srv);
    ROS_INFO("result %s", srv.response.result.c_str());
    return 0;
}