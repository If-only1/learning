#include <geometry_msgs/Twist.h>
#include <ros/ros.h>
#include <tf/transform_listener.h>
#include <turtlesim/Spawn.h>
int main(int argc, char** argv) {
    ros::init(argc, argv, "my_tf_listener");
    ros::NodeHandle nh;
    ros::service::waitForService("/spawn");
    ros::ServiceClient add_turtle = nh.serviceClient<turtlesim::Spawn>("/spawn");
    turtlesim::Spawn srv;
    add_turtle.call(srv);

    ros::Publisher tutle_vel = nh.advertise<geometry_msgs::Twist>("turtle2/cmd_vel", 10);
    tf::TransformListener listener;
    ros::Rate rate(10.0);
    while (ros::ok()) {
        tf::StampedTransform transform;
        try {
            listener.waitForTransform("/turtle2", "/turtle1",ros::Time(0),ros::Duration(3)));
            listener.lookupTransform("/turtle2", "/turtle1", ros::Time(0), transform);
        } catch (tf::TransformException ex) {
            ROS_ERROR("%s", ex.what());
            ros::Duration(1.0).sleep();
            continue;
        } catch (const std::exception& e) {
            std::cerr << e.what() << '\n';
            return -1;
        }
        geometry_msgs::Twist vel_msg;
        vel_msg.linear.x =
            sqrt(pow(transform.getOrigin().x(), 2) + pow(transform.getOrigin().y(), 2)) / 2;
        vel_msg.angular.z = atan2(transform.getOrigin().y(), transform.getOrigin().x());
        tutle_vel.publish(vel_msg);
        rate.sleep();
    }
    return 0;
}