#ifndef DriveRightTurn_H
#define DriveRightTurn_H

#include "Commands/Command.h"

class DriveRightTurn : public frc::Command {
public:
	DriveRightTurn(float angle);
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
	float rampSpeed;
};

#endif  // DriveRightTurn_H
