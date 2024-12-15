#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void mogo(){
    //blue side
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize

    Clamp.set(true);
    MoveEncoderPID(TestPara, -100, 15, 0.3, 0, true);
    MoveEncoderPID(TestPara, -40, 25, 0.3, 0, true);
    Clamp.set(false);
    wait(200 , msec);
    TurnMaxTimePID(TestPara, -60,  0.3, true);
    wait(50, msec);
    RunRoller(100);
    MoveEncoderPID(TestPara, 45, 23, 0.3, -60, true);
    wait(100, msec);
    TurnMaxTimePID(TestPara, -140, 0.3, true);
    MoveEncoderPID(TestPara, 40, 15, 0.3, -140, true); //3rd ring
    MoveEncoderPID(TestPara, -100, 5, 0.3, -140, true);
    TurnMaxTimePID(TestPara, -115, 0.3, true);
    MoveEncoderPID(TestPara, 28, 22, 0.3, -115, true); //last ring 
    MoveEncoderPID(TestPara, -100, 20, 0.3, -115, true);
    TurnMaxTimePID(TestPara, -175, 0.3, true);
    MoveEncoderPID(TestPara, 90, 25, 0.3, -175, true); // touch ladder
}