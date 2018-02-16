#include "DriveRightTurn.h"
#include "Subsystems/DriveTrainSubsystem.h"
#include "../Robot.h"
#include <iostream>

DriveRightTurn::DriveRightTurn(float angle) {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::driveTrainSubsystem.get());
	this->startLoop = true;
	turnAngle = Robot::driveTrainSubsystem.get()->GetGyroValue() + angle;
	this->inputAngle = angle;
	this->speed = 0.5;
	this->rampSpeed = 0.0;
}

// Called just before this Command runs the first time
void DriveRightTurn::Initialize() {
}

// Called repeatedly when this Command is scheduled to run
void DriveRightTurn::Execute() {
	if(this->startLoop) {
		this->turnAngle = this->inputAngle + Robot::driveTrainSubsystem.get()->GetGyroValue();
		this->rampSpeed = 0.0;
		this->startLoop = false;
	}

	this->rampSpeed += 0.05;
	this->rampSpeed = std::min(double(this->rampSpeed), this->speed);
	Robot::driveTrainSubsystem->TankDrive(this->rampSpeed, -1 * this->rampSpeed * 2);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveRightTurn::IsFinished() {
	return (Robot::driveTrainSubsystem.get()->GetGyroValue() >= this->turnAngle);
}

// Called once after isFinished returns true
void DriveRightTurn::End() {
	Robot::driveTrainSubsystem.get()->stopRobot();
	this->startLoop = true;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveRightTurn::Interrupted() {

}
