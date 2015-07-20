#!/usr/bin/python
import time
import RPi.GPIO as GPIO

GPIO.setmode(GPIO.BCM)

#Setting the motor signal pins
LEFT_W = 4
RIGHT_W = 17

#Duty cycles required for forward, reverse, stopping
fwd = 94.69
rws = 56.81
halt = 75.75

#initializing the pins
GPIO.setup(LEFT_W, GPIO.OUT)
GPIO.setup(RIGHT_W, GPIO.OUT)
#Setting the PWM freq. to 50
left_pwm = GPIO.PWM(LEFT_W, 50)
right_pwm = GPIO.PWM(RIGHT_W, 50)
#Starting the PWM
left_pwm.start(0)
right_pwm.start(0)

try:
    while True:
        left_pwm.ChangeDutyCycle(fwd)
        right_pwm.ChangeDutyCycle(fwd)
        print("Forward")
        time.sleep(5)
        left_pwm.ChangeDutyCycle(halt)
        right_pwm.ChangeDutyCycle(halt)
        print("Halt")
        time.sleep(5)
        left_pwm.ChangeDutyCycle(rws)
        right_pwm.ChangeDutyCycle(rws)
        print("Reverse")
        time.sleep(5)
        
except KeyboardInterrupt:
    pass

left_pwm.stop()
right_pwm.stop()

GPIO.cleanup()
