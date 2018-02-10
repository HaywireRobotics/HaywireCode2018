#include "DriveTurn.h"
#include "Subsystems/DriveTrainSubsystem.h"
#include "../Robot.h"

DriveTurn::DriveTurn(int angle) {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::driveTrainSubsystem.get());
}

// Called just before this Command runs the first time
void DriveTurn::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveTurn::Execute() {

}

// Make this return true when this Command no longer needs to run execute()
bool DriveTurn::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void DriveTurn::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveTurn::Interrupted() {

}
