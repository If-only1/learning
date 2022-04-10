#include <ros/ros.h>
#include <tf/transform_broadcaster.h>
#include <turtlesim/Pose.h>

#include <string>
using namespace std;
string turtle_name;
void callback_fn(const turtlesim::PoseConstPtr& msg) {
    tf::TransformBroadcaster br;
    tf::Transform transform;
    transform.setOrigin(tf::Vector3(msg->x, msg->y, 0));
    tf::Quaternion q;
    q.setRPY(0, 0, msg->theta);
    transform.setRotation(q);
    br.sendTransform(tf::StampedTransform(transform, ros::Time::now(), "world", turtle_name));
}
int main(int argc, char** argv) {
    if (argc < 2) {
        ROS_ERROR("need inpute the turtle name !");
        return -1;
    }
    ros::init(argc, argv, "my_tf_broadcaster");
    turtle_name = argv[1];
    ros::NodeHandle nh;
    ros::Subscriber sub = nh.subscribe(turtle_name + "/pose", 10, &callback_fn);
    ros::spin();
}