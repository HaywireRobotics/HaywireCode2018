#include "SwitchHeightCommand.h"
#include "../Robot.h"
#include <iostream>

SwitchHeightCommand::SwitchHeightCommand() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::elevatorSubsystem.get());
}

// Called just before this Command runs the first time
void SwitchHeightCommand::Initialize() {
	Robot::elevatorSubsystem.get()->InitCounter();
	Robot::elevatorSubsystem.get()->movingToPosition = true;

//	Robot::elevatorSubsystem.get()->ElevateUp(0.5);
}

// Called repeatedly when this Command is scheduled to run
void SwitchHeightCommand::Execute() {
	Robot::elevatorSubsystem.get()->ElevatorSet(0.1);
}

// Make this return true when this Command no longer needs to run execute()
bool SwitchHeightCommand::IsFinished() {
	return Robot::elevatorSubsystem.get()->HasSwitchSet();
}

// Called once after isFinished returns true
void SwitchHeightCommand::End() {
	Robot::elevatorSubsystem.get()->StopElevate();
	Robot::elevatorSubsystem.get()->movingToPosition = false;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void SwitchHeightCommand::Interrupted() {
	this->End();
}
