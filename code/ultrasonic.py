#!/usr/bin/python
import time
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)

#Pins
TRIGGER = 4
ECHO = 17
#Preset dist
dist = 0


def getdist():
    #Sending the 10microsecond pulse nedded
    GPIO.output(TRIGGER, True)
    time.sleep(0.00001)
    GPIO.output(TRIGGER, False)
    #When echo goes high the time starts
    while GPIO.input(ECHO)==0:
        pass    
    start = time.time()
    #When echo goes low the time stops
    while GPIO.input(ECHO)==1:
        pass
    stop = time.time()

    #The time difference * speedofsound
    #Divided by two since the since the distance meassured is back and forth
    distance = ((stop-start) * 34000)/2

    return distance

##############################
##############################

GPIO.setup(TRIGGER,GPIO.OUT)
GPIO.setup(ECHO,GPIO.IN)      

#Setting up the sensor (0.1second to 'load' the module)
GPIO.output(TRIGGER, False)
time.sleep(0.1)

#Getting an inital distance
dist = getdist()
#While loop to check if the distance is over 5cm
while dist > 5.0:
    dist = getdist()
    print(dist)
    #For testing purposes
    time.sleep(1)

print("Distance: %.5f ") % dist

GPIO.cleanup()
