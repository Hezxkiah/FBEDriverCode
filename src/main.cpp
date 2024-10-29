/*----------------------------------------------------------------------------*/
/*                                                                            */
/*    Module:       main.cpp                                                  */
/*    Author:       C:\Users\hezek                                            */
/*    Created:      Thu Sep 05 2024                                           */
/*    Description:  V5 project                                                */
/*                                                                            */
/*----------------------------------------------------------------------------*/

// ---- START VEXCODE CONFIGURED DEVICES ----
// Robot Configuration:
// [Name]               [Type]        [Port(s)]
// IntakeMotor          motor         6               
// Controller1          controller                    
// leftFrontM           motor         1               
// leftBackM            motor         2               
// rightFrontM          motor         3               
// rightBackM           motor         4               
// airFist              digital_out   A               
// ---- END VEXCODE CONFIGURED DEVICES ----


#include "vex.h"

using namespace vex;

bool airOn;

int airPump()
{
  while (1)
  {
    if (Controller1.ButtonR2.pressing())
    {
      if(airOn)
      {
        airFist.set(true);
        airOn = false;
        wait(0.1,seconds);
      }
      
      else
      {
        airFist.set(false);
        airOn = true;
        wait(0.1,seconds);
      }
    }
  }

  return 0;
}

int joysticks()
{
  while(1)
  {
    leftFrontM.spin(fwd,(Controller1.Axis3.position()),velocityUnits::pct);
    leftBackM.spin(fwd,(Controller1.Axis3.position()),velocityUnits::pct);
    
    rightFrontM.spin(fwd,(Controller1.Axis2.position()),velocityUnits::pct); 
    rightBackM.spin(fwd,(Controller1.Axis2.position()),velocityUnits::pct); 
  }
  
  return 0;
}

int IntakeUp()
{
  while(1)
  {
    if (Controller1.ButtonL1.pressing())
    {
      IntakeMotor.spin(forward,100,velocityUnits::pct);
    }

    else if (Controller1.ButtonL2.pressing())
    {
      IntakeMotor.spin(reverse,100,velocityUnits::pct);
    }

    else 
    {
      IntakeMotor.stop();
    }
  }
  return 0;
}

int main() 
{
  // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  task MyTask1 = task(joysticks);
  task Mytask2 = task(IntakeUp);
  // task MyTask3 = task(IntakeDown);
  task MyTask4 = task(airPump);
}
