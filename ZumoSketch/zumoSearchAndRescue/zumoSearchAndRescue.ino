#include <Wire.h>
#include <Zumo32U4.h>

// Zumo32U4ButtonA buttonA;
// Documentation for the motors class:
// http://pololu.github.io/zumo-32u4-arduino-library/class_zumo32_u4_motors.html
Zumo32U4Motors motors;
Zumo32U4LineSensors lineSensors;

#define LED 13
#define QTR_THRESHOLD  700
#define NUM_SENSORS 3

#define MOTOR_SPEED 100
bool onOff = true;
unsigned int lineSensorValues[NUM_SENSORS];

void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);
  lineSensors.initThreeSensors();
}

void loop() {


  while (Serial1.available()>0) {
    
    int direction = Serial1.read();
    Serial.print("Got message: ");
    Serial.println(direction);
    String name ="";

    switch (direction){
      case'w': case 'W':{
      name = "Forward";
      motors.setSpeeds(MOTOR_SPEED, MOTOR_SPEED);
      delay(250);
      motors.setSpeeds(0, 0);
      break;
    }
      
      case'a': case 'A': {
      name = "Left";
      motors.setSpeeds(-MOTOR_SPEED, MOTOR_SPEED);
      delay(115);
      motors.setSpeeds(0, 0);
      break;
      }
      
      case'd': case 'D': {
      name = "Right";
      motors.setSpeeds(MOTOR_SPEED, -MOTOR_SPEED);
      delay(115);
      motors.setSpeeds(0, 0);
      break;
      }
      
      case's': case 'S': {
      name = "Backwards";
      motors.setSpeeds(-MOTOR_SPEED, -MOTOR_SPEED);
      delay(250);
      motors.setSpeeds(0, 0);
      break;
      }

      case'z': case 'Z': {
      name = "Stop";
      motors.setSpeeds(0, 0);
      break;
      }

      case 'c': case 'C': {
      name= "Auto forward";
      autoForward();
      }

    }
 }
}

void autoForward()
{
  int i = 6;

  while (i = 6){
    
  lineSensors.read(lineSensorValues);

      if (lineSensorValues[0] > QTR_THRESHOLD)
      {
        // If leftmost sensor detects line, reverse and turn to the
        // right.
        motors.setSpeeds(-MOTOR_SPEED, -MOTOR_SPEED);
        delay(200);
        motors.setSpeeds(MOTOR_SPEED, -MOTOR_SPEED);
        delay(300);
        motors.setSpeeds(MOTOR_SPEED, MOTOR_SPEED);
      }
      else if (lineSensorValues[NUM_SENSORS - 1] > QTR_THRESHOLD)
      {
        // If rightmost sensor detects line, reverse and turn to the
        // left.
        motors.setSpeeds(-MOTOR_SPEED, -MOTOR_SPEED);
        delay(200);
        motors.setSpeeds(-MOTOR_SPEED, MOTOR_SPEED);
        delay(300);
        motors.setSpeeds(MOTOR_SPEED, MOTOR_SPEED);
      }
      else
      {
        // Otherwise, go straight.
        motors.setSpeeds(MOTOR_SPEED, MOTOR_SPEED);
      }
  }
}
