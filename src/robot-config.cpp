#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
motor LF = motor(PORT13, ratio6_1, true);
motor LM = motor(PORT17, ratio6_1, true);
motor RF = motor(PORT14, ratio6_1, false);
motor RM = motor(PORT18, ratio6_1, false);
motor LB = motor(PORT19, ratio6_1, true);
motor RB = motor(PORT11, ratio6_1, false);
motor Intake = motor(PORT12, ratio6_1, true);
motor Lift = motor(PORT10, ratio6_1, true);

//Motor Groups
motor_group Roller = motor_group(Intake);
motor_group wallstakes = motor_group(Lift);
//Pistons
digital_out OPMECH = digital_out(Brain.ThreeWirePort.B);
digital_out Tilt = digital_out(Brain.ThreeWirePort.D);
digital_out Clamp = digital_out(Brain.ThreeWirePort.A);

digital_out Pistake =digital_out(Brain.ThreeWirePort.C);
//Gyro and stuff for PID
inertial Gyro = inertial(PORT20);
//Naming convention: 
// Important variables
const double wheelDiam = 2.75;
const double wheelToMotorRatio = 48.0/36;

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}