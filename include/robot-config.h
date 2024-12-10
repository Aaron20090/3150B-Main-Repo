using namespace vex;

extern brain Brain;

// VEXcode devices
extern controller Controller1;
extern motor LF;
extern motor LM;
extern motor RF;
extern motor RM;
extern motor LB;
extern motor RB;
extern motor_group Roller;
extern digital_out Tilt;
extern digital_out Clamp;
extern digital_out RightBackWing;
extern digital_out Pistake;
extern motor PU;
extern inertial Gyro;
extern digital_out LeftBackWing;
extern digital_out OPMECH;
extern motor_group lift;
extern const double wheelDiam;
extern double wheelToMotorRatio;
extern optical OpSens;
extern digital_out doinker;
extern rotation liftSensor;
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );