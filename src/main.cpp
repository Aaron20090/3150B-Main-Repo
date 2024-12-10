/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       VEX                                                       */
/*    Created:      Thu Sep 26 2019                                           */
/*    Description:  Competition Template                                      */
/*                                                                            */
/*----------------------------------------------------------------------------*/

//#include "STDLib.cpp"
#include "vex.h"
#include "math.h"
#include "screen_gui.hpp"
#include "movement.hpp"
#include "routes/routes.hpp"
#include <iostream>
using namespace vex;
using namespace std;

// A global instance of competition
competition Competition;


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

bool SP;
bool EXIT;
bool Inversion_Constant;
void pre_auton(void) {
  liftSensor.resetPosition();
  
  lift.setStopping(brake);
   EXIT=false;
   
  
  PX=0;
  JX=0;
  AutoSelectorVal=0;
  SP=false;
  
  
  // Initializing Robot Configuration. DO NOT REMOVE!
  wait(1000,msec);
  
  vexcodeInit();
  
Gyro.calibrate();

//Ensure Robot Launch Position is set before auto proceeds, once plugged into field control,
//start program and do not temper bot under all circumstances

//1. IF ANY ADJUSTMENT IS NEEDED, QUIT PROGRAM, THEN ADJUST, RESTART PROGRAM AFTER ADJUSTMENTS COMPLETED
//2. DO NOT START PROGRAM BEFORE PLUGGING IN FIELD CONTROL, THIS MAY DISABLE AUTO
//3. ONLY SIGNAL JUDGES TO BEGIN MATCH AFTER THE ZEROING PROMPT ON SCREEN HAS CLEARED

//Print precautionary message
Brain.Screen.drawRectangle(0,0,500,500);

Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#f8b195");
Brain.Screen.setCursor(2,10);
Brain.Screen.print("FLIR TIMEOUT");


waitUntil(!Gyro.isCalibrating());


Zeroing(true,true);
DisplayAutoSelector();
DisplayWords();

//task AutoSelTask=task(ScreenSelMain);
  while(!EXIT)
{
if(Brain.Screen.xPosition()<100)
{
if(Brain.Screen.yPosition()<75&&Brain.Screen.yPosition()>25)AutoSelectorVal=1;
else if(Brain.Screen.yPosition()<150&&Brain.Screen.yPosition()>100)AutoSelectorVal=3;
else if(Brain.Screen.yPosition()<225&&Brain.Screen.yPosition()>175)AutoSelectorVal=5;
}
else if(Brain.Screen.xPosition()>375)
{
if(Brain.Screen.yPosition()<75&&Brain.Screen.yPosition()>25)AutoSelectorVal=2;
else if(Brain.Screen.yPosition()<150&&Brain.Screen.yPosition()>100)AutoSelectorVal=4;
else if(Brain.Screen.yPosition()<225&&Brain.Screen.yPosition()>175)AutoSelectorVal=6;
}

if(Brain.Screen.xPosition()>187&&Brain.Screen.xPosition()<287)
{
if(Brain.Screen.yPosition()<55&&Brain.Screen.yPosition()>5) EXIT=true;
else if(Brain.Screen.yPosition()>125&&Brain.Screen.yPosition()<225)AutoSelectorVal=7;
}

if(Brain.Screen.pressing()&&!SP) UpdateDynamic();

SP=Brain.Screen.pressing();

}

Brain.Screen.clearScreen();

if(AutoSelectorVal==1){
Brain.Screen.drawRectangle(1,25,100,50);
  Brain.Screen.setCursor(3,3);
  Brain.Screen.print("AWP");

Brain.Screen.setFillColor(black);
Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#f8b195");
Brain.Screen.setCursor(3,10);
if(Inversion_Constant==false)Brain.Screen.print("red");
else if(Inversion_Constant == true)Brain.Screen.print("blue");
Brain.Screen.setCursor(4,10);
Brain.Screen.print("AWP");
Brain.Screen.setFont(monoM);
  Brain.Screen.setFillColor("#f8b195");

}

if(AutoSelectorVal==2){
Brain.Screen.drawRectangle(375,25,100,50);
    Brain.Screen.setCursor(3,40);
  Brain.Screen.print("Risky");

Brain.Screen.setFillColor(black);

  Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#f8b195");
Brain.Screen.setCursor(3,10);
//Brain.Screen.print("MATCHLOAD");
if(Inversion_Constant==false)Brain.Screen.print("red");
else if(Inversion_Constant == true)Brain.Screen.print("Blue");
Brain.Screen.setCursor(4,10);
Brain.Screen.print("Risky");
Brain.Screen.setFont(monoM);
  Brain.Screen.setFillColor("#f8b195");
}

if(AutoSelectorVal==3){
  Brain.Screen.drawRectangle(1,100,100,50);
  Brain.Screen.setCursor(7,3);
  Brain.Screen.print("n/a");

Brain.Screen.setFillColor(black);

    Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#f8b195");
Brain.Screen.setCursor(3,10);
//Brain.Screen.print("GOAL SIDE");
if(Inversion_Constant==false)Brain.Screen.print("Red");
else if(Inversion_Constant == true)Brain.Screen.print("Blue");
Brain.Screen.setCursor(4,10);
Brain.Screen.print("n/a");
Brain.Screen.setFont(monoM);  
  Brain.Screen.setFillColor("#f8b195");
}

if(AutoSelectorVal==4){
Brain.Screen.drawRectangle(375,100,100,50);
  Brain.Screen.setCursor(7,40);
  Brain.Screen.print("Safe");

Brain.Screen.setFillColor(black);

  Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#f8b195");
Brain.Screen.setCursor(3,10);
//Brain.Screen.print("MATCHLOAD");
if(Inversion_Constant==false)Brain.Screen.print("Red");
else if(Inversion_Constant == true)Brain.Screen.print("Blue");
Brain.Screen.setCursor(4,10);
Brain.Screen.print("Safe");
Brain.Screen.setFont(monoM); 
  Brain.Screen.setFillColor("#f8b195");

}

if(AutoSelectorVal==5){
  Brain.Screen.drawRectangle(1,175,100,50);
      Brain.Screen.setCursor(11,3);
  Brain.Screen.print("Simple6Inverted");

Brain.Screen.setFillColor(black);
    Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#f8b195");
Brain.Screen.setCursor(3,10);
//Brain.Screen.print("GOAL SIDE");
if(Inversion_Constant==false)Brain.Screen.print("RED");
else if(Inversion_Constant == true)Brain.Screen.print("Blue");
Brain.Screen.setCursor(4,10);
Brain.Screen.print("Risky AWP");
Brain.Screen.setFont(monoM); 
  Brain.Screen.setFillColor("#f8b195");

}

if(AutoSelectorVal==6){
Brain.Screen.drawRectangle(375,175,175,50);
Brain.Screen.setCursor(11,40);
Brain.Screen.print("ML-AWP");
Brain.Screen.setFillColor(black);
Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#f8b195");
Brain.Screen.setCursor(3,10);
//Brain.Screen.print("MATCHLOAD");
if(Inversion_Constant==false)Brain.Screen.print("Red");
else if(Inversion_Constant == true)Brain.Screen.print("Blue");
Brain.Screen.setCursor(4,10);
Brain.Screen.print("ONLY AWP");
Brain.Screen.setFont(monoM); 
  Brain.Screen.setFillColor("#f8b195");

  }

if(AutoSelectorVal==7){
  //Inversion_Constant=-1;
  Brain.Screen.setCursor(3,10);
Brain.Screen.print("blue");
 /* Brain.Screen.drawRectangle(187,175,100,50);
  Brain.Screen.setCursor(11,22);
  Brain.Screen.print("Skills");

Brain.Screen.setFillColor(black);
      Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#f8b195");
Brain.Screen.setCursor(3,10);
Brain.Screen.print("SKILLS");
Brain.Screen.setCursor(4,10);
Brain.Screen.print("SKILLS");
Brain.Screen.setFont(monoM); 
  Brain.Screen.setFillColor("#f8b195");*/

}

Brain.Screen.setFillColor(black);
Brain.Screen.setFont(monoXL);
Brain.Screen.setPenColor("#f8b195");
Brain.Screen.setCursor(5,10);
Brain.Screen.print("AUTO CONFIRMED");



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
  
//PID Straight and turn arguments:
// MoveEncoderPID(TestPara, motor speed, encoder travel distance (inches), time to full speed(sec), relative heading(to starting position), braking?)
// TurnMaxTimePID(TestPara, Desired Heading -180 to 180, time out to calculate turn, Braking?)
// MoveTimePID(TestPara, motor speed, time traveled (sec), time to full speed, heading, false);

//Do not change the below
PIDDataSet TestPara={3.8,0.1,0.1};
Zeroing(true,true);

//can start editing if nessary
//Put Auto route function into if statements to use autoselector
if(AutoSelectorVal==1)//Quali close 6 triball auto 
{
  RedLocalSAWP();
}

if(AutoSelectorVal==2)// Safe awp
{
  BlueLocalSAWP();
}

if(AutoSelectorVal==3)//Risky
{
  RedMogoRush();
  } 

if(AutoSelectorVal==4)// risky AWP
{
  blue9PTRing();
}

if(AutoSelectorVal==5)// 
{
  Simple6Inverted();

}                   


if(AutoSelectorVal==6)//AWP only
{
      TurnMaxTimePID(TestPara, -106,2,true);
MoveEncoderPID(TestPara, -100, 28, 0.4, -106, true); //grab ring 2
    TurnMaxTimePID(TestPara, -130,0.4,true);
}


if(AutoSelectorVal==7)//DO NOT USE SLOT 7 RESERVED FOR TURN INVERSION
{   
  Inversion_Constant= false;

}
//MoveTimePID(TestPara, -100, 0.5,0.1,-40,true);//score 2nd triball
//(PID Parameters, motor speed -100 - 100, time for travel 0 - inf, time to accelerate to full speed, Absolute Heading, Braking?)

    // ..........................................................................
  // Insert autonomous user code here.
  // ..........................................................................
CStop();
}
int RV;
int LV;
int DriveTask(void){
  while(true)
  {
    EXIT=true;
    RV=Controller1.Axis3.position(percent)-Controller1.Axis1.position(percent);
    LV=Controller1.Axis3.position(percent)+Controller1.Axis1.position(percent);
    Move(LV,RV);
  }

return 0;
}
int V;
int ButtonPressingB=0,BTaskActiv=0;
bool Check = true;
bool discDetected = false;
  unsigned counter = 0;
