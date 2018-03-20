#include "ElevatorToSwitch.h"
#include "Subsystems/ElevatorSubsystem.h"
#include "../Robot.h"
#include <iostream>

ElevatorToSwitch::ElevatorToSwitch() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::elevatorSubsystem.get());
}

// Called just before this Command runs the first time
void ElevatorToSwitch::Initialize() {
	Robot::elevatorSubsystem.get()->InitCounter();
}

// Called repeatedly when this Command is scheduled to run
void ElevatorToSwitch::Execute() {
	Robot::elevatorSubsystem.get()->ElevateUp(0.7);
}

// Make this return true when this Command no longer needs to run execute()
bool ElevatorToSwitch::IsFinished() {
	return Robot::elevatorSubsystem.get()->HasSwitchSet();
}

// Called once after isFinished returns true
void ElevatorToSwitch::End() {
//	std::cout<<"STUFF STUFF STUFF";
	Robot::elevatorSubsystem.get()->StopElevate();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void ElevatorToSwitch::Interrupted() {

}
