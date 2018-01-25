#ifndef ElevatorSubsystem_H
#define ElevatorSubsystem_H

#include <Commands/Subsystem.h>
#include <Spark.h>
#include <DigitalInput.h>
#include <Counter.h>
#include "../RobotMap.h"

class ElevatorSubsystem : public Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

public:
	ElevatorSubsystem();
	void InitDefaultCommand();
	void ElevateUp(float speed);
	void ElevateDown(float speed);
	void StopElevate();
	void ElevatorSet(float speed);
	bool HasSwitchSet();
	void InitCounter();

	frc::Counter *counter;

private:
	frc::Spark Elevator0 { ElevatorPort0 };
	frc::Spark Elevator1 { ElevatorPort1 };
	void SetElevatorSpeed(float speed);

	frc::DigitalInput *limitSwitch;
};

#endif  // ElevatorSubsystem_H