bool rightcolor;
bool waiting = false;
int rollerStopTime = 500; // Time to stop in milliseconds
int delayStartTime = 0;
bool rollerSpinning =false;

int arraynumber;
int arraynumber2;
int arraynumber3;
int arrarnumber4;
vex::timer Timer;

int ATask(void)
{
  
  double pow;
  if(Inversion_Constant == true)
  {
    arraynumber = 0;
    arraynumber2 = 10;
    arraynumber3 = 200;
    arrarnumber4 = 270;

  }
  else if (Inversion_Constant == false)
  {
    arraynumber = 0;
    arraynumber2 = 10;
    arraynumber3 = 200;
    arrarnumber4 = 270;
  }

  OpSens.integrationTime(5);
  OpSens.setLightPower(100,percent);
  double powl; //powl is the power for lift
  //bool question = false;
  double hue;
  
    while (true) {
    hue = OpSens.hue();

    // Handle Button B press and task activation/deactivation
     if (BTaskActiv == 0 && Controller1.ButtonB.pressing() && ButtonPressingB == 0) {
        Check = false;
        discDetected = false;
        ButtonPressingB = 1;  // Button is now pressed
        BTaskActiv = 1;        // Task is now active
    } 
    else if(!Controller1.ButtonB.pressing())ButtonPressingB=0;
    else if (BTaskActiv == 1 && Controller1.ButtonB.pressing() && ButtonPressingB == 0) {
        Check = true;
        ButtonPressingB = 1;   // Button is now pressed
        BTaskActiv = 0;        // Task is now inactive
    }


    ////////////////////////////////////////////////////////////////////////////////////////////////
    if (hue >= arraynumber && hue <= arraynumber2 && !discDetected && OpSens.isNearObject() == true) {
            discDetected = true;
            rightcolor =true;
            
            
            Roller.resetPosition();
        }
    else if(hue >= arraynumber3 && hue<=arrarnumber4 && !discDetected){

        discDetected = true;
        rightcolor =false;
        rollerSpinning = true;
        Roller.resetPosition();

    }
    // Control roller based on hue detection and button presses
    if (!Check) {
      cout<<Roller.position(degrees)<<endl;
        

        if (discDetected&&rightcolor) {
          cout<<"disdetected and its the right colour"<<endl;
            if (Roller.position(degrees) >= -1500) {
                RunRoller(-100);
                cout<<"redirecting"<<endl;
            } else {
                discDetected = false;
                
            }
        } 
        else if (!discDetected) {
            
            pow = (Controller1.ButtonR2.pressing() - Controller1.ButtonR1.pressing()) * 100;
            RunRoller(-pow);
        }
    } 
    else {
        pow = (Controller1.ButtonR2.pressing() - Controller1.ButtonR1.pressing()) * 100;
        RunRoller(-pow);
    }/*
    if (rollerSpinning) {
      if(!rightcolor){
        if (Roller.position(degrees) > 792) {  // Approximately 2.2 rotations (360 * 2.2 = 792 degrees)
              RunRoller(0);  // Stop the roller
                // Stop spinning
              rollerSpinning=false;
              waiting = true;  // Start waiting
              Timer.clear();
              delayStartTime = Timer.time(); // Record the current time
          }
      }
    }

    // Handle the non-blocking wait outside the main if-check loop
    if (waiting) {
      cout<<"a"<<endl;
      cout<<delayStartTime<<endl;
      
        // Check if the delay time has passed
        if (delayStartTime>= rollerStopTime) {
            waiting = false;  // Stop waiting
            discDetected = false;  // Reset disc detection
            RunRoller(-100);  // Start the roller again
            rightcolor= true;
            Roller.resetPosition();  // Reset the roller's position after restarting
        }
      
    }*/
    
    }

    // Control lift power based on button presses
    return 0;
    
}
        
        
  //RunPuncher((Controller1.ButtonB.pressing())*100);

  
  




