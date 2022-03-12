#include <learning_topic/Person.h>
#include <ros/ros.h>

int main(int argc, char **argv) {
    ros::init(argc, argv, "person_publisher");
    ros::NodeHandle nh;
    ros::Publisher person_pub{nh.advertise<learning_topic::Person>("/person_info", 10)};
    ros::Rate loop_rate(1);
    int count{0};
    while (ros::ok()) {
        learning_topic::Person person;
        person.age = 10;
        person.sex = learning_topic::Person::male;
        person.name = "tom";
        person_pub.publish(person);
        ROS_INFO("pubulish the person message  name %s, age %d, sex %d", person.name.c_str(),
                 person.age, person.sex);
        loop_rate.sleep();
    }
    return 0;
}
