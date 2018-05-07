/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "DriveForwardDistance.h"
#include "../Robot.h"
#include <iostream>

DriveForwardDistance::DriveForwardDistance(double distanceTarget) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::driveTrainSubsystem.get());
	this->distanceTarget = Robot::driveTrainSubsystem.get()->GetRangeValue()+ distanceTarget;
	speed = -0.5;
	this->distanceActual = 0.0;
}

// Called just before this Command runs the first time
void DriveForwardDistance::Initialize()
{
	distanceActual = Robot::driveTrainSubsystem.get()->GetRangeValue();
}

// Called repeatedly when this Command is scheduled to run
void DriveForwardDistance::Execute() {
	Robot::driveTrainSubsystem->driveForward(speed);
}

// Make this return true when this Command no longer needs to run execute()
bool DriveForwardDistance::IsFinished() {
	if(distanceActual > distanceTarget)
	{
		return true;
	}
	else {
		return false;
	}
}

// Called once after isFinished returns true
void DriveForwardDistance::End() {
	Robot::driveTrainSubsystem->driveForward(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveForwardDistance::Interrupted() {

}
