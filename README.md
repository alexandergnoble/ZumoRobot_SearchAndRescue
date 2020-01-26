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
