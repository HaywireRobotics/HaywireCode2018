#include "DriveRightTurn.h"
#include "Subsystems/DriveTrainSubsystem.h"
#include "../Robot.h"
#include <iostream>

DriveRightTurn::DriveRightTurn(float angle) {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::driveTrainSubsystem.get());
	this->startLoop = true;
	turnAngle = Robot::driveTrainSubsystem.get()->GetGyroValue() + angle;
	this->beforeAngle = 0.0;
	this->inputAngle = angle;
	this->speed = 0.2;
	this->rampSpeed = 0.0;
	this->oneQuarterAngle = angle/4;
	this->threeQuarterAngle = oneQuarterAngle * 3;
	this->currentProgress = 0.0;
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

/*	this->rampSpeed += 0.05;
	this->rampSpeed = std::min(double(this->rampSpeed), this->speed);
	Robot::driveTrainSubsystem->TankDrive(this->rampSpeed, -1 * this->rampSpeed * 2);*/
	if (this->oneQuarterAngle + this->beforeAngle <= Robot::driveTrainSubsystem.get()->GetGyroValue()) {//;
		//Greater than a quarter
	}
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
