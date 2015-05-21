/*********************************************************************
*
* Software License Agreement (BSD License)
*
*    Copyright (c) 2009, Willow Garage, Inc.
*    All rights reserved.
*
*    Redistribution and use in source and binary forms, with or without
*    modification, are permitted provided that the following conditions
*    are met:
*
*     * Redistributions of source code must retain the above copyright
*         notice, this list of conditions and the following disclaimer.
*     * Redistributions in binary form must reproduce the above
*         copyright notice, this list of conditions and the following
*         disclaimer in the documentation and/or other materials provided
*         with the distribution.
*     * Neither the name of Willow Garage, Inc. nor the names of its
*         contributors may be used to endorse or promote products derived
*         from this software without specific prior written permission.
*
*    THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
*    "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
*    LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS
*    FOR A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE
*    COPYRIGHT OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT,
*    INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING,
*    BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES;
*    LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
*    CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT
*    LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN
*    ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
*    POSSIBILITY OF SUCH DAMAGE.
*
* Author: Eitan Marder-Eppstein
*********************************************************************/
#include <ros/ros.h>
#include <sensor_msgs/LaserScan.h>
#include <iostream>
#include <wiringPi.h>
#include <stdlib.h>

extern "C" int lidar_init(bool);
extern "C" int lidar_read(int);

#define PIN16 23
#define PIN18 24

//PIN16 is the pin #16 on the pi diagram
// use for setting up the motorcontroller

//PIN18 is the pin #18 on the pi diagram
// use for controlling the steps

void setUpPins(){
    system("gpio export 23 out");
    system("gpio export 24 out");
    system("gpio -g write 23 1");
}

void step(int steps){
    for(int i = 0; i<steps; i++){
        system("/home/ubuntu/gpioThing.sh");
    }
}


int main(int argc, char** argv){
    int fd = lidar_init(false);//set to true for printouts
    setUpPins();
    // If init failed
    if (fd == -1) {
        printf("initialization error\n");
    }

    ros::init(argc, argv, "laser_scan_publisher");

    ros::NodeHandle n;
    ros::Publisher scan_pub = n.advertise<sensor_msgs::LaserScan>("scan", 10);

    const unsigned int num_readings = 50; //number of readings in one packet.
    const unsigned int num_steps = 1;
    const double laser_frequency = 0.5/*MIGHT CHANGE*/; //how many spins in one second
    const unsigned short circle_segments = 4;
    const double pi = 3.141592;

    int i = 0;
    while(n.ok()){
        ros::Time scan_time = ros::Time::now();

        //sets up the relevant info about the laser
        sensor_msgs::LaserScan scan;
        scan.header.frame_id = "laser";
        scan.angle_min = i*(0.5*pi); // angles in radians
        scan.angle_max = (++i)*(0.5*pi);
        scan.angle_increment = 2*pi / (200/num_steps);
        scan.time_increment = (1 / laser_frequency) / (num_readings); //time between measurements in seconds
        scan.range_min = 0.1;//the distance range. in meters
        scan.range_max = 40.0;//set to 40 or less for our laser
        scan.scan_time = 0.02;
        scan.header.stamp = scan_time;

        //publish the data to /scan
        scan.ranges.resize(num_readings);
        for(unsigned int i = 0; i < num_readings; ++i){
            step(num_steps);
            scan.ranges[i] = lidar_read(fd)/100.0;
        }

        scan_pub.publish(scan);
    }
}
