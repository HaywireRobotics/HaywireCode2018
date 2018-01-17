/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "DriveTrainSubsystem.h"

#include "../RobotMap.h"


DriveTrainSubsystem::DriveTrainSubsystem()
    : frc::Subsystem("DriveTrainSubsystem") {
}

void DriveTrainSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}
//Public
void DriveTrainSubsystem::TankDrive(float left, float right) {
	this->MoveLeft(left);
	this->MoveRight(right);
}

void DriveTrainSubsystem::takeJoystickInputs(Joystick left, Joystick right) {
	this->TankDrive(left,right);
}

void DriveTrainSubsystem::stopRobot() {
	myRobot.Drive(0,0);
}
//Private
void DriveTrainSubsystem::MoveLeft(float speed) {
	this->DriveTrainLeft0.Set(speed);
	this->DriveTrainLeft1.Set(speed);
}

void DriveTrainSubsystem::MoveRight(float speed) {
	this->DriveTrainRight0.Set(speed);
	this->DriveTrainRight1.Set(speed);
}
