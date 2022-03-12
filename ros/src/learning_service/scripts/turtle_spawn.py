#! /home/lixianyang/miniconda3/envs/a100/bin/python

import rospy
from  turtlesim.srv import Spawn

def turtle_spawn():
    rospy.init_node('turtle_spawn')
    rospy.wait_for_service('/spawn')
    try:
        add_turtle=rospy.ServiceProxy('/spawn', Spawn)
        response=add_turtle(2,2,0,'turtle3')
        return response.name
    
    except rospy.ServiceException as e:
        print(f'catch exception {e}')


if __name__=='__main__':
    print(f"{turtle_spawn()} success.")