int ButtonPressingX,XTaskActiv;
int ButtonPressingY,YTaskActiv;
int ButtonPressingA,ATaskActiv;
int ButtonPressingU,UTaskActiv;
int PTask(void)
{
    while(true)
    {
      //Toggles Tilt
    if(XTaskActiv==0&&Controller1.ButtonX.pressing()&&ButtonPressingX==0)//Finding if ButtonX is pressing and if it was held down before.
    {
      ButtonPressingX=1;//Button is now pressed
      XTaskActiv=1;//Task is now active
      doinker.set(true);
    }

    else if(!Controller1.ButtonX.pressing())ButtonPressingX=0;

    else if(XTaskActiv==1&&Controller1.ButtonX.pressing()&&ButtonPressingX==0)//Finding if task is active and if ButtonX wasn't pressed before
    {
      ButtonPressingX=1;//Button is now pressed
      XTaskActiv=0;//Task is now NOT running
      doinker.set(false);
    }
    //----------------------
      //Toggles Clamp
    if(YTaskActiv==0&&Controller1.ButtonY.pressing()&&ButtonPressingY==0)//Finding if ButtonY is pressing and if it was held down before.
    {
      ButtonPressingY=1;//Button is now pressed
      YTaskActiv=1;//Task is now active
      Clamp.set(true);
    }

    else if(!Controller1.ButtonY.pressing())ButtonPressingY=0;//Button is not pressed so pressing is set to 0

    else if(YTaskActiv==1&&Controller1.ButtonY.pressing()&&ButtonPressingY==0)//Findingif Ytask already happened(clamp active)
    {
      ButtonPressingY=1;//Button pressed
      YTaskActiv=0;//Task is now NOT happening 
      Clamp.set(false);
    }

    //Toggles Pistake(The piston on the intake)
    if(UTaskActiv==0&&Controller1.ButtonUp.pressing()&&ButtonPressingU==0)
    {
      ButtonPressingU=1;
      UTaskActiv=1;
      OPMECH.set(true);
    }
    else if(!Controller1.ButtonUp.pressing())ButtonPressingU=0;

    else if(UTaskActiv==1&&Controller1.ButtonUp.pressing()&&ButtonPressingU==0)

    {
      ButtonPressingU=1;
      UTaskActiv=0;
      OPMECH.set(false);
      
    }
  
  
    if(ATaskActiv==0&&Controller1.ButtonA.pressing()&&ButtonPressingA==0)
    {
      ButtonPressingA=1;
      ATaskActiv=1;
      Pistake.set(true);
    }
    else if(!Controller1.ButtonA.pressing())ButtonPressingA=0;

    else if(ATaskActiv==1&&Controller1.ButtonA.pressing()&&ButtonPressingA==0)

    {
      ButtonPressingA=1;
      ATaskActiv=0;
      Pistake.set(false);
      
    }
    }

  return 0;
  }
  

