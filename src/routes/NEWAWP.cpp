#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out t calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

void Red1Mogo6Ring() {
    PIDDataSet TestPara={1.5,0.1,0.15}; //initialize
    lift.resetPosition();
    MoveEncoderPID(TestPara, -100, 12 , 0.4, 0, false);//drive to Mogo Fast to save time
    MoveEncoderPID(TestPara, -70, 8, 0.3, 0, true);// slow down so Mogo doesn't get sent flying

    Clamp.set(false);
    wait(200,msec);

    TurnMaxTimePID(TestPara, 130, 0.5, true);// turn  to face the first ring 
    MoveEncoderPID(TestPara, 90, 29, 0.3, 130, true);//drive to grab the first ring
    RunRoller(100);
    MoveEncoderPID(TestPara, -90, 10, 0.3, 130, true); //drive back to be safe
    TurnMaxTimePID(TestPara, 115, 0.3, true);
    MoveEncoderPID(TestPara, 100, 20, 0.3, 115, true);
    MoveEncoderPID(TestPara, -100, 23, 0.3, 48, false);
    MoveEncoderPID(TestPara, 100, 25, 0.3, 48, true);
    

    
    

}

void RedRingRush(){
    PIDDataSet TestPara={1.5,0.1,0.15};
    MoveEncoderPID(TestPara, 100, 50, 0.3, 0, true);
    MoveEncoderPID(TestPara, -100, 40, 0.3, 2, true);
    doinker.set(false);
    TurnMaxTimePID(TestPara, -35, 0.3 , true);
    MoveEncoderPID(TestPara, -60, 12, 0.3, -35, true);
    TurnMaxTimePID(TestPara, -90, 0.4, true);
    MoveEncoderPID(TestPara, 70, 40, 0.3, -90, true);
    TurnMaxTimePID(TestPara, 176, 0.6, true);
    MoveEncoderPID(TestPara, 90, 42, 0.3, 176, true);
    



    
}
void RedLocalSAWP() {
    PIDDataSet TestPara={1.5,0.1,0.15};
  Clamp.set(true);
    TurnMaxTimePID(TestPara, -57, 0.4, true);
    MoveEncoderPID(TestPara, 100, 16, 0.3, -57, true);
    RunLift(80);
    wait(500,msec);
    RunLift(0);
    MoveEncoderPID(TestPara, -100, 22, 0.3, -58, true);
    RunLift(-100);
    wait(555, msec);
    RunLift(0);
    TurnMaxTimePID(TestPara, 0, 0.4, true);
    liftSensor.resetPosition();
    MoveEncoderPID(TestPara, -100, 17 , 0.4, 2, false);//drive to Mogo Fast to save time
    
    MoveEncoderPID(TestPara, -60, 15, 0.3, 2, false);// slow down so Mogo doesn't get sent flying
 
    Clamp.set(false);
    wait(200,msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, 90, 0.5, true);// Turn to face first ring
    MoveEncoderPID(TestPara, 90, 30, 0.3, 90, true);//drive to grab first ring
    TurnMaxTimePID(TestPara,20, 0.6, true);//turn to face the corner for bottom ring
    MoveEncoderPID(TestPara, 100, 55, 0.3, 20, true);// drive to grab the bottom ring
    MoveEncoderPID(TestPara, 65, 15, 0.3, 20, true);
    
    wait(100,msec);//Wait to make sure you actually grab the ring

    MoveEncoderPID(TestPara, -60,5, 0.3, 20, true);// back up out of corner
    TurnMaxTimePID(TestPara, -90, 0.7, true);// Turn to face last ring in front of alliance
    MoveEncoderPID(TestPara, 80, 54, 0.3, -90, false);//drive towards last ring fast to sacve time
    
    Pistake.set(true);
    
    MoveEncoderPID(TestPara, 60, 25, 0.3, -90, true);// drive slower to last ring to not hit ring
  wait(200,msec);
    Pistake.set(false);
    wait(100,msec);
    MoveEncoderPID(TestPara, -100, 33, 0.3, -90, true);
    TurnMaxTimePID(TestPara, -143, 0.6, true);
    MoveEncoderPID(TestPara, 100, 20, 0.3, -143, false);
    RunLift(70);
    wait(650,msec);
    RunLift(0); 
    



    
}
void BlueLocalSAWP() {
    PIDDataSet TestPara={1.5,0.1,0.15};
   /*Clamp.set(true);
    TurnMaxTimePID(TestPara, 57, 0.4, true);
    MoveEncoderPID(TestPara, 100, 16, 0.3, 57, true);
    RunLift(80);
    wait(500,msec);
    RunLift(0);
    MoveEncoderPID(TestPara, -100, 22, 0.3, 58, true);
    RunLift(-100);
    wait(555, msec);
    RunLift(0);
    TurnMaxTimePID(TestPara, 0, 0.4, true);
    liftSensor.resetPosition();
    MoveEncoderPID(TestPara, -100, 17 , 0.4, -2, false);//drive to Mogo Fast to save time
    
    MoveEncoderPID(TestPara, -60, 15, 0.3, -2, false);// slow down so Mogo doesn't get sent flying
 
    Clamp.set(false);
    wait(200,msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, -90, 0.5, true);// Turn to face first ring
    MoveEncoderPID(TestPara, 90, 30, 0.3, -90, true);//drive to grab first ring
    TurnMaxTimePID(TestPara, -20, 0.6, true);//turn to face the corner for bottom ring
    MoveEncoderPID(TestPara, 100, 55, 0.3, -20, true);// drive to grab the bottom ring
    MoveEncoderPID(TestPara, 65, 15, 0.3, -20, true);
    
    wait(100,msec);//Wait to make sure you actually grab the ring

    MoveEncoderPID(TestPara, -60,5, 0.3, -20, true);// back up out of corner
    TurnMaxTimePID(TestPara, 90, 0.7, true);// Turn to face last ring in front of alliance
    MoveEncoderPID(TestPara, 80, 54, 0.3, 90, false);//drive towards last ring fast to sacve time
    
    Pistake.set(true);
    
    MoveEncoderPID(TestPara, 60, 25, 0.3, 90, true);// drive slower to last ring to not hit ring
  wait(200,msec);
    Pistake.set(false);
    wait(100,msec);
    MoveEncoderPID(TestPara, -100, 33, 0.3, 90, true);
    TurnMaxTimePID(TestPara, 143, 0.6, true);
    MoveEncoderPID(TestPara, 100, 20, 0.3, 143, false);
    RunLift(70);
    wait(650,msec);
    RunLift(0);

    
    

*/
    
    



    
}

