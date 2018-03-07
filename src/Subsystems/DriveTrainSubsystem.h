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
#include "../Enums.h"
#include <RobotDrive.h>
#include <Joystick.h>
#include "../Commands/TeleopCommand.h"
#include <ADXRS450_Gyro.h>
#include <AnalogInput.h>
#include <DigitalInput.h>
#include <Drive/DifferentialDrive.h>
#include <SpeedControllerGroup.h>
#include <PWMVictorSPX.h>

class DriveTrainSubsystem : public frc::Subsystem {
public:
	DriveTrainSubsystem(RobotType roboTypeIn);
	void InitDefaultCommand() override;
	void takeJoystickInputs(Joystick *left, Joystick *right);
	void driveForward(double speed);
	void stopRobot();
	void TankDrive(double left, double right);
	float GetGyroValue();
	double GetRangeValue();
	void ResetGyro();
	void SetDrivingBackward(bool input);
	bool GetDrivingBackward();
	RobotType GetRobotType();
	frc::ADXRS450_Gyro gyro { frc::SPI::Port::kOnboardCS0 };
	frc::AnalogInput *range;
	frc::DigitalInput *inMagneticSwitch;
	bool doneDrivingBackward;

private:
	frc::PWMVictorSPX DriveTrainLeft0 { DriveTrain1 };
	frc::PWMVictorSPX DriveTrainLeft1 { DriveTrain2 };
	frc::SpeedControllerGroup LeftGroup {DriveTrainLeft0, DriveTrainLeft1};

	frc::PWMVictorSPX DriveTrainRight0 { DriveTrain3 };
	frc::PWMVictorSPX DriveTrainRight1 { DriveTrain4 };
	frc::SpeedControllerGroup RightGroup {DriveTrainRight0, DriveTrainRight1};

	frc::DifferentialDrive myRobot{LeftGroup, RightGroup};
	void MoveLeft(float speed);
	void MoveRight(float speed);
	RobotType roboType;
};
