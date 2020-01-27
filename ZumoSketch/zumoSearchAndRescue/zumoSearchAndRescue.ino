#include <Wire.h>
#include <Zumo32U4.h>

Zumo32U4Motors motors;
Zumo32U4LineSensors lineSensors;
Zumo32U4ProximitySensors proxSensors;
Zumo32U4Buzzer buzzer;

#define QTR_THRESHOLD  700 /* Line detection threshold, edit to change the sensitivity */
#define NUM_SENSORS 3      /* Defining the number of front sensors we require, with 0 being the left most, 1 being the center and 2 being the right most */
#define MOTOR_SPEED 100    /* Defining a set speed for a variable - used for the motors */
#define LEFT 0
#define RIGHT 1

unsigned int lineSensorValues[NUM_SENSORS]; /* Defining an array of 3 for our line sensor values */
const uint8_t sensorThreshold = 1; /* The sensors reading must be greater than or equal to this threshold to consider it an object */
bool senseDir = RIGHT; /* Using the definitions from above, we set senseDir to 1 effectively */
bool turningLeft = false; /* Boolean for task 5, check if it is turning left last */
bool turningRight = false; /* Boolean for task 5, check if it is turning right last */
const uint16_t deceleration = 50; /* Integer to use to decelerate the bot when turning in task 5 */
const uint16_t acceleration = 50; /* Integer to use to accelerate the bot when turning in task 5 */
uint16_t turnSpeed = 110; /* Defining a integer for task 5's turning */

void setup() { /* Run everytime at the beginning of the robots power on */
  Serial1.begin(9600); /* Begin a serial connection using the XBEE attached to the robot */
  lineSensors.initThreeSensors(); /* Initiating the three line sensors on the robot */
  proxSensors.initFrontSensor(); /* Initiating the front proximity sensors on the robot */
}

