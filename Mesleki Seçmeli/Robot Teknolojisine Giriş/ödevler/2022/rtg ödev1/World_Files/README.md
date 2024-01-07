# Ros Gazebo Multi Robot Tutorial
This program modified by Yildiz Team (Erkan Uslu, Furkan Cakmak, Muhamet Balcilar, Fatih Amasyali, Sirma Yavuz) to demostrate the creation of multiple robots for RoboCup  Virtual Robot Competition. This code is tested by using a Gazebo5 server.
In case of any problem please contact 

uslu.erkan@gmail.com
furca609@gmail.com
muhammetbalcilar@gmail.com

# Server Side:
* Clone repository to your workspace
```
cd ~/catkin_ws/src

git clone https://github.com/YildizTeam/pioneer3at_demo.git
```

* Extract RC2012Pre1.dae.zip with following command:
```
cd ~/catkin_ws/src/pioneer3at_demo/p3at_gazebo/worlds/models/robocup2012_rvrl_pre1/meshes
unzip RC2012Pre1.dae.zip
```

* Build
```
cd ~/catkin_ws

catkin_make 

catkin_make install
```

* Run launch
```
roslaunch p3at_description empty_world_multi_robot_example.launch
```



# Client Side:
* Edit host file 
```
sudo gedit /etc/hosts
```
edit server ip and server host name


* Edit .bashrc
```
gedit .bashrc
```
set ros master uri according to your ros server..

* Test your connection 
```
rostopic list
```
You should be able to see the topic list.

* Open Rviz and add relevant topics
