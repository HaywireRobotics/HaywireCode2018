#ifndef TeleopCommand_H
#define TeleopCommand_H

#include "Commands/Command.h"

class TeleopCommand : public frc::Command {
public:
	TeleopCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // TeleopCommand_H
