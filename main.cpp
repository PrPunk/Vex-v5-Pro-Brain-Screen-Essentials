/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       Josiah Schatz and Sherwin Sagadam                         */
/*    Created:      Sat 23 Aug 2025                                           */
/*    Description:  Example brain screen code                                 */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"
#include "brain-display.cpp"
using namespace vex;
BrainDisplay brainDisplay; 

// A global instance of competition
competition Competition;

int autonMode = 0;

void pre_auton(void) {
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  
  // All activities that occur before the competition starts
  // Example: clearing encoders, setting servo positions, ...
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              Autonomous Task                              */
/*                                                                           */
/*  This task is used to control your robot during the autonomous phase of   */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void autonomous(void) {
  // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
}

/*---------------------------------------------------------------------------*/
/*                                                                           */
/*                              User Control Task                            */
/*                                                                           */
/*  This task is used to control your robot during the user control phase of */
/*  a VEX Competition.                                                       */
/*                                                                           */
/*  You must modify the code to add your own robot specific commands here.   */
/*---------------------------------------------------------------------------*/

void usercontrol(void) {
  // User control code here, inside the loop
  while (1) {

    // driver control code:
    
    ;
    
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.

    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

void setAuton(int autonNumber) {
  // Set autonomous mode.
  autonMode = autonNumber;
  CT1.rumble("-.-.-");
}

void goToPage(int pageId) {
  brainDisplay.switchPage(pageId);
}


void drawOnScreen() {
  //Place code here

  Button newButton;
  newButton.x = 350;
  newButton.y = 200;
  newButton.width = 140;
  newButton.height = 60;
  newButton.callback = goToPage;
  newButton.param = 0;
  char newText[20] = "Return";
  strcpy(newButton.text, newText);
  newButton.color = 0xff0000;
  brainDisplay.createButton(2,0, newButton);
  brainDisplay.addImage(2);

  Button newButton2;
  newButton2.x = 40;
  newButton2.y = 60;
  newButton2.width = 140;
  newButton2.height = 60;
  newButton2.callback = setAuton;
  newButton2.param = 3;
  char newText2[20] = "Skills Auton";
  strcpy(newButton2.text, newText2);
  newButton2.color = 0x04cc33;
  brainDisplay.createButton(1,0, newButton2);

  Button newButton3;
  newButton3.x = 40;
  newButton3.y = 160;
  newButton3.width = 140;
  newButton3.height = 60;
  newButton3.callback = goToPage;
  newButton3.param = 0;
  char newText3[20] = "Return";
  strcpy(newButton3.text, newText3);
  newButton3.color = 0xff0000;
  brainDisplay.createButton(1,1, newButton3);

  Button newButton4;
  newButton4.x = 300;
  newButton4.y = 60;
  newButton4.width = 140;
  newButton4.height = 60;
  newButton4.callback = setAuton;
  newButton4.param = 1;
  char newText4[20] = "Left Side";
  strcpy(newButton4.text, newText4);
  newButton4.color = 0x02749e;
  brainDisplay.createButton(1,2, newButton4);

  Button newButton5;
  newButton5.x = 300;
  newButton5.y = 160;
  newButton5.width = 140;
  newButton5.height = 60;
  newButton5.callback = setAuton;
  newButton5.param = 2;
  char newText5[20] = "Right Side";
  strcpy(newButton5.text, newText5);
  newButton5.color = 0x02749e;
  brainDisplay.createButton(1,3, newButton5);

  Button newButton6;
  newButton6.x = 180;
  newButton6.y = 160;
  newButton6.width = 140;
  newButton6.height = 60;
  newButton6.callback = goToPage;
  newButton6.param = 1;
  char newText6[20] = "Auton";
  strcpy(newButton6.text, newText6);
  newButton6.color = 0x02749e;
  brainDisplay.createButton(0,0, newButton6);
  brainDisplay.switchPage(0);

  Button newButton7;
  newButton7.x = 180;
  newButton7.y = 60;
  newButton7.width = 140;
  newButton7.height = 60;
  newButton7.callback = goToPage;
  newButton7.param = 2;
  char newText7[20] = "Image";
  strcpy(newButton7.text, newText7);
  newButton7.color = 0xff0000;
  brainDisplay.createButton(0,1, newB

}

//
// Main will set up the competition functions and callbacks.
//

void screenCallback() {
  brainDisplay.screenPressed();
}

int main() {
  // Set up callbacks for autonomous and driver control periods.
  Brain.Screen.pressed(screenCallback);
  // brain screen code
  drawOnScreen();

  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}