void loop() {


  while (Serial1.available()>0) {
    
    int direction = Serial1.read(); /* Read the serials input (from the GUI) and assign it to the integer direction */
    String name ="";

    switch (direction){ /* Creating a switch case from reading the GUI inputs */
      case'w': case 'W':{ /* If W is entered from the GUI/Serial, go forward */
      name = "Forward";
      motors.setSpeeds(100, 100);
      delay(200);
      motors.setSpeeds(0, 0);
      return;
    }
      
      case'a': case 'A': { /* If A is entered from the GUI/Serial, turn left */
      name = "Left";
      motors.setSpeeds(-150, 150);
      delay(100);
      motors.setSpeeds(0, 0);
      return;
      }
      
      case'd': case 'D': { /* If D is entered from the GUI/Serial, go right */
      name = "Right";
      motors.setSpeeds(150, -150);
      delay(100);
      motors.setSpeeds(0, 0);
      return;
      }
      
      case's': case 'S': { /* If S is entered from the GUI/Serial, go backwards */
      name = "Backwards";
      motors.setSpeeds(-100, -100);
      delay(200);
      motors.setSpeeds(0, 0);
      return;
      }

      case'z': case 'Z': { /* If Z is entered from the GUI/Serial, trigger the object detection function */
      name = "Object Detector";
      roomDirection();
      return;
      }

      case 'c': case 'C': { /* If C is entered from the GUI/Serial, trigger the manual corridor scaler function */
      name= "Manual Corridor Scaler";
      manualCorridor(); /* Calls the manual corridor scaler function from below */
      return;
      }

      case 'x': case 'X': { /* If C is entered from the GUI/Serial, trigger the automatic corridor scaler function */
      name= "Auto Corridor Scaler";
      autoCorridor();
      return;
      }

      case 'l': case 'L': { /* If L is entered from the GUI/Serial, turn left 90 degrees */
      name= "90 degree left";
      motors.setSpeeds(-200, 200);
      delay(330);
      motors.setSpeeds(0, 0);
      return;
      }

      case 'r': case 'R': { /* If R is entered from the GUI/Serial, turn right 90 degrees */
      name= "90 degree right";
      motors.setSpeeds(200, -200);
      delay(330);
      motors.setSpeeds(0, 0);
      return;
      }
      
      case 'b': case 'B': { /* If B is entered from the GUI/Serial, turn backwards 180 degrees */
      name= "180 degree turn";
      motors.setSpeeds(200, -200);
      delay(660);
      motors.setSpeeds(0, 0);
      return;
      }

    }
 }
}
void manualTurn() /* Function for task 3 */
{
  String name ="";
  Serial1.print("Please make a turn by using the A & D keys or buttons. Press C to resume once done."); /* Outputs to the GUI */
  
  while (Serial1.available()==0);
    
      int direction = Serial1.read(); /* Read the GUI/Serial inputs and assign it to integer direction */
    
      switch (direction){ /* Switch case from integer direction */
              
      case'a': case 'A': { /* If A is inputted from the GUI/Serial */
      name = "Left";
      motors.setSpeeds(-120, 120);
      delay(100);
      motors.setSpeeds(0, 0);
      }
      
      case'd': case 'D': { /* If D is inputted from the GUI/Serial */
      name = "Right";
      motors.setSpeeds(120, -120);
      delay(100);
      motors.setSpeeds(0, 0);
      }
      
      case'b': case 'B': { /* If B is inputted from the GUI/Serial */
      name = "180";
      motors.setSpeeds(200, -200); /* Speeds and delay set to a 180 degree turn angle */
      delay(660);
      motors.setSpeeds(0, 0);
      }
      case'c': case 'C': { /* If B is inputted from the GUI/Serial */
      name = "Resume";
      Serial1.print("Resuming!");
      break;
      }
      return;
      
   }
}
void autoTurn() /* Function for task 4 */
{
  String name ="";
  Serial1.print("At end of corridor - input L for left, R for right or B for backwards"); /* Outputs to the GUI */
  
  while (Serial1.available()==0);
    
      int direction = Serial1.read(); /* Read the GUI/Serial inputs and assign it to integer direction */
    
      switch (direction){ /* Switch case from integer direction */
              
      case'a': case 'A': { /* If A is inputted from the GUI/Serial */
      name = "Left";
      motors.setSpeeds(-200, 200); /* Speeds and delay set to a 90 degree turn angle */
      delay(330);
      motors.setSpeeds(0, 0);
      break;
      }
      
      case'd': case 'D': { /* If D is inputted from the GUI/Serial */
      name = "Right";
      motors.setSpeeds(200, -200); /* Speeds and delay set to a 90 degree turn angle */
      delay(330);
      motors.setSpeeds(0, 0);
      break;
      }
      
      case'b': case 'B': { /* If B is inputted from the GUI/Serial */
      name = "180";
      motors.setSpeeds(200, -200); /* Speeds and delay set to a 180 degree turn angle */
      delay(660);
      motors.setSpeeds(0, 0);
      break;
      }
      return;
      
   }
}
void manualCorridor() /* Function for task 3 */
{
  int i = 6;

  while (i = 6){ /* Creates a loop whilst i == 6 */
    
      lineSensors.read(lineSensorValues); /* Read the current line sensor values and assign it to our array lineSensorValues  */

      if (lineSensorValues[0] > QTR_THRESHOLD) /* If the line sensor value for the left sensor is higher than our threshold */
      {
        
        motors.setSpeeds(40,40); /* Goes forward ever so slightly */
        delay(200);
        lineSensors.read(lineSensorValues); /* Records the line sensor values again */
        
          if (lineSensorValues[NUM_SENSORS - 1] > QTR_THRESHOLD && lineSensorValues[0] > QTR_THRESHOLD) /* If both the left most sensor and the right most senser are above the threshold */
          {
            motors.setSpeeds(-30,-30); /* Reverse slightly and make a stop */
            delay(220);
            motors.setSpeeds(0,0);
            manualTurn(); /* Calls the manualTurn function from above for task 3 */
          }
            else /* If both line sensors are not over the threshold, and only the leftmost is */
            {
            motors.setSpeeds(-MOTOR_SPEED, -MOTOR_SPEED); /* Reverse ever so slightly, make a right hand turn and start going forward again */
            delay(200);
            motors.setSpeeds(MOTOR_SPEED, -MOTOR_SPEED);
            delay(80);
            motors.setSpeeds(MOTOR_SPEED, MOTOR_SPEED);
            }
      }
      
      else if (lineSensorValues[NUM_SENSORS - 1] > QTR_THRESHOLD) /* If the line sensor value for the slight right sensor is higher than our threshold */
      {
        motors.setSpeeds(40,40); /* Goes forward ever so slightly */
        delay(200);
        lineSensors.read(lineSensorValues); /* Records the line sensor values again */
          if (lineSensorValues[0] > QTR_THRESHOLD && lineSensorValues[NUM_SENSORS - 1] > QTR_THRESHOLD) /* If both the left most sensor and the right most senser are above the threshold */
          {
            motors.setSpeeds(-30,-30); /* Reverse slightly and make a stop */
            delay(220);
            motors.setSpeeds(0,0);
            manualTurn(); /* Calls the manualTurn function from above for task 3 */
          }
            else /* If both line sensors are not over the threshold, and only the leftmost is */
            {
            motors.setSpeeds(-MOTOR_SPEED, -MOTOR_SPEED); /* Reverse ever so slightly, make a  slight left hand turn and start going forward again */
            delay(200);
            motors.setSpeeds(-MOTOR_SPEED, MOTOR_SPEED);
            delay(80);
            motors.setSpeeds(MOTOR_SPEED, MOTOR_SPEED);
            }
      }
      
      else /* If neither linesensor is over the threshold */
      {
        motors.setSpeeds(50, 50); /* Keep going straight */
      }

  }
}

