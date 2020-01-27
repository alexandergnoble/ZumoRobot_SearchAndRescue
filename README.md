# Pololu Zumo Robot - Search and Rescue
Programming "Things" - SHU University Assignment - Coursework 1

This assignment involved scripting a Pololozu Zumo 32u4 Robot to perform a search and rescue mission on a given 'maze'. The search and rescue mission involves the Zumo traversing the 'maze' both manually and automatically whilst also being commanded to 'scan' rooms for possible people inside.

The scenario motivating this assignment is that your robot is trying to find/rescue people trapped on a single floor in a building which is filled with smoke. The robot moves through a corridor and people are to be discovered in rooms or in the corridor. When the robot discovers a 'person' it signals back to ‘base’ so that a search party can come in to rescue that person. The robot, however, continues to search, signalling as and when it finds people in other rooms. When the robot reaches the (final) end of the corridor, it turns around and returns to base (by the quickest route possible, but visiting all the locations where it has found people to confirm they have been rescued).

In order to achieve the rescue mission, different aspects from the Zumo will need to be used, these are; the line sensors for keeping within the corridors and rooms, the motors so the Zumo can move back, forth and turn, the proximity sensors to detect if people are inside of the rooms & the XBEE adapter for wireless communication between the Zumo and PC.

The 'building floor' will consist of a corridor with corners and adjoining rooms. The borders will be set out with black lines on a white background.  As an illustration, one possible configuration of rooms and corridor is given below…

<p align="center">
<img src="https://i.imgur.com/NxDuadH.png" 
alt="Building layout" width="704" height="366" border="10" />
</p>

## GUI Overview - C# & WPF

<p align="center">
<img src="https://i.imgur.com/4PYPHZV.png" 
alt="Building layout" width="704" height="366" border="10" />
</p>

The GUI, written in C# and WPF, allows for control over the robot. Each section of the GUI outputs to the serial port "COM5" where the XBEE device is connected to. PLEASE ADJUST THIS ACCORDINGLY IF YOU'RE WANTING TO CONNECT USING THE XBEE ADAPTER.

| GUI Component          | Behaviour                                                                                                                                               |
|---------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------|
| Zumo Output             | Any messages sent from the robot are outputted here (for example, directions of travel, people found in a room etc.                                                                                  |
| Object Detector             | This button executes the object detection function.                                                                          |
| Auto Corridor Scaler              | This button executes the automatic corridor scaler function.                                                                          |
| Manual Corridor Scaler           | This button toggles the manual corridor scaler function.                                                                    |
| Type Controls            | This is a text box where the user can input commands for the Zumo robot. The type controls consist of; W - Forward, A - Left, S - Reverse, D - Right, L - 90° Left, R - 90° Right, B - 180° Turn, C - Manual Corridor, X - Auto Corridor, Z - Room Search                                                                                  |
| WASD Controls              | These buttons replicate typing the WASD movements in the form of clickable buttons. W - Forward, A - Left, S - Reverse, D - Right, L - 90° Left, R - 90° Right, B - 180°.                                                                                                                                   |

## Function Overview
In order to traverse the corridors and perform the rescue mission, the robot has been programmed with several different functions which can each be triggered from the GUI. These are;

| Function          | Behaviour                                                                                                                                               |
|---------------------------|---------------------------------------------------------------------------------------------------------------------------------------------------------|
| Manual movement           | The robot can be controlled manually through WASD controls on the GUI. This allows for free traversal of the robot without any automatic line detection etc.                                                                      |    
| Manual Corridor Scaler           | The robot will begin to move up the corridor automatically using line detectors to keep it within the boundaries. At the end of the corridor, the robot will stop and prompt the user through the Zumo Output to make a manual turn of the robot. After completing this turn, the user can input 'C' into the 'TYPE CONTROLS' component to resume the function.                                                                      |                 
| Auto Corridor Scaler              | The robot will begin to move up the corridor automatically using line detectors to keep it within the boundaries. At the end of the corridor, the robot will stop and prompt the user for a command through the 'Zumo Ouput'. Using the 'TYPE CONTROLS' component, the user can enter 'L' for a left 90 degree turn, 'R' for a right 90 degree turn, or 'B' for a 180 degree turn. The robot will then make the respective turn and continue on down the corridor.                                                                          |
| Object Detection              | This function will scan a room, either to the left or the right of the corridor, for objects/people that are in there. If an object/person is found, the robot will turn to it, buzz, and record the entry in the Zumo Output. The user needs to indicate whether the room is to the left or the right using the 'TYPE CONTROLS' component and typing either L or R depending on which side the room is needing to be searched. The robot will turn, move forward into the room, scan for objects/people, indicate to the user using the 'Zumo Output' if something was in there, and then quit out the function.                                     

## Achievements & Key Issues
Achievements;

The tasks as listed in the [report] (https://github.com/alexandernoble/ZumoRobot_SearchAndRescue/blob/master/Assignment%20Brief.pdf) have been achieved on a maze scenario at home;

## Acknowledgements & Sources

The .ino script utilises libraries and sections of example scripts provided by Pololu. Libraries used include; <wire.h> & <Zumo32U4.h>. Example scripts include; Zumo32U4 > BorderDetect, Zumo32U4 > LineAndProximitySensors, Zumo32U4 > SumoColission. https://www.pololu.com/
