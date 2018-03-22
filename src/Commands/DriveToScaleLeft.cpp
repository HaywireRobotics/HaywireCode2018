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
#include <iostream>

DriveToScaleLeft::DriveToScaleLeft(std::string gameData) {

	if(gameData[0] == 'L')
	{
		std::cout<<"DriveForward"<<std::endl;
		AddSequential(new DriveForward(3.2, 0.8));
		std::cout<<"DriveRightTurn"<<std::endl;
		AddSequential(new DriveRightTurn(77.0));
		std::cout<<"DriveBackward"<<std::endl;
		AddSequential(new DriveForward(-1.8, 0.5));
		std::cout<<"Elevator to scale"<<std::endl;
		AddSequential(new ElevatorToScale());
		std::cout<<"Hold"<<std::endl;
		AddParallel(new HoldHold());
		std::cout<<"Drive Forward"<<std::endl;
		AddSequential(new DriveForward(1.5, 0.5));
		std::cout<<"Open Claw"<<std::endl;
		AddSequential(new OpenClaw());
		std::cout<<"Drive backward"<<std::endl;
		AddSequential(new DriveForward(-2.5, 0.45));
		AddSequential(new DriveRightTurn(38.5));
		AddSequential(new DriveForward(2.0, 0.5));
	}
	else if (gameData[1] == 'R')
	{
		AddSequential(new DriveForward(5.0, 0.5));
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
