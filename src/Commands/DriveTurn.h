#ifndef DriveTurn_H
#define DriveTurn_H

#include "Commands/Command.h"

class DriveTurn : public frc::Command {
public:
	DriveTurn(int);
	void Initialize();
	void Execute();
	bool IsFinished();
	void End();
	void Interrupted();
};

#endif  // DriveTurn_H
