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
private:
	float turnAngle;
	double speed;
	bool startLoop;
	float inputAngle;
};

#endif  // DriveTurn_H
