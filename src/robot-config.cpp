#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor IntakeMotor = motor(PORT6, ratio18_1, false);
controller Controller1 = controller(primary);
motor leftFrontM = motor(PORT1, ratio18_1, false);
motor leftBackM = motor(PORT2, ratio18_1, false);
motor rightFrontM = motor(PORT3, ratio18_1, true);
motor rightBackM = motor(PORT4, ratio18_1, true);
digital_out airFist = digital_out(Brain.ThreeWirePort.A);

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