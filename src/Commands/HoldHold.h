#ifndef HoldHold_H
#define HoldHold_H

#include "Subsystems/DriveTrainSubsystem.h"
#include "../Robot.h"
#include "Commands/Command.h"

class HoldHold : public frc::Command {
public:
	HoldHold();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // HoldHold_H
