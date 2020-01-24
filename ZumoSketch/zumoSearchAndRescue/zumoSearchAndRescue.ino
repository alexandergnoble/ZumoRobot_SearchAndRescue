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
  lineSensors.initThreeSensors();
}

void loop() {


  while (Serial1.available()>0) {
    
    int direction = Serial1.read();
    Serial1.print("Got message: ");
    Serial1.println(direction);
    String name ="";

    switch (direction){
      case'w': case 'W':{
      name = "Forward";
      motors.setSpeeds(100, 100);
      delay(200);
      motors.setSpeeds(0, 0);
      return;
    }
      
      case'a': case 'A': {
      name = "Left";
      motors.setSpeeds(-150, 150);
      delay(100);
      motors.setSpeeds(0, 0);
      return;
      }
      
      case'd': case 'D': {
      name = "Right";
      motors.setSpeeds(150, -150);
      delay(100);
      motors.setSpeeds(0, 0);
      return;
      }
      
      case's': case 'S': {
      name = "Backwards";
      motors.setSpeeds(-100, -100);
      delay(200);
      motors.setSpeeds(0, 0);
      return;
      }

      case'z': case 'Z': {
      name = "Stop";
      motors.setSpeeds(0, 0);
      return;
      }

      case 'c': case 'C': {
      name= "Auto forward";
      autoForward();
      break;
      }

    }
 }
}
void manualTurn()
{
  String name ="";
  Serial1.print("Press C to resume!");
  
  while (Serial1.available()==0);
    
      int direction = Serial1.read();
    
      switch (direction){
              
      case'a': case 'A': {
      name = "Left";
      motors.setSpeeds(-200, 200);
      delay(330);
      motors.setSpeeds(0, 0);
      break;
      }
      
      case'd': case 'D': {
      name = "Right";
      motors.setSpeeds(200, -200);
      delay(330);
      motors.setSpeeds(0, 0);
      break;
      }
      
      case's': case 'S': {
      name = "180";
      motors.setSpeeds(200, -200);
      delay(660);
      motors.setSpeeds(0, 0);
      break;
      }

      case'c': case 'C': {
      name = "Resume";
      Serial1.print("Resuming!");
      return;
      }

      case'z': case 'Z': {
      name = "Exit";
      Serial1.print("Exiting!");
      return;
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
        motors.setSpeeds(40,40);
        delay(200);
        lineSensors.read(lineSensorValues);
        if (lineSensorValues[NUM_SENSORS - 1] > QTR_THRESHOLD && lineSensorValues[0] > QTR_THRESHOLD)
        {
          motors.setSpeeds(-30,-30);
          delay(220);
          motors.setSpeeds(0,0);
          manualTurn();
        }
        else
        {
        motors.setSpeeds(-MOTOR_SPEED, -MOTOR_SPEED);
        delay(200);
        motors.setSpeeds(MOTOR_SPEED, -MOTOR_SPEED);
        delay(80);
        motors.setSpeeds(MOTOR_SPEED, MOTOR_SPEED);
        }
      }
      else if (lineSensorValues[NUM_SENSORS - 1] > QTR_THRESHOLD)
      {
        motors.setSpeeds(40,40);
        delay(200);
        lineSensors.read(lineSensorValues);
        if (lineSensorValues[0] > QTR_THRESHOLD && lineSensorValues[NUM_SENSORS - 1] > QTR_THRESHOLD)
        {
          motors.setSpeeds(-30,-30);
          delay(220);
          motors.setSpeeds(0,0);
          manualTurn();
        }
        else
        {
        // If rightmost sensor detects line, reverse and turn to the
        // left.
        motors.setSpeeds(-MOTOR_SPEED, -MOTOR_SPEED);
        delay(200);
        motors.setSpeeds(-MOTOR_SPEED, MOTOR_SPEED);
        delay(80);
        motors.setSpeeds(MOTOR_SPEED, MOTOR_SPEED);
        }
      }
      else
      {
        // Otherwise, go straight.
        motors.setSpeeds(50, 50);
      }

  }
}