int ButtonPressingL, LTaskActiv;
int BTask(void) {
  int mvel = 0;
  int pow1 = 0;
  liftSensor.resetPosition();
  while(true) {
    cout<<(liftSensor.position(degrees))<<endl;
    
    if(LTaskActiv==1) {
      if(abs(liftSensor.position(degrees)) < 23) {
        RunLift(60);
        if(abs(liftSensor.position(degrees)) > 23) {
          LTaskActiv = 0;
        }
      } 
      else if(abs(liftSensor.position(degrees)) > 23) {
        RunLift(-60);
        if(abs(liftSensor.position(degrees)) < 23) {

          LTaskActiv = 0;
        }
      } 
    }
    else {
      pow1=((Controller1.ButtonL1.pressing()-Controller1.ButtonL2.pressing())*75);//Calculate intake power, if button pressed, button.pressing returns 1
      if(pow1==0) {
        lift.setStopping(hold);
        lift.stop();
      }
      else {
        RunLift(pow1);
      }
    }

// copy of macro so if i break it i still have a backup 
  // while(true) {
  //   if(abs(liftSensor.position(degrees)) <= 19 && YTaskActiv==1) {
  //     mvel = (90 - liftSensor.position(vex::rotationUnits::deg)) 1.25; //301.81
  //     RunLift(-100);
  //     std::cout << mvel << std::endl; //test
  //     if(abs(liftSensor.position(degrees)) > 19) {
  //       YTaskActiv = 0;
  //     }
  //   }
  //   else {
  //     pow1=((Controller1.ButtonR2.pressing()-Controller1.ButtonR1.pressing())*100);//Calculate intake power, if button pressed, button.pressing returns 1
  //     std::cout << mvel << std::endl; //test
  //     if(pow1==0) {
  //       lift.setStopping(hold);
  //       lift.stop();
  //     }
  //     else {
  //       RunLift(pow1);
  //     }
  //   } 

    //commenting out the button a pressing macro because we do not have a rotation sensor for now

    if(Controller1.ButtonLeft.pressing() && ButtonPressingL == 0) {
      ButtonPressingL=1;
      LTaskActiv=1;
    }

    else if(!Controller1.ButtonLeft.pressing())ButtonPressingL=0;

    else if(LTaskActiv==1&&Controller1.ButtonLeft.pressing()&&ButtonPressingL==0) {
      ButtonPressingL=1;
      LTaskActiv=0;
      RunLift(0);
    }


  }
  return 0;
}
//
// Main will set up the competition functions and callbacks.
//
void usercontrol(void) {
  EXIT=true;//Force Exit Autosel once drivercontrol began.
  // User control code here, inside the loop
  while (1) {
    // This is the main execution loop for the user control program.
    // Each time through the loop your program should update motor + servo
    // values based on feedback from the joysticks.
    
    
    
    task Dtask=task(DriveTask);
    task Atask=task(ATask);
    task Ptask=task(PTask);
    task Btask = task(BTask);
    // ........................................................................
    // Insert user code here. This is where you use the joystick values to
    // update your motors, etc.
    // ........................................................................

    wait(20, msec); // Sleep the task for a short amount of time to
                    // prevent wasted resources.
  }
}

int main() {
  
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
  