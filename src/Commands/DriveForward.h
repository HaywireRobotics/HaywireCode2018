#ifndef DriveForward_H
#define DriveForward_H

#include <Commands/Command.h>
#include "Subsystems/DriveTrainSubsystem.h"
#include <Timer.h>

class DriveForward : public frc::Command {
public:
	DriveForward(double);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
private:
	Timer *time;
	double seconds;
};

#endif  // DriveForward_H