void Skills(){
    PIDDataSet TestPara={1.5,0.1,0.15};
    Clamp.set(true);
    MoveEncoderPID(TestPara, -40, 0.2, 0.3, 0, true);
    RunRoller(100);
    wait(500,msec);
    RunRoller(0);
    MoveEncoderPID(TestPara, 80, 18, 0.3, 0, true);
    TurnMaxTimePID(TestPara, -90, 0.6,true);
    Clamp.set(false);
    MoveEncoderPID(TestPara, -100, 13 , 0.4, -90, false);//drive to Mogo Fast to save time
    MoveEncoderPID(TestPara, -70, 12.5, 0.3, -90, false);// slow down so Mogo doesn't get sent flying
    MoveEncoderPID(TestPara, -100, 13 , 0.4, -90, false);//drive to Mogo Fast to save time
    MoveEncoderPID(TestPara, -70, 12.5, 0.3, -90, false);// slow down so Mogo doesn't get sent flying
    Clamp.set(true);

    TurnMaxTimePID(TestPara, 0,  0.3, true);
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 25, 0.3, 0, true);
    TurnMaxTimePID(TestPara, 45, 0.3, true);
    MoveEncoderPID(TestPara, 80, 30, 0.3,45, true);
    armMoveToAngle(-15, 70);
    TurnMaxTimePID(TestPara, 90, 0.3, true);
    MoveEncoderPID(TestPara, 70, 25, 0.3, 90, true);
    RunRoller(0);
    wait(100,msec);
    RunLift(60);
    wait(400,msec);
    RunLift(0);
    wait(200,msec);
    RunLift(-75);

    MoveEncoderPID(TestPara, -80, 25, 0.3, 90, true);
    RunRoller(0);

    TurnMaxTimePID(TestPara, 0, 0.4, true);
    
    MoveEncoderPID(TestPara, 100, 30, 0.3, 0, true);
    MoveEncoderPID(TestPara, 76, 36, 0.3, 0, true);
    TurnMaxTimePID(TestPara, 45, 0.3, true);
    MoveEncoderPID(TestPara, 100, 12, 0.3, 45, true);
    TurnMaxTimePID(TestPara, -5, 0.3, true);
    MoveEncoderPID(TestPara, -40, 10, 0.3, -5, true);
    Clamp.set(false);
    wait(200,msec);
    MoveEncoderPID(TestPara, 40, 10, 0.3, -5, true);
    TurnMaxTimePID(TestPara, 90, 0.3 , true);
    MoveEncoderPID(TestPara, 90, 76, 0.3, -5, true);
    MoveEncoderPID(TestPara, -70, 14, 0.3, 90, false);
    Clamp.set(true);
    wait(400,msec);
    TurnMaxTimePID(TestPara, 0, 0.6, true);





    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 25, 0.3, 0, true);
    TurnMaxTimePID(TestPara, -45, 0.3, true);
    MoveEncoderPID(TestPara, 80, 30, 0.3,-45, true);
    armMoveToAngle(-15, 70);
    TurnMaxTimePID(TestPara, -90, 0.3, true);
    MoveEncoderPID(TestPara, 70, 25, 0.3, -90, true);
    RunRoller(0);
    wait(100,msec);
    RunLift(60);
    wait(400,msec);
    RunLift(0);
    wait(200,msec);
    RunLift(-75);

    MoveEncoderPID(TestPara, -80, 25, 0.3, -90, true);
    RunRoller(0);

    TurnMaxTimePID(TestPara, 0, 0.4, true);
    
    MoveEncoderPID(TestPara, 100, 30, 0.3, 0, true);
    MoveEncoderPID(TestPara, 76, 36, 0.3, 0, true);
    TurnMaxTimePID(TestPara, -45, 0.3, true);
    MoveEncoderPID(TestPara, 100, 12, 0.3, -45, true);
    TurnMaxTimePID(TestPara, 5, 0.3, true);
    MoveEncoderPID(TestPara, -40, 10, 0.3, 5, true);
    Clamp.set(false);






    





}
void RedMogoRush() {
    











    PIDDataSet TestPara={1.5,0.1,0.15};
    TurnMaxTimePID(TestPara, 49, 0.4, true);
    MoveEncoderPID(TestPara, 100, 17, 0.3, 49, true);
    RunLift(60);
    wait(1000,msec);
    MoveEncoderPID(TestPara, -100, 16.8, 0.3, 49, true);
    RunLift(-81);
    TurnMaxTimePID(TestPara, 0, 0.4, true);
    RunLift(0);
    liftSensor.resetPosition();
    MoveEncoderPID(TestPara, -100, 13 , 0.4, 0, false);//drive to Mogo Fast to save time
    MoveEncoderPID(TestPara, -70, 13, 0.3, 0, false);// slow down so Mogo doesn't get sent flying
   
    Clamp.set(true);
    wait(200,msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, -90, 0.5, true);// Turn to face first ring
    MoveEncoderPID(TestPara, 90, 25.5, 0.3, -90, true);//drive to grab first ring
    wait(1000,msec);
    Clamp.set(false);
    TurnMaxTimePID(TestPara, 0, 0.6, true);//turn to 5th mogo
    
    MoveEncoderPID(TestPara, -100, 7.2 , 0.4, 0, false);//drive to Mogo Fast to save time
    
    MoveEncoderPID(TestPara, -70, 8.9, 0.3, 0, true);// slow down so Mogo doesn't get sent flying
    Clamp.set(true);

    MoveEncoderPID(TestPara, 100, 18 , 0.4, 0, false);//drive back toi where the first ringh used to be
    
    TurnMaxTimePID(TestPara,-28, 0.6, true);//turn to face the corner for bottom ring
    MoveEncoderPID(TestPara, 70, 43, 0.3, -28, false);// drive to grab the bottom ring
    MoveEncoderPID(TestPara, 90, 15, 0.3, -28, false);
    wait(100,msec);//Wait to make sure you actually grab the ring

    MoveEncoderPID(TestPara, -60,15, 0.3, -28, true);// back up out of corner
    doinker.set(true);
    MoveEncoderPID(TestPara, 60, 12, 0.3, -28, true);// back up out of corner
    
    TurnMaxTimePID(TestPara, -25, 0.5, true);
    
    MoveEncoderPID(TestPara, -60,15, 0.3, -25, true);// back up out of corner
    doinker.set(false);

    








   

  
    
    
    
    
    


    
    



    
}