/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "PneumaticsSubsystem.h"
#include <Compressor.h>
#include <Solenoid.h>

#include "../RobotMap.h"

PneumaticsSubsystem::PneumaticsSubsystem() : frc::Subsystem("PneumaticsSubsystem") {
	/*compressor = new Compressor(CompressorPort);
	compressor->ClearAllPCMStickyFaults();
	compressor->SetClosedLoopControl(true);*/

	openSole1 = new Solenoid(Solenoid1OpenPort);
	closeSole1 = new Solenoid(Solenoid1ClosePort);
}

void PneumaticsSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void PneumaticsSubsystem::SetSole1Open() {
	openSole1->Set(true);
	closeSole1->Set(false);
}

void PneumaticsSubsystem::SetSole1Close() {
	openSole1->Set(false);
	closeSole1->Set(true);
}

void PneumaticsSubsystem::SetSole1Stop() {
	openSole1->Set(false);
	closeSole1->Set(false);
}
