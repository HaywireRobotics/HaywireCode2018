#include "DriveForward.h"
#include "../Robot.h"
#include <iostream>

DriveForward::DriveForward(double seconds) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::driveTrainSubsystem.get());
	time = new Timer();
	this->seconds = seconds;
	speed = -0.5;
}

// Called just before this Command runs the first time
void DriveForward::Initialize() {
	time->Reset();
	time->Start();
}

// Called repeatedly when this Command is scheduled to run
void DriveForward::Execute()
{
	if(seconds < 0)
		Robot::driveTrainSubsystem->driveForward(-speed);
	else
		Robot::driveTrainSubsystem->driveForward(speed);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForward::IsFinished() {
	if(seconds < 0)
	{
		return time->HasPeriodPassed(-seconds);
		Robot::driveTrainSubsystem->SetDrivingBackward(true);
	}
	else
	{
		return time->HasPeriodPassed(seconds);
		Robot::driveTrainSubsystem->SetDrivingBackward(false);
	}
}

// Called once after isFinished returns true
void DriveForward::End() {
	Robot::driveTrainSubsystem->stopRobot();
}

// Called when another command which require s one or more of the same
// subsystems is scheduled to run
void DriveForward::Interrupted() {

}

