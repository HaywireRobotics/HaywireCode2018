/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "PushPiston.h"
#include "../Subsystems/PneumaticsSubsystem.h"
#include "../Robot.h"

PushPiston::PushPiston() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(&Robot::chassis);
	Requires(Robot::pneumaticsSubsystem.get());
}

// Called just before this Command runs the first time
void PushPiston::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void PushPiston::Execute() {
	Robot::pneumaticsSubsystem->SetSole1Close();
	//Robot::pneumaticsSubsystem->SetSole1Close();
}

// Make this return true when this Command no longer needs to run execute()
bool PushPiston::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void PushPiston::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PushPiston::Interrupted() {}
