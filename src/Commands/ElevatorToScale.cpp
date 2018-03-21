/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ElevatorToScale.h"

ElevatorToScale::ElevatorToScale() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::elevatorSubsystem.get());
	this->time = new Timer();
}

// Called just before this Command runs the first time
void ElevatorToScale::Initialize() {
	this->time->Reset();
	this->time->Start();
}

// Called repeatedly when this Command is scheduled to run
void ElevatorToScale::Execute() {
	Robot::elevatorSubsystem.get()->ElevateUp(0.7);
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorToScale::IsFinished() {
	return this->time->HasPeriodPassed(3.0);
}

// Called once after isFinished returns true
void ElevatorToScale::End() {
	Robot::elevatorSubsystem.get()->ElevateUp(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorToScale::Interrupted() {

}
