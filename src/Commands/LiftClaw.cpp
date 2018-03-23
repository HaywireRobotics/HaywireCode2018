/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "LiftClaw.h"
#include "../Robot.h"

LiftClaw::LiftClaw() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::clawSubsystem.get());
	this->power = 0.4;
}

// Called just before this Command runs the first time
void LiftClaw::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void LiftClaw::Execute() {
	Robot::clawSubsystem.get()->ElevatorClaw(this->power);
}

// Make this return true when this Command no longer needs to run execute()
bool LiftClaw::IsFinished() {
	return Robot::clawSubsystem.get()->GetDropClaw();
}

// Called once after isFinished returns true
void LiftClaw::End() {
	Robot::clawSubsystem.get()->ElevatorClaw(0.0);
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void LiftClaw::Interrupted() {

}
