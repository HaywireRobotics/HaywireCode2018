/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>
#include <VictorSP.h>
#include "../RobotMap.h"
#include <RobotDrive.h>
#include <Joystick.h>
#include "../Commands/TeleopCommand.h"
#include <ADXRS450_Gyro.h>
#include <AnalogInput.h>
#include <DigitalInput.h>
//#include <DifferentialDrive.h>
#include <SpeedControllerGroup.h>

class DriveTrainSubsystem : public frc::Subsystem {
public:
	DriveTrainSubsystem();
	void InitDefaultCommand() override;
	void takeJoystickInputs(Joystick *left, Joystick *right);
	void stopRobot();
	void TankDrive(float left, float right);
	frc::ADXRS450_Gyro gyro { frc::SPI::Port::kOnboardCS0 };
	frc::AnalogInput *range;
	frc::DigitalInput *inMagneticSwitch;

private:
	frc::VictorSP DriveTrainLeft0 { DriveTrain1 };
	frc::VictorSP DriveTrainLeft1 { DriveTrain2 };
	frc::SpeedControllerGroup LeftGroup {DriveTrainLeft0, DriveTrainLeft1};
	frc::VictorSP DriveTrainRight0 { DriveTrain3 };
	frc::VictorSP DriveTrainRight1 { DriveTrain4 };
	frc::SpeedControllerGroup RightGroup {DriveTrainRight0, DriveTrainRight1};
	frc::DifferentialDrive myRobot{LeftGroup, RightGroup};
	void MoveLeft(float speed);
	void MoveRight(float speed);
};
