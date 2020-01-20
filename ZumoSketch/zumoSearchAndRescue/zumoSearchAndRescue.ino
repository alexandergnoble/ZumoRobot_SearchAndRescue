#include <Zumo32U4.h>
#include <Wire.h>

// Zumo32U4ButtonA buttonA;
// Documentation for the motors class:
// http://pololu.github.io/zumo-32u4-arduino-library/class_zumo32_u4_motors.html
Zumo32U4Motors motors;
Zumo32U4LineSensors lineSensors;
Zumo32U4ProximitySensors proxSensors;

uint16_t lineSensorValues[5] = { 0, 0, 0, 0, 0 };

const uint16_t motorSpeed = 200;

void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);
  uint8_t lineSensorPins[] = { SENSOR_DOWN1, SENSOR_DOWN2, SENSOR_DOWN3, SENSOR_DOWN4, SENSOR_DOWN5 };
}

void loop() {


  while (Serial1.available()>0) {
    
    int direction = Serial1.read();
    Serial.print("Got message: ");
    Serial.println(direction);
    String name ="";

    switch (direction){
      case'w': case 'W':
      name = "Forward";
      motors.setSpeeds(motorSpeed, motorSpeed);
      delay(250);
      motors.setSpeeds(0, 0);
      break;
      
      case'a': case 'A':
      name = "Left";
      motors.setSpeeds(-motorSpeed, motorSpeed);
      delay(115);
      motors.setSpeeds(0, 0);
      break;
      
      case'd': case 'D':
      name = "Right";
      motors.setSpeeds(motorSpeed, -motorSpeed);
      delay(115);
      motors.setSpeeds(0, 0);
      break;
      
      case's': case 'S':
      name = "Backwards";
      motors.setSpeeds(-motorSpeed, -motorSpeed);
      delay(250);
      motors.setSpeeds(0, 0);
      break;

      case'z': case 'Z':
      name = "Stop";
      motors.setSpeeds(0, 0);
      break;
    }
 }
}
