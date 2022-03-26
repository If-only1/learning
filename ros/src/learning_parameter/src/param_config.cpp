#include <ros/ros.h>
#include <std_srvs/Empty.h>
#include <iostream>
using namespace std;
int main(int argc, char** argv) {
    int r;
    ros::init(argc, argv, "param_config");
    ros::NodeHandle node;
    ros::param::get("/background_r", r);
    cout << "r:" << r << endl;
    ros::param::set("/background_r", 255);
    ros::param::get("/background_r", r);
    cout << "r:" << r << endl;
    ros::service::waitForService("/clear");
    std_srvs::Empty meg;
    ros::ServiceClient clear_client = node.serviceClient<std_srvs::Empty>("/clear");
    clear_client.call(meg);
    sleep(1);
    return 0;
}