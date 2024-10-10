/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       graysonbou                                                */
/*    Created:      10/7/2024, 1:09:58 PM                                     */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

#include "vex.h"

using namespace vex;

// A global instance of competition
competition Competition;
brain Brain;
motor leftdrive1(PORT7, ratio6_1, false);
motor leftdrive2(PORT9, ratio6_1, true);
motor leftdrive3(PORT8, ratio6_1, false);
motor rightdrive1(PORT2, ratio6_1, true);
motor rightdrive2(PORT12, ratio6_1, false);
motor rightdrive3(PORT13, ratio6_1, true);
motor intake(PORT16, ratio6_1, false);
controller Controller(primary);
motor_group rightdrive(rightdrive1,rightdrive2,rightdrive3);
motor_group leftdrive(leftdrive1,leftdrive2,leftdrive3);
pneumatic Rod(Brain.ThreeWirePort.H);
// define your global instances of motors and other devices here

/*---------------------------------------------------------------------------*/
/*                          Pre-Autonomous Functions                         */
/*                                                                           */
/*  You may want to perform some actions before the competition starts.      */
/*  Do them in the following function.  You must return from this function   */
/*  or the autonomous and usercontrol tasks will not be started.  This       */
/*  function is only called once after the V5 has been powered on and        */
/*  not every time that the robot is disabled.                               */
/*---------------------------------------------------------------------------*/

void pre_auton(void) {

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
    while (1) {
    rightdrive.setVelocity(Controller.Axis2.position(), pct);
    leftdrive.setVelocity(Controller.Axis3.position(), pct);
    rightdrive.spin(forward);
    leftdrive.spin(forward);
    if (Controller.ButtonL1.pressing()) {
    intake.spin(forward);
    }else if (Controller.ButtonL2.pressing()) {
    intake.spin(reverse);
    } else {intake.stop();}
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

//
// Main will set up the competition functions and callbacks.
//
int main() {
  Controller.ButtonR1.pressed([]() {
   Rod.set(!Rod);
  });
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Run the pre-autonomous function.
  pre_auton();

  // Prevent main from exiting with an infinite loop.
  while (true) {
    wait(100, msec);
  }
}
