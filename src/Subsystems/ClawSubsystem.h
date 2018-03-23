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

class ClawSubsystem : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities

	frc::VictorSP claw { ClawPort4 };
	bool dropClaw;
public:
	ClawSubsystem();
	void InitDefaultCommand() override;
	void ElevatorClaw(double speed);
	void SetDropClaw(bool inputBool);
	bool GetDropClaw();
};

