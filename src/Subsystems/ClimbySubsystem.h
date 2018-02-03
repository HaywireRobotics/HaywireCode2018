/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once

#include <Commands/Subsystem.h>
#include <Spark.h>
#include <VictorSP.h>
#include <DigitalInput.h>
#include <Counter.h>
#include "../RobotMap.h"
#include "../Commands/TeleopCommand.h"

class ClimbySubsystem : public frc::Subsystem {
public:
	ClimbySubsystem();
	void InitDefaultCommand() override;
	void TapeControl(float speed);
	void WinchControl(float speed);
private:
	frc::Spark ClimbyTapeMotor {ClimbyTapePort};
	frc::Spark ClimbyWinchMotor {ClimbyWinchPort};
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
};
