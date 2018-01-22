/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "PneumaticsSubsystem.h"
#include <Compressor.h>
#include <DoubleSolenoid.h>

#include "../RobotMap.h"

PneumaticsSubsystem::PneumaticsSubsystem() : frc::Subsystem("PneumaticsSubsystem") {
	/*compressor = new Compressor(CompressorPort);
	compressor->ClearAllPCMStickyFaults();
	compressor->SetClosedLoopControl(true);*/

	Sole1 = new DoubleSolenoid(Solenoid1OpenPort,Solenoid1ClosePort);
}

void PneumaticsSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.
void PneumaticsSubsystem::SetSole1Open() {
	Sole1->Set(frc::DoubleSolenoid::kForward);
}

void PneumaticsSubsystem::SetSole1Close() {
	Sole1->Set(frc::DoubleSolenoid::kReverse);
}

void PneumaticsSubsystem::SetSole1Stop() {
	Sole1->Set(frc::DoubleSolenoid::kOff);
}
