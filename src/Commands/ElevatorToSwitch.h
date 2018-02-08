#ifndef ElevatorToSwitch_H
#define ElevatorToSwitch_H

#include "Commands/Command.h"

class ElevatorToSwitch : public frc::Command {
public:
	ElevatorToSwitch();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // ElevatorToSwitch_H
