# How to run

* Install [RaspberryPi wiringPi](http://www.wiringpi.com/) library (if you have ROS installed, then skip this step)
* git clone https://github.com/utommo/ED2-P2-H103.git
* cd /ED2-P2-H103/code
* scp -r /laser-module/ hostname@ip:/
* cd laser-module
* run cmake CMakeLists.txt
* run make
* sudo ./StartLaser

Modify and make if you want to change the code
