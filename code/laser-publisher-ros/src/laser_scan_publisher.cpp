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
#include "lidarLite.h"

int main(int argc, char** argv){
    int fd = lidar_init(true);
    // If init failed
    if (fd == -1) {
        printf("initialization error\n");
    }

    ros::init(argc, argv, "laser_scan_publisher");

    ros::NodeHandle n;
    ros::Publisher scan_pub = n.advertise<sensor_msgs::LaserScan>("scan", 50);

    unsigned int num_readings = 200; //number of readings in one packet.
    double laser_frequency = 40; //how many spins in one second
    double ranges[num_readings];

    ros::Rate fullScan(1.0);
    ros::Rate singleStep(0.25);
    while(n.ok()){
        //sets up the relevant info about the laser
        sensor_msgs::LaserScan scan;
        scan.header.stamp = scan_time;
        scan.header.frame_id = "laser_frame";
        scan.angle_min = -1.57;//angles in radians
        scan.angle_max = 1.57;
        scan.angle_increment = 3.14 / num_readings;
        scan.time_increment = (1 / laser_frequency) / (num_readings); //time between measurements in seconds
        scan.range_min = 0.1;//the distance range. in meters
        scan.range_max = 40.0;//set to 40 or less for our laser

        //publish the data to /scan
        scan.ranges.resize(num_readings);
        for(unsigned int i = 0; i < num_readings; ++i){
            scan.ranges[i] = lidar_read(fd);
            singleStep.sleep()
        }

        scan_pub.publish(scan);
        fullScan.sleep();
    }
}
