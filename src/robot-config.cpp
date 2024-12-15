#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
controller Controller1 = controller(primary);
//left side drive
motor LF = motor(PORT12, ratio6_1, true);
motor LM = motor(PORT16, ratio6_1, true);
motor LB = motor(PORT14, ratio6_1, true);

// right side drive
motor RF = motor(PORT13, ratio6_1, false);
motor RM = motor(PORT17, ratio6_1, false);
motor RB = motor(PORT18, ratio6_1, false);

// intake
motor In1 = motor(PORT21, ratio6_1, true);
motor In2 = motor(PORT21, ratio6_1, false);

//Things for Lift
motor Lt1= motor(PORT20, ratio36_1, true);
motor Lt2= motor(PORT20, ratio36_1, false);

//sensors
rotation liftSensor = rotation(PORT1);
optical OpSens = optical(PORT4);

//define lift to brake when stopped

//Motor Groups
motor_group Roller = motor_group(In1,In2);
motor_group lift = motor_group(Lt1, Lt2);

//Pistons
digital_out Pistake = digital_out(Brain.ThreeWirePort.G);
//digital_out Tilt = digital_out(Brain.ThreeWirePort.B);
digital_out Clamp = digital_out(Brain.ThreeWirePort.F);
digital_out OPMECH =digital_out(Brain.ThreeWirePort.H);
digital_out doinker = digital_out(Brain.ThreeWirePort.B);
//Gyro and stuff for PID
inertial Gyro = inertial(PORT2);
//Naming convention: 
// Important variables
const double wheelDiam = 3.25;
double wheelToMotorRatio = 48/36;

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