/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "dropLift.h"
#include "Subsystems/ElevatorSubsystem.h"
#include "../Robot.h"
#include <iostream>

dropLift::dropLift() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::elevatorSubsystem.get());
}

// Called just before this Command runs the first time
void dropLift::Initialize() {
	Robot::elevatorSubsystem.get()->InitCounter();
}

// Called repeatedly when this Command is scheduled to run
void dropLift::Execute() {
	Robot::elevatorSubsystem.get()->ElevateUp(-0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool dropLift::IsFinished() {
	return Robot::elevatorSubsystem.get()->HasSwitchSet();
}

// Called once after isFinished returns true
void dropLift::End() {
	Robot::elevatorSubsystem.get()->StopElevate();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void dropLift::Interrupted() {

}
