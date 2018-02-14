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
	range = new frc::AnalogInput(0);
	inMagneticSwitch = new frc::DigitalInput(0);
}

void DriveTrainSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
	SetDefaultCommand(new TeleopCommand());
}
//Public
void DriveTrainSubsystem::TankDrive(double left, double right) {
	myRobot.TankDrive(left, right, false);
}

void DriveTrainSubsystem::driveForward(double speed)
{
	myRobot.TankDrive(speed,speed);
}
void DriveTrainSubsystem::takeJoystickInputs(Joystick *left, Joystick *right)
{
	myRobot.TankDrive(left->GetY(),right->GetY(), false);
}
void DriveTrainSubsystem::stopRobot()
{
	myRobot.TankDrive(0,0,false);
}
float DriveTrainSubsystem::GetGyroValue() {
	return gyro.GetAngle();
}
void DriveTrainSubsystem::ResetGyro() {
	gyro.Reset();
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






