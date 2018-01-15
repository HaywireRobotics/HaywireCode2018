/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>

class DriveTrainSubsystem : public frc::Subsystem {
public:
	DriveTrainSubsystem();
	void InitDefaultCommand() override;
	void TankDrive(float left, float right);

private:
	frc::VictorSP DriveTrainLeft0 { DriveTrain1 };
	frc::VictorSP DriveTrainLeft1 { DriveTrain2 };
	frc::VictorSP DriveTrainRight0 { DriveTrain3 };
	frc::VictorSP DriveTrainRight1 { DriveTrain4 };
	void MoveLeft(float speed);
	void MoveRight(float speed);
};