/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "ClimbySubsystem.h"

#include "../RobotMap.h"

ClimbySubsystem::ClimbySubsystem()
    : frc::Subsystem("ClimbySubsystem") {
}

void ClimbySubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	//SetDefaultCommand(new TeleopCommand());
}

void ClimbySubsystem::TapeControl(float speed){
	this->ClimbyTapeMotor.Set(speed);
}

void ClimbySubsystem::WinchControl(float speed){
	this->ClimbyWinchMotor.Set(speed);
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
