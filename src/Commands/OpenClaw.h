#ifndef PullPiston_H
#define PullPiston_H

#include <Commands/Command.h>
#include <Timer.h>

class OpenClaw : public frc::Command {
public:
	OpenClaw();
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // PullPiston_H
