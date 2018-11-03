/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "DriveToScaleLeft.h"
#include "../Commands/CloseClaw.h"
#include "../Commands/OpenClaw.h"
#include "../Commands/DriveForward.h"
#include "../Commands/SwitchHeightCommand.h"
#include "../Commands/ElevatorToSwitch.h"
#include "../Commands/HoldHold.h"
#include "../Commands/DriveLeftTurn.h"
#include "../Commands/DriveRightTurn.h"
#include "../Commands/DriveForwardDistance.h"
#include "../Commands/ElevateToSwitchAndHold.h"
#include "../Commands/ElevatorToScale.h"
#include "../Commands/ElevateToScaleAndHold.h"
#include "LiftClaw.h"
#include <iostream>

DriveToScaleLeft::DriveToScaleLeft(std::string gameData) {

	if(gameData[0] == 'L')
	{
		AddSequential(new DriveForward(3.2, 0.8));
		AddSequential(new DriveRightTurn(77.0));
		AddSequential(new DriveForward(-1.8, 0.5));

		//Practice
		AddSequential(new ElevatorToScale());
		AddParallel(new HoldHold());
		AddParallel(new LiftClaw());
		AddSequential(new DriveForward(1.5, 0.5));
		AddSequential(new OpenClaw());
		AddSequential(new DriveForward(-2.5, 0.45));
		AddSequential(new DriveRightTurn(38.5));
		AddSequential(new DriveForward(2.0, 0.5));
	}

	else if (gameData[1] == 'R')
	{
		AddSequential(new DriveForward(5.0, 0.5));
    }

	else
	{
		AddSequential(new DriveForward(2.0, 0.8));
	}
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
}
