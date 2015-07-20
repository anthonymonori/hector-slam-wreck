#!/usr/bin/python
import time
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
print("Program started")
#Pins
TRIGGER_LEFT = 4
ECHO_LEFT = 17

TRIGGER_RIGHT = 18
ECHO_RIGHT = 22

TRIGGER_CENTER = 23
ECHO_CENTER = 24

#Preset dist
dist_left = 0
dist_right = 0
dist_center = 0
print("Pin def succes")
GPIO.setup(TRIGGER_LEFT,GPIO.OUT)
GPIO.setup(ECHO_LEFT,GPIO.IN)      

GPIO.setup(TRIGGER_RIGHT,GPIO.OUT)
GPIO.setup(ECHO_RIGHT,GPIO.IN)

GPIO.setup(TRIGGER_CENTER, GPIO.OUT)
GPIO.setup(ECHO_CENTER, GPIO.IN)

def getdist(trigger, echo):
    #Sending the 10microsecond pulse nedded
    GPIO.output(trigger, True)
    time.sleep(0.00001)
    GPIO.output(trigger, False)
    #When echo goes high the time starts
    while GPIO.input(echo)==0:
        pass
    start = time.time()
    #When echo goes low the time stops
    while GPIO.input(echo)==1:
        pass
    stop = time.time()

    #The time difference * speedofsound
    #Divided by two since the since the distance meassured is back and forth
    distance = ((stop-start) * 34000)/2

    return distance

print("Left: " + str(getdist(TRIGGER_LEFT, ECHO_LEFT)))
print("Right: " + str(getdist(TRIGGER_RIGHT, ECHO_RIGHT)))
print("Center: " + str(getdist(TRIGGER_CENTER, ECHO_CENTER)))

GPIO.cleanup()
