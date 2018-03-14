/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
#include <Commands/CloseClaw.h>
#include <Commands/OpenClaw.h>
#include <Commands/DriveToSwitchLeft.h>
#include "../Commands/DriveForward.h"
#include "../Commands/SwitchHeightCommand.h"
#include "../Commands/ElevatorToSwitch.h"
#include "../Commands/HoldHold.h"
#include "../Commands/DriveLeftTurn.h"
#include "../Commands/DriveRightTurn.h"
#include "../Commands/DriveForwardDistance.h"
#include "../Commands/OpenClaw.h"

#include "DriveToSwitchCenter.h"

DriveToSwitchCenter::DriveToSwitchCenter(std::string gameData) {
	// Add Commands here:
	// e.g. AddSequential(new Command1());
	//      AddSequential(new Command2());
	// these will run in order.

	// To run multiple commands at the same time,
	// use AddParallel()
	// e.g. AddParallel(new Command1());
	//      AddSequential(new Command2());
	// Command1 and Command2 will run in parallel.

	// A command group will require all of the subsystems that each member
	// would require.
	// e.g. if Command1 requires chassis, and Command2 requires arm,
	// a CommandGroup containing them would require both the chassis and the
	// arm.
	if (gameData[0] == 'L') {
		AddSequential(new DriveForward(1.0,0.5));
		AddSequential(new DriveLeftTurn(-32.5));
		AddParallel(new ElevatorToSwitch());
		AddSequential(new DriveForward(2.0,0.5));
		AddSequential(new DriveRightTurn(32.5));
		AddParallel(new HoldHold());
		AddSequential(new DriveForward(1.5, 0.5));
		AddSequential(new OpenClaw());
		AddSequential(new DriveForward(-1.0, 0.5));
	}
	else if (gameData[0] == 'R') {
		AddSequential(new DriveForward(1.0, 0.5));
	}
}
