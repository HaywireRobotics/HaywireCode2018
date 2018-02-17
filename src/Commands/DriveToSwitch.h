#ifndef autoGetPowerSwitchCL_H
#define autoGetPowerSwitchCL_H

#include <Commands/CommandGroup.h>

class DriveToSwitch : public frc::CommandGroup {
public:
	DriveToSwitch(std::string);
};

#endif  // autoGetPowerSwitchCL_H
