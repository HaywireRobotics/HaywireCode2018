#include "DriveForward.h"
#include "../Robot.h"
#include <iostream>

DriveForward::DriveForward(double seconds, double speed) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::driveTrainSubsystem.get());
	time = new Timer();
	this->seconds = seconds;
	this->speed = speed;
	if (seconds < 0)
		this->negative = true;
	else
		this->negative = false;
}

// Called just before this Command runs the first time
void DriveForward::Initialize() {
	time->Reset();
	time->Start();
	Robot::driveTrainSubsystem->SetDrivingBackward(false);
}

// Called repeatedly when this Command is scheduled to run
void DriveForward::Execute()
{
	if(this->seconds < 0)
		Robot::driveTrainSubsystem->driveForward(speed);
	else
		Robot::driveTrainSubsystem->driveForward(-speed);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForward::IsFinished() {
	if(this->seconds < 0)
	{
		Robot::driveTrainSubsystem->SetDrivingBackward(true);
//		std::cout << "Set Driving Backward to " + Robot::driveTrainSubsystem->GetDrivingBackward() << std::endl;
		return this->time->HasPeriodPassed(-seconds);
	}
	else
	{
		return this->time->HasPeriodPassed(seconds);
		Robot::driveTrainSubsystem->SetDrivingBackward(false);
	}
}

// Called once after isFinished returns true
void DriveForward::End() {
	if (this->seconds < 0) {
		Robot::driveTrainSubsystem->SetDrivingBackward(true);
	}
//	Robot::driveTrainSubsystem->SetDrivingBackward(false);
	Robot::driveTrainSubsystem->stopRobot();
}

// Called when another command which require s one or more of the same
// subsystems is scheduled to run
void DriveForward::Interrupted() {

}

