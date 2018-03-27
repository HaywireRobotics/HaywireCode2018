/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "DriveToSwitchRight.h"
#include "../Commands/DriveForward.h"
#include "../Commands/ElevatorToSwitch.h"
#include "../Commands/ElevatorToScale.h"
#include "../Commands/HoldHold.h"
#include "../Commands/ElevateToSwitchAndHold.h"
#include <iostream>

DriveToSwitchRight::DriveToSwitchRight(std::string gameData) {
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
	if(gameData[0] == 'R')
	{
		AddParallel(new ElevateToSwitchAndHold());
		AddSequential(new DriveForward(2.3,0.7));
		AddSequential(new DriveLeftTurn(-75.0));
		AddSequential(new DriveForward(0.3, 0.5));
		AddSequential(new OpenClaw());
		AddSequential(new DriveForward(-1.5,0.4));
	}

	else if(gameData[1] == 'R')
	{
			AddSequential(new DriveForward(3.1, 0.8));
			AddSequential(new DriveLeftTurn(-77.0));
			AddSequential(new DriveForward(-2.3, 0.5));

			//Practice
			//AddSequential(new ElevatorToScale());
			//AddParallel(new HoldHold());
			//AddSequential(new DriveForward(1.7, 0.5));
			//AddSequential(new OpenClaw());
			//AddSequential(new DriveForward(-3.0, 0.45));
			//AddSequential(new DriveLeftTurn(-38.5));
			//AddSequential(new DriveForward(2.0, 0.5));
	}

	else if (gameData[1] == 'L') {
		AddSequential(new DriveForward(5.0, 0.5));
	}

}
