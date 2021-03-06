/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "liftLift.h"
#include "Subsystems/ElevatorSubsystem.h"
#include "../Robot.h"
#include <iostream>

liftLift::liftLift(Height height) {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::elevatorSubsystem.get());
	this->passedHeight = height;
}

// Called just before this Command runs the first time
void liftLift::Initialize() {
	Robot::elevatorSubsystem.get()->InitCounter();
}

// Called repeatedly when this Command is scheduled to run
void liftLift::Execute() {
	Robot::elevatorSubsystem.get()->ElevateUp(0.5);
}

// Make this return true when this Command no longer needs to run execute()
bool liftLift::IsFinished() {
	return Robot::elevatorSubsystem.get()->HasSwitchSet();
}

// Called once after isFinished returns true
void liftLift::End() {
	Robot::elevatorSubsystem.get()->StopElevate();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void liftLift::Interrupted() {

}
