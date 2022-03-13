#! /home/lixianyang/miniconda3/envs/a100/bin/python
import rospy
from turtlesim.msg import Pose

def poseCallback(msg):
    rospy.loginfo('pose x: %.2f %.2f',msg.x,msg.y)

def main():
    rospy.init_node('pose_subscriber')
    rospy.Subscriber('/turtle1/pose',Pose,poseCallback)
    rospy.spin()


if __name__=='__main__':
    main()