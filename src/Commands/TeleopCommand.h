#ifndef TeleopCommand_H
#define TeleopCommand_H

#include "Commands/Command.h"
#include "../Commands/PushPiston.h"
#include "../Commands/PullPiston.h"

class TeleopCommand : public frc::Command {
public:
	TeleopCommand();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	PushPiston* PushPistonPtr;
	PullPiston* PullPistonPtr;
};

#endif  // TeleopCommand_H