void autoCorridor() /* Function for task 4 */
{
  int i = 6;

  while (i = 6){ /* Creates a loop whilst i == 6 */
    
      lineSensors.read(lineSensorValues); /* Read the current line sensor values and assign it to our array lineSensorValues  */

      if (lineSensorValues[0] > QTR_THRESHOLD) /* If the line sensor value for the left sensor is higher than our threshold */
      {
        
        motors.setSpeeds(40,40); /* Goes forward ever so slightly */
        delay(200);
        lineSensors.read(lineSensorValues); /* Records the line sensor values again */
        
          if (lineSensorValues[NUM_SENSORS - 1] > QTR_THRESHOLD && lineSensorValues[0] > QTR_THRESHOLD) /* If both the left most sensor and the right most senser are above the threshold */
          {
            motors.setSpeeds(-30,-30); /* Reverse slightly and make a stop */
            delay(220);
            motors.setSpeeds(0,0);
            autoTurn(); /* Calls the automaticTurn function from above for task 3 */
          }
            else /* If both line sensors are not over the threshold, and only the leftmost is */
            {
            motors.setSpeeds(-MOTOR_SPEED, -MOTOR_SPEED); /* Reverse ever so slightly, make a right hand turn and start going forward again */
            delay(200);
            motors.setSpeeds(MOTOR_SPEED, -MOTOR_SPEED);
            delay(80);
            motors.setSpeeds(MOTOR_SPEED, MOTOR_SPEED);
            }
      }
      
      else if (lineSensorValues[NUM_SENSORS - 1] > QTR_THRESHOLD) /* If the line sensor value for the slight right sensor is higher than our threshold */
      {
        motors.setSpeeds(40,40); /* Goes forward ever so slightly */
        delay(200);
        lineSensors.read(lineSensorValues); /* Records the line sensor values again */
          if (lineSensorValues[0] > QTR_THRESHOLD && lineSensorValues[NUM_SENSORS - 1] > QTR_THRESHOLD) /* If both the left most sensor and the right most senser are above the threshold */
          {
            motors.setSpeeds(-30,-30); /* Reverse slightly and make a stop */
            delay(220);
            motors.setSpeeds(0,0);
            autoTurn(); /* Calls the automaticTurn function from above for task 3 */
          }
            else /* If both line sensors are not over the threshold, and only the leftmost is */
            {
            motors.setSpeeds(-MOTOR_SPEED, -MOTOR_SPEED); /* Reverse ever so slightly, make a  slight left hand turn and start going forward again */
            delay(200);
            motors.setSpeeds(-MOTOR_SPEED, MOTOR_SPEED);
            delay(80);
            motors.setSpeeds(MOTOR_SPEED, MOTOR_SPEED);
            }
      }
      
      else /* If neither linesensor is over the threshold */
      {
        motors.setSpeeds(50, 50); /* Keep going straight */
      }

  }
}
void roomDirection() /* Beginning funcion for task 5 */
{
  String name ="";
  Serial1.print("Is the room to the left or right? Press L or R to respond."); /* Outputs to the GUI */
  
  while (Serial1.available()==0);
    
      int direction = Serial1.read(); /* Read the GUI/Serial inputs and assign it to integer direction */
    
      switch (direction){ /* Switch case from integer direction */
              
      case'l': case 'L': { /* If L is inputted from the GUI/Serial */
      name = "Left";
      motors.setSpeeds(-200, 200); /* Speeds and delay set to a 90 degree turn angle, then go forward */
      delay(330);
      motors.setSpeeds(90, 90);
      delay(200);
      motors.setSpeeds(0, 0);
      objectScanner(); /* Go to objectScanner function */
      return;
      }
      
      case'r': case 'R': { /* If R is inputted from the GUI/Serial */
      name = "Right";
      motors.setSpeeds(200, -200); /* Speeds and delay set to a 90 degree turn angle, then go forward */
      delay(330);
      motors.setSpeeds(90, 90);
      delay(200);
      motors.setSpeeds(0, 0);
      objectScanner(); /* Go to objectScanner function */
      return;
      }
      return;
      
   }
}
void objectScanner() /* Second funcion for task 5 */
{
  int i = 6;

  while (i = 6){ /* Created a loop */

    proxSensors.read(); /* Read proximity sensor values */
    uint8_t leftValue = proxSensors.countsFrontWithLeftLeds(); /* Assign both the front left and right LED to leftValue and rightValue */
    uint8_t rightValue = proxSensors.countsFrontWithRightLeds();

    bool objectSeen = leftValue >= sensorThreshold || rightValue >= sensorThreshold;

    if (objectSeen) /* If object is visible, start decelerating in order to help the robot find the object without overturning */
    {
      turnSpeed -= deceleration; 
    }
    else /* Object is not visible,  accelerate in order to help find the object sooner. */
    {
      turnSpeed += acceleration;
    }

    if (objectSeen) /* If object is seen = true */
    {
      // An object seen.
      ledYellow(1);
  
      bool lastTurnRight = turnRight;
  
      if (leftValue < rightValue) /* Right value is greater, so the object is closer to the robot's right LEDs. Turn to the right to make it more even. */
      {
        turnRight();
        senseDir = RIGHT;
      }
        else if (leftValue > rightValue) /* Left value is greater, so turn to the left. */
        {
          turnLeft();
          senseDir = LEFT;
        }
          else /*Object is found so stop the motors and run an LED/Buzzer sequence */
          {
            
            motors.setSpeeds(0, 0);
            turningLeft = false;
            turningRight = false;
            Serial1.print("Object found in the room!");
            buzzer.playNote(NOTE_G(3), 200, 15);
            delay(300);
            ledRed(1);
            ledYellow(1);
            ledGreen(1);
            delay(300);
            ledRed(0);
            ledYellow(0);
            ledGreen(0);
            delay(300);
            ledRed(1);
            ledYellow(1);
            ledGreen(1);
            delay(300);
            ledRed(0);
            ledYellow(0);
            ledGreen(0);
            loop();           
          }
      }
          else /* No object is seen, keep turning in the direction that object was last sensed */
          {
            ledYellow(0);
        
            if (senseDir == RIGHT)
            {
              turnRight();
            }
            else
            {
              turnLeft();
            }
          }
      }
}

void turnRight() /* Turn right function for task 5 */
{
  motors.setSpeeds(turnSpeed, -turnSpeed);
  turningLeft = false;
  turningRight = true;
}

void turnLeft() /* Turn left function for task 5 */
{
  motors.setSpeeds(-turnSpeed, turnSpeed);
  turningLeft = true;
  turningRight = false;
}
