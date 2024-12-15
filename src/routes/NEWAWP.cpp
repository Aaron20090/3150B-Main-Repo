#include "../movement.hpp"
#include "../helper_functions.hpp"
#include "vex.h"
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out t calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);
void Simple6Inverted(){
  PIDDataSet TestPara={1.5,0.1,0.15};
  lift.resetPosition();
    Clamp.set(true);
   /* MoveEncoderPID(TestPara, -100, 3, 0.3, 0, true);
    TurnMaxTimePID(TestPara, -51, 0.4, true);
    MoveEncoderPID(TestPara, 100, 22, 0.3, -51, true);
    RunLift(80);
    wait(500,msec);
    RunLift(0);
    MoveEncoderPID(TestPara, -100, 23, 0.3, -58, true);
   RunLift(-50);
    TurnMaxTimePID(TestPara, 0, 0.4, true);
    liftSensor.resetPosition(); */ 
    //commenting out bc alliance skate sucks 
    
    MoveEncoderPID(TestPara, -100, 15, 0.4, 1, false);//drive to Mogo Fast to save time
    RunLift(0);
  MoveEncoderPID(TestPara, -60, 23, 0.4, 1, false);//Move back slower so moog doesn't go flying
  Clamp.set(false);
  wait(150,msec);
  //MoveEncoderPID(TestPara, 100, 3.3 , 0.3, 0, true);
  TurnMaxTimePID(TestPara, -133, 0.6, true);//turn to face 1st ring
 RunRoller(100);
  MoveEncoderPID(TestPara, 100, 28, 0.3, -133,true);//drive to 1st ring

  MoveEncoderPID(TestPara, -100, 6, 0.2, -118 ,true);//drive back to be safe
  TurnMaxTimePID(TestPara, -120, 0.3, true);//turn to 2nd ring
  MoveEncoderPID(TestPara, 100, 17, 0.2, -120, true);//drive to second ring
    MoveEncoderPID(TestPara, -100, 10, 0.2, -115, true);
  MoveEncoderPID(TestPara, -100, 15, 0.2, -160, false);//drive back
  TurnMaxTimePID(TestPara, -90, 0.5, true);// turn to 3rd ring
  MoveEncoderPID(TestPara, 100, 20, 0.2, -90, true);//drive to 3rd ring
  MoveEncoderPID(TestPara, -100, 5, 0.4, -90, true);
  TurnMaxTimePID(TestPara, -40, 0.5, true);// turn to corner
  MoveEncoderPID(TestPara, 100, 65, 0.2, -40, true);//drive fast to corner
  MoveEncoderPID(TestPara, 60, 20, 0.2, -40, true);// drive slower to not break anything
  wait(50,msec);
  MoveEncoderPID(TestPara, -100, 10, 0.2, -60, true);//drive back
 /*TurnMaxTimePID(TestPara, 90, 0.5, true);//face last ring
  MoveEncoderPID(TestPara, 100, 50, 0.2, 90, true);// drive to last ring
  //lift.setVelocity(60,percent);
  //lift.spinTo(-86, degrees);//lift wall stakes
  Pistake.set(true);
  MoveEncoderPID(TestPara, 100, 36, 0.4, 90, true);
   Pistake.set(false);
  MoveEncoderPID(TestPara, -100, 5, 0.3, 85, true);// drive  to last ring
  
  TurnMaxTimePID(TestPara, 182, 0.5, true);// turn to alliance stake
  

  MoveEncoderPID(TestPara, 70, 20, 0.5, 172, false);// drive back
  RunLift(100);
  wait(400, msec);
  RunLift(0);
*/


}
void Simple6(){
     PIDDataSet TestPara={1.5,0.1,0.15};
  lift.resetPosition();
    Clamp.set(true);
   /* MoveEncoderPID(TestPara, -100, 3, 0.3, 0, true);
    TurnMaxTimePID(TestPara, -51, 0.4, true);
    MoveEncoderPID(TestPara, 100, 22, 0.3, -51, true);
    RunLift(80);
    wait(500,msec);
    RunLift(0);
    MoveEncoderPID(TestPara, -100, 23, 0.3, -58, true);
   RunLift(-50);
    TurnMaxTimePID(TestPara, 0, 0.4, true);
    liftSensor.resetPosition(); */ 
    //commenting out bc alliance skate sucks 
    
    MoveEncoderPID(TestPara, -100, 17, 0.4, 1, false);//drive to Mogo Fast to save time
    RunLift(0);
  MoveEncoderPID(TestPara, -60, 20, 0.4, 1, false);//Move back slower so moog doesn't go flying
  Clamp.set(false);
  wait(150,msec);
  //MoveEncoderPID(TestPara, 100, 3.3 , 0.3, 0, true);
  TurnMaxTimePID(TestPara, 133, 0.6, true);//turn to face 1st ring
 RunRoller(100);
  MoveEncoderPID(TestPara, 100, 28, 0.3, 133,true);//drive to 1st ring

  MoveEncoderPID(TestPara, -100, 8, 0.2, 115 ,true);//drive back to be safe
  TurnMaxTimePID(TestPara, 115, 0.3, true);//turn to 2nd ring
  MoveEncoderPID(TestPara, 80, 20, 0.2, 115, true);//drive to second ring
    MoveEncoderPID(TestPara, -100, 10, 0.2, 115, true);
  MoveEncoderPID(TestPara, -100, 15, 0.2, 160, false);//drive back
  TurnMaxTimePID(TestPara, 90, 0.5, true);// turn to 3rd ring
  MoveEncoderPID(TestPara, 100, 20, 0.2, 90, true);//drive to 3rd ring
  TurnMaxTimePID(TestPara, 30, 0.5, true);// turn to corner
  MoveEncoderPID(TestPara, 100, 55, 0.2, 30, true);//drive fast to corner
  MoveEncoderPID(TestPara, 60, 16, 0.2, 30, true);// drive slower to not break anything
  wait(50,msec);
  MoveEncoderPID(TestPara, -100, 10, 0.2, 30, true);//drive back
  TurnMaxTimePID(TestPara, -90, 0.5, true);//face last ring
 /**/ MoveEncoderPID(TestPara, 100, 30, 0.2, -90, true);// drive to last ring
  //lift.setVelocity(60,percent);
  //lift.spinTo(-86, degrees);//lift wall stakes
 // Pistake.set(true);
 // MoveEncoderPID(TestPara, 100, 38, 0.4, -90, true);
  // Pistake.set(false);
 // MoveEncoderPID(TestPara, -100, 5, 0.3, -85, true);// drive  to last ring
  
 // TurnMaxTimePID(TestPara, -182, 0.5, true);// turn to alliance stake
  

  //MoveEncoderPID(TestPara, 70, 20, 0.5, -172, false);// drive back


  

}
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
  
    MoveEncoderPID(TestPara, -100, 3, 0.3, 0, true);
    TurnMaxTimePID(TestPara, -50, 0.4, true);
    MoveEncoderPID(TestPara, 100, 20, 0.3, -50, true);
    RunLift(80);
    wait(500,msec);
    RunLift(0);
    MoveEncoderPID(TestPara, -100, 22, 0.3, -58, true);
    RunLift(-50);
    TurnMaxTimePID(TestPara, 0, 0.4, true);
    MoveEncoderPID(TestPara, -100, 15, 0.4, 1, false);//drive to Mogo Fast to save time
      RunLift(0);
    
    MoveEncoderPID(TestPara, -50, 24, 0.3, 1, false);// slow down so Mogo doesn't get sent flying
 
    Clamp.set(false);
    wait(200,msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, 85, 0.5, true);// Turn to face first ring
    MoveEncoderPID(TestPara, 100, 28, 0.3, 85, true);//drive to grab first ring
    TurnMaxTimePID(TestPara, -45, 0.4, true);
    
    MoveEncoderPID(TestPara, 100, 57, 0.3, -45, true);
    TurnMaxTimePID(TestPara, -90, 0.4, true);
    Pistake.set(true);
    MoveEncoderPID(TestPara, 100, 40, 0.3, -92, true);//drive towards last ring fast to sacve time 
     Pistake.set(false);
    MoveEncoderPID(TestPara, -100, 10, 0.4, -90, true);
    wait(700, msec);
    Clamp.set(true);
    RunRoller(-100);
    MoveEncoderPID(TestPara, 100, 65, 0.4, -90, true);
    wait(100, msec);
    TurnMaxTimePID(TestPara, 0, 0.4, true);
    MoveEncoderPID(TestPara, -100, 16, 0.4, 0, true);
    MoveEncoderPID(TestPara, -50, 10,  0.4, 0, true);
    Clamp.set(false);
    wait(100, msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, -90, 0.4, true);
    MoveEncoderPID(TestPara, 100, 25, 0.3, -90, true);
    wait(400, msec);
    RunLift(100);
    TurnMaxTimePID(TestPara, 90, 0.4, true);
    RunRoller(100);
    wait(60, msec);
    
       RunLift(0);
    MoveEncoderPID(TestPara, 100, 17, 0.4, 90, false);
 




    

    

    



    
}
void BlueLocalSAWP() {
      PIDDataSet TestPara={1.5,0.1,0.15};
  Clamp.set(true);
    MoveEncoderPID(TestPara, -100, 3, 0.3, 0, true);
    TurnMaxTimePID(TestPara, 50, 0.4, true);
    MoveEncoderPID(TestPara, 100, 20, 0.3, 50, true);
    RunLift(80);
    wait(500,msec);
    RunLift(0);
    MoveEncoderPID(TestPara, -100, 22, 0.3, 58, true);
    RunLift(-100);
    wait(555, msec);
    RunLift(0);
    TurnMaxTimePID(TestPara, 0, 0.4, true);
    wait(455, msec);
    RunLift(0);
    MoveEncoderPID(TestPara, -100, 20, 0.4, -2, false);//drive to Mogo Fast to save time
    
    MoveEncoderPID(TestPara, -60, 15, 0.3, -2, false);// slow down so Mogo doesn't get sent flying
 
    Clamp.set(false);
    wait(200,msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, -90, 0.5, true);// Turn to face first ring
    MoveEncoderPID(TestPara, 90, 28, 0.3, -90, true);//drive to grab first ring
    TurnMaxTimePID(TestPara, -20, 0.6, true);//turn to face the corner for bottom ring
    
    MoveEncoderPID(TestPara, 100, 45, 0.3, -20, true);// drive to grab the bottom ring
    MoveEncoderPID(TestPara, 65, 30, 0.3, -20, true);
    
    wait(100,msec);//Wait to make sure you actually grab the ring

    MoveEncoderPID(TestPara, -60,5, 0.3, -20, true);// back up out of corner
    TurnMaxTimePID(TestPara, 95, 0.7, true);// Turn to face last ring in front of alliance
    wait(50, msec);
    MoveEncoderPID(TestPara, 100, 44, 0.3, 95, false);
    Clamp.set(true);
    Pistake.set(true);
    MoveEncoderPID(TestPara, 100, 40, 0.3, 95, false);//drive towards last ring fast to sacve time 
    Pistake.set(false);
    wait(400, msec);
    RunRoller(0);   
    TurnMaxTimePID(TestPara, -25, 0.6, true);
    MoveEncoderPID(TestPara, -50, 35, 0.4, -25, true);
    Clamp.set(false);
    wait(100, msec);
    RunRoller(100);
    TurnMaxTimePID(TestPara, 90, 0.4, true);
    MoveEncoderPID(TestPara, 100, 25, 0.3, 90, true);
    wait(100, msec);
    TurnMaxTimePID(TestPara, -110, 0.4, true);
    wait(100, msec);
       RunLift(100);
       wait(400, msec);
       RunLift(0);
    MoveEncoderPID(TestPara, 100, 20, 0.4, -110, false);
    


    
    



    
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
void BlueMogoRush() {
    











    PIDDataSet TestPara={1.5,0.1,0.15};
        Clamp.set(true);
    MoveEncoderPID(TestPara, 100, 75, 0.3, 0, true); //drive toward middle mogo at full speed
    OPMECH.set(true);//active opmech
     wait(50,msec);
    MoveEncoderPID(TestPara, -100, 35, 0.3, 0, true);//grab mogo and bag that shi
    MoveEncoderPID(TestPara, -60, 20, 0.4, 0, true);
    OPMECH.set(false);//let go bc the ops are after me
    wait(100, msec);  
    TurnMaxTimePID(TestPara, 198, 0.4, true);//turn so my behind is toward suspect
    MoveEncoderPID(TestPara, -40, 15, 0.4, 198, true);
    Clamp.set(false);
    wait(400, msec);
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 25, 0.4, 0, true);
    TurnMaxTimePID(TestPara, 20, 0.4, true);
    Clamp.set(true);
    MoveEncoderPID(TestPara, 100, 20, 0.4, 20, true);
    wait(100, msec);
    RunRoller(0);
    TurnMaxTimePID(TestPara, 88, 0.4, true);

   MoveEncoderPID(TestPara, -40, 30, 0.4, 88, true);
   Clamp.set(false);
   wait(100, msec);
   RunRoller(100);
   MoveEncoderPID(TestPara, 100, 35, 0.4, 75, true);
  
    
}
void RedMogoRush(){
   PIDDataSet TestPara={1.5,0.1,0.15};
    Clamp.set(true);
    MoveEncoderPID(TestPara, 100, 75, 0.3, 0, true); //drive toward middle mogo at full speed
    OPMECH.set(true);//active opmech 
     wait(50,msec);
    MoveEncoderPID(TestPara, -100, 30, 0.3, 0, true);//grab mogo and bag that shi
    MoveEncoderPID(TestPara, -60, 5, 0.4, 0, true);
    OPMECH.set(false);//let go bc the ops are after me
    wait(100, msec);
    TurnMaxTimePID(TestPara, -160, 0.4, true);//turn so my behind is toward suspect
     MoveEncoderPID(TestPara, -30, 20, 0.3, -160, true);// back into suspect
     Clamp.set(false);//grab her by the leg
         wait(200, msec);
    RunRoller(100);
    MoveEncoderPID(TestPara, 100, 25, 0.3, -160, true);//run up on em ops
         TurnMaxTimePID(TestPara, 0, 0.4, true);//turn toward the big double tower
  Clamp.set(true);

    TurnMaxTimePID(TestPara, -110, 0.4, true);//turn to drop suspect off to the warehouse
     MoveEncoderPID(TestPara, -80, 15, 0.3, -110, true);//run up on em ops
         MoveEncoderPID(TestPara, -20, 7, 0.3, -110, true);//run up on em ops

     Clamp.set(false);//bag that shit cuzo
     wait(100, msec);
     TurnMaxTimePID(TestPara, -35, 0.4, true);//turn toward the big double tower

     MoveEncoderPID(TestPara, 100, 52, 0.3, -35, true);//fill em with the bomb
          wait(100, msec);
        TurnMaxTimePID(TestPara, -135, 0.4, true);//turn toward the big double tower
     MoveEncoderPID(TestPara, 100, 30, 0.3, -135, true);//run up on em ops
     MoveEncoderPID(TestPara, 40, 5, 0.3, -160, true);//run up on em ops

     MoveEncoderPID(TestPara, -100, 5, 0.3, -160, true);//run up on em ops

}
