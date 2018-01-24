#include "ElevatorSubsystem.h"
#include "../RobotMap.h"

ElevatorSubsystem::ElevatorSubsystem() : Subsystem("ExampleSubsystem") {

}

void ElevatorSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.

void ElevatorSubsystem::ElevateUp(float speed) {
	this->Elevator0.Set(speed);
	this->Elevator1.Set(speed);
}

void ElevatorSubsystem::ElevateDown(float speed) {
	this->Elevator0.Set(-1 * speed);
	this->Elevator1.Set(-1 * speed);
}

void ElevatorSubsystem::StopElevate() {
	this->Elevator0.Set(0.0);
	this->Elevator1.Set(0.0);
}
