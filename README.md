# hector-slam-wreck
A robotic system designed to take advantage of already existing technologies to create a 2d/3d map of a room.

### Modules
1. An obstacle-avoidance system written in Python that uses ultrasonic sensors to navigate and 4 DC motors through PWM for movement.
2. A lidar-laser module that collects 360 deg information regarding it's surrounding to later create a 2d/3d map using ROS.

### Requirements
- HC-SR04 Ultrasonic Range Finder (3 of them)
- DFRobot 4WD Arduino-Compatible Platform with Encoders
- Pololu DRV8833
- https://www.thingiverse.com/thing:781918 (3D printed enclosures for ultrasonic sensors)
- LIDAR-Lite Laser Rangefinder v1
- Slip Ring with 22mm rim
- 12V, 350mA, 28oz-in NEMA-17 Bipolar Stepper Motor
- EasyDriver - Stepper Motor Driver
- http://www.thingiverse.com/thing:662646 (3d printed case for microcontroller and stepper motor for rotating the lidar laser)
- Raspberry Pi 2 Model B ARM Cortex-A7 Quad Core CPU 900MHz 1GB RAM
- Arduino Uno

### General instruction to run the project
- Upload /utils/rotate-stepper.cpp to the Arduino Uno connected to the stepper motor in the 360 case
- Install Ubuntu ARM on a Raspberry Pi 2 Model B (or newer, similar hardware configuration)
- Install ROS Indigo distribution for Ubuntu ARM with desktop tools
- sudo apt-get install github
- git clone https://github.com/anthonymonori/hector-slam-wreck.git
- cp ./utils/gpioThing.sh /home/ubuntu/gpioThing.sh
- install lidarlite_scan package
- setup nodes
- run roscore
- start necessary nodes, see main.launch file
- rosrun lidarlite_laser laser_scan
- python /utils/obstacle-avoidance.py
- Using rviz, visualize the generated map.

### Contributors:
- [utommo](https://github.com/utommo)
- [emilioamores](https://github.com/emilioamores)
- [42f87d89](https://github.com/42f87d89)
- [anthonymonori](https://github.com/anthonymonori)
