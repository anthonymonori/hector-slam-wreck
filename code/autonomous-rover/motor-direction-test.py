#!/usr/bin/python
import time
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)
MOTOR_A1 = 5
MOTOR_A2 = 6
MOTOR_B1 = 13
MOTOR_B2 = 26

GPIO.setup(MOTOR_A1, GPIO.OUT)
GPIO.setup(MOTOR_A2, GPIO.OUT)
GPIO.setup(MOTOR_B1, GPIO.OUT)
GPIO.setup(MOTOR_B2, GPIO.OUT)

def forward():
    GPIO.output(MOTOR_A1, True)
    GPIO.output(MOTOR_A2, False)
    GPIO.output(MOTOR_B1, True)
    GPIO.output(MOTOR_B2, False)
    print("Forward.")
    return


def left():
    GPIO.output(MOTOR_A1, False)
    GPIO.output(MOTOR_A2, True)
    GPIO.output(MOTOR_B1, True)
    GPIO.output(MOTOR_B2, False)
    print("Turning left.")
    return

def right():
    GPIO.output(MOTOR_A1, True)
    GPIO.output(MOTOR_A2, False)
    GPIO.output(MOTOR_B1, False)
    GPIO.output(MOTOR_B2, True)
    print("Turning right.")
    return

def stop():
    GPIO.output(MOTOR_A1, False)
    GPIO.output(MOTOR_A2, False)
    GPIO.output(MOTOR_B1, False)
    GPIO.output(MOTOR_B2, False)
    print("Stopping.")
    return

def reverse():
    GPIO.output(MOTOR_A1, False)
    GPIO.output(MOTOR_A2, True)
    GPIO.output(MOTOR_B1, False)
    GPIO.output(MOTOR_B2, True)
    print("Reversing")    
    return
try:
    print("Starting motor test in 3 seconds..")
    time.sleep(3)
    forward()
    time.sleep(3)
    left()
    time.sleep(3)
    right()
    time.sleep(3)
    reverse()
    time.sleep(3)
    stop()
    time.sleep(3)
    print("Test script completed")
except KeyboardInterrupt:
    pass

GPIO.cleanup()
