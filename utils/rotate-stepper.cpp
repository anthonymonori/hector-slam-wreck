//////////////////////////////////////////////////////////////////
//©2011 bildr
//Released under the MIT License - Please reuse change and share
//Using the easy stepper with your arduino
//use rotate and/or rotateDeg to controll stepper motor
//speed is any number from .01 -> 1 with 1 being fastest -
//Slower Speed == Stronger movement
/////////////////////////////////////////////////////////////////


#define DIR_PIN 2
#define STEP_PIN 3

void setup() {
    pinMode(DIR_PIN, OUTPUT);
    pinMode(STEP_PIN, OUTPUT);
}

void loop(){
    rotate(1600, 300); //reverse
}

void rotate(int steps, int usDelay){
    //rotate a specific number of microsteps (8 microsteps per step) - (negitive for reverse movement)
    //speed is any number from .01 -> 1 with 1 being fastest - Slower is stronger
    int dir = (steps > 0)? HIGH:LOW;
    steps = abs(steps);

    digitalWrite(DIR_PIN,dir);

    for(int i=0; i < steps; i++){
        digitalWrite(STEP_PIN, HIGH);
        digitalWrite(STEP_PIN, LOW);
        delayMicroseconds(2*usDelay);
    }
}
