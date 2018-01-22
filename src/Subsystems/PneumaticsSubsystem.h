/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>
#include <Compressor.h>
#include <DoubleSolenoid.h>

class PneumaticsSubsystem : public frc::Subsystem {
public:
	PneumaticsSubsystem();
	void InitDefaultCommand() override;
	void SetSole1Open();
	void SetSole1Close();
	void SetSole1Stop();


//	frc::Compressor *compressor;
	frc::DoubleSolenoid *Sole1;
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
private:
};
