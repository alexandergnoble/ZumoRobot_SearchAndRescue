#include <Zumo32U4.h>

// Zumo32U4ButtonA buttonA;
// Documentation for the motors class:
// http://pololu.github.io/zumo-32u4-arduino-library/class_zumo32_u4_motors.html
Zumo32U4Motors motors;

const uint16_t motorSpeed = 200;

void setup() {
  Serial1.begin(9600);
  Serial.begin(9600);
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
