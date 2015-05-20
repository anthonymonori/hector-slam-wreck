int dirpin = 2;
int steppin = 3;

void setup()
{
    pinMode(dirpin, OUTPUT);
    pinMode(steppin, OUTPUT);
    digitalWrite(dirpin, LOW);
}
void loop()
{
    // This LOW to HIGH change is what creates the
    digitalWrite(steppin, LOW);
    // "Rising Edge" so the easydriver knows when to step.
    digitalWrite(steppin, HIGH);
    /*This delay time is close to top speed for this particular motor. Any faster, the particular motor stalls.*/
    delayMicroseconds(500);
    delay(10);
}
