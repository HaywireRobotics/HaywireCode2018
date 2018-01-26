#include "DriveForward.h"

DriveForward::DriveForward(double seconds) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::driveTrainSubsystem.get());
	time = new Timer();
	this->seconds = seconds;
}

// Called just before this Command runs the first time
void DriveForward::Initialize() {
	time->Reset();
}

// Called repeatedly when this Command is scheduled to run
void DriveForward::Execute()
{
	Robot::driveTrainSubsystem->driveForward(0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForward::IsFinished() {
	return time->HasPeriodPassed(seconds);
}

// Called once after isFinished returns true
void DriveForward::End() {
	Robot::driveTrainSubsystem->stopRobot();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForward::Interrupted() {

}
