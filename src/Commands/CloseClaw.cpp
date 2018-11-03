/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include <Commands/CloseClaw.h>
#include "../Subsystems/PneumaticsSubsystem.h"
#include "../Robot.h"

CloseClaw::CloseClaw() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(&Robot::chassis);
	Requires(Robot::pneumaticsSubsystem.get());
}

// Called just before this Command runs the first time
void CloseClaw::Initialize() {}

// Called repeatedly when this Command is scheduled to run
void CloseClaw::Execute() {
	Robot::pneumaticsSubsystem.get()->SetSole1Close();
	//Robot::pneumaticsSubsystem->SetSole1Close();
}

// Make this return true when this Command no longer needs to run execute()
bool CloseClaw::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void CloseClaw::End() {}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void CloseClaw::Interrupted() {}
