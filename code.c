/* 
 * Created by 
 * Created on April 2025
 * This program turns servo when an object gets closer than 50 cm away from the sonar
*/

# include <Servo.h>

// setting constants for sonar sensor
const int TRIG_PIN = 9;  
const int ECHO_PIN = 10;
const int PIN_4 = 4;
const int SPEED = 9600;
const float INCH_TO_CM = 0.0343;

// variables
int servoAngle = 0;
int sleepTime = 100;
float duration, distance;

Servo myServo;

void setup() {
    // defining sonar sensor and servo pins
    pinMode(TRIG_PIN, OUTPUT);
    pinMode(ECHO_PIN, INPUT);
    Serial.begin(SPEED);
    myServo.attach(PIN_4);
    myServo.write(servoAngle);
}

void loop() {
    sleepTime = 100;
    myServo.write(servoAngle); // Setting servo to 0 degrees
    digitalWrite(TRIG_PIN, LOW);
	delay(sleepTime);
    digitalWrite(TRIG_PIN, HIGH);
	delay(sleepTime);
    digitalWrite(TRIG_PIN, LOW);
    duration = pulseIn(ECHO_PIN, HIGH);
    distance = (duration * INCH_TO_CM)/2; // convert distance in inches to cm
    Serial.print("Distance: ");
    Serial.println(distance);
    delay(sleepTime);
 
  if (distance < 50) {
    // Turning servo 90 from 0 degrees if distance is less than 50cm
    sleepTime = 500;
    servoAngle = 0;
    myServo.write(servoAngle);
    delay(sleepTime);
    servoAngle = 90;
    myServo.write(servoAngle);
    delay(sleepTime);
  }
}
