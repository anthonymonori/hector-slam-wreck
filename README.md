# hector-slam-wreck
A robotic system designed to take advantage of already existing technologies to create a 2d/3d map of a room.

### Modules
1. An obstacle-avoidance system written in Python that uses ultrasonic sensors to navigate and 4 DC motors through PWM for movement.
2. A lidar-laser module that collects 360 deg information regarding it's surrounding to later create a 2d/3d map using ROS.

### Requirements
- Raspberry Pi 2 Model B 512 MB or higher microcontroller
- Ubuntu distribution with ROS framework installed and set up
- hector-slam module
- LIDAR Lite v1 or v2 laser

### General instruction to run the project
- Install Ubuntu ARM on a Raspberry Pi 2 Model B (or newer, similar hardware configuration).
- Install ROS Indigo distribution for Ubuntu ARM with desktop tools.
- Clone code, install libraries, dependencies.
- Setup nodes, run roscore, start necessary nodes: rosrun lidarlite_laser laser_scan
- Using rviz, visualize the generated map.

### Contributors:
- [utommo](https://github.com/utommo)
- [emilioamores](https://github.com/emilioamores)
- [42f87d89](https://github.com/42f87d89)
- [anthonymonori](https://github.com/anthonymonori)

