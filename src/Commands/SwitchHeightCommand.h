#ifndef SwitchHeightCommand_H
#define SwitchHeightCommand_H

#include "Commands/Command.h"

class SwitchHeightCommand : public frc::Command {
public:
	SwitchHeightCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // SwitchHeightCommand_H
