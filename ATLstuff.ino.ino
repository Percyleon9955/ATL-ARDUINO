#include <NewPing.h>

#define TRIGGER_PIN  12  // pin for the trigger signal of the ultrasonic sensor
#define ECHO_PIN     11  // pin for the echo signal of the ultrasonic sensor
#define MAX_DISTANCE 200  // maximum distance in centimeters that the ultrasonic sensor can detect

#define LEFT_MOTOR_FORWARD  3  // pin for controlling the direction of the left motor
#define LEFT_MOTOR_BACKWARD 4  // pin for controlling the direction of the left motor
#define RIGHT_MOTOR_FORWARD 5  // pin for controlling the direction of the right motor
#define RIGHT_MOTOR_BACKWARD 6  // pin for controlling the direction of the right motor

#define MIN_DISTANCE 30  // minimum distance in centimeters to consider an obstacle
#define TURN_DISTANCE 10  // distance in centimeters to turn the car

NewPing sonar(TRIGGER_PIN, ECHO_PIN, MAX_DISTANCE);  // create a NewPing object for the ultrasonic sensor

void setup() {
  pinMode(LEFT_MOTOR_FORWARD, OUTPUT);
  pinMode(LEFT_MOTOR_BACKWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_FORWARD, OUTPUT);
  pinMode(RIGHT_MOTOR_BACKWARD, OUTPUT);
}

void loop() {
  int distance = sonar.ping_cm();  // get the distance to the closest obstacle

  if (distance < MIN_DISTANCE) {  // if an obstacle is detected
    digitalWrite(LEFT_MOTOR_FORWARD, LOW);  // stop the left motor
    digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
    digitalWrite(RIGHT_MOTOR_FORWARD, LOW);  // stop the right motor
    digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);

    delay(TURN_DISTANCE * 50);  // wait for the car to turn

    // drive the car in reverse for a short distance
    digitalWrite(LEFT_MOTOR_FORWARD, LOW);
    digitalWrite(LEFT_MOTOR_BACKWARD, HIGH);
    digitalWrite(RIGHT_MOTOR_FORWARD, LOW);
    digitalWrite(RIGHT_MOTOR_BACKWARD, HIGH);

    delay(TURN_DISTANCE * 50);  // wait for the car to reverse

    // turn the car to the left
    digitalWrite(LEFT_MOTOR_FORWARD, LOW);
    digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
    digitalWrite(RIGHT_MOTOR_FORWARD, HIGH);
    digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);

    delay(TURN_DISTANCE * 50);  // wait for the car to turn

    // drive the car forward again
    digitalWrite(LEFT_MOTOR_FORWARD, HIGH);
    digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
    digitalWrite(RIGHT_MOTOR_FORWARD, HIGH);
    digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
} else { // if no obstacle is detected
// drive the car forward
digitalWrite(LEFT_MOTOR_FORWARD, HIGH);
digitalWrite(LEFT_MOTOR_BACKWARD, LOW);
digitalWrite(RIGHT_MOTOR_FORWARD, HIGH);
digitalWrite(RIGHT_MOTOR_BACKWARD, LOW);
}
}
