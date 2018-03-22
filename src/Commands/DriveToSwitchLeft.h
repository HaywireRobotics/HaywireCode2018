#ifndef autoGetPowerSwitchCL_H
#define autoGetPowerSwitchCL_H

#include <Commands/CommandGroup.h>

class DriveToSwitchLeft : public frc::CommandGroup {
public:
	DriveToSwitchLeft(std::string gameData);
};

#endif  // autoGetPowerSwitchCL_H
