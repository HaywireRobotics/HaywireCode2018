/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "DriveLeftTurn.h"
#include "Subsystems/DriveTrainSubsystem.h"
#include "../Robot.h"
#include <iostream>

DriveLeftTurn::DriveLeftTurn(float angle) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::driveTrainSubsystem.get());
	this->startLoop = true;
	turnAngle = Robot::driveTrainSubsystem.get()->GetGyroValue() + angle;
	this->inputAngle = angle;
	this->speed = -0.5;
	this->rampSpeed = 0.0;
}

// Called just before this Command runs the first time
void DriveLeftTurn::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveLeftTurn::Execute() {
	if(this->startLoop) {
		this->turnAngle = this->inputAngle + Robot::driveTrainSubsystem.get()->GetGyroValue();
		this->rampSpeed = 0.0;
		this->startLoop = false;
	}

	this->rampSpeed -= 0.05;
	this->rampSpeed = std::max(double(this->rampSpeed), this->speed);
	Robot::driveTrainSubsystem.get()->TankDrive(this->rampSpeed * 2, -1 * this->rampSpeed);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveLeftTurn::IsFinished() {
	return (Robot::driveTrainSubsystem.get()->GetGyroValue() <= this->turnAngle);
}

// Called once after isFinished returns true
void DriveLeftTurn::End() {
	Robot::driveTrainSubsystem.get()->stopRobot();
	this->startLoop = true;
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveLeftTurn::Interrupted() {

}
