#include "../Commands/DriveForward.h"
#include "Subsystems/ElevatorSubsystem.h"
#include "../Robot.h"
#include "HoldHold.h"
#include <iostream>

HoldHold::HoldHold() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::elevatorSubsystem.get());
}

// Called just before this Command runs the first time
void HoldHold::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void HoldHold::Execute() {
	std::cout << "HOLDING" << std::endl;
	Robot::elevatorSubsystem.get()->ElevateUp(0.3);
}

// Make this return true when this Command no longer needs to run execute()
bool HoldHold::IsFinished() {
	std::cout << "HoldHold isFinished" << std::endl;
	return Robot::driveTrainSubsystem->GetDrivingBackward();
}

// Called once after isFinished returns true
void HoldHold::End() {
	Robot::elevatorSubsystem.get()->ElevateUp(-0.2);
	std::cout << "HoldHold End" << std::endl;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void HoldHold::Interrupted() {

}
