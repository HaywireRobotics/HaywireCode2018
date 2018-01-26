#include "ElevatorSubsystem.h"
#include "../RobotMap.h"

ElevatorSubsystem::ElevatorSubsystem() : Subsystem("ElevatorSubsystem") {
	limitSwitch = new frc::DigitalInput(1);
	counter = new frc::Counter(limitSwitch);
}

void ElevatorSubsystem::InitDefaultCommand() {}

//Custom Public
void ElevatorSubsystem::ElevateUp(float speed) {
	this->SetElevatorSpeed(speed);
}

void ElevatorSubsystem::ElevateDown(float speed) {
	this->SetElevatorSpeed(-1 * speed);
}

void ElevatorSubsystem::StopElevate() {
	this->SetElevatorSpeed(0.0);
}

void ElevatorSubsystem::ElevatorSet(float speed) {
	this->SetElevatorSpeed(speed);
}

void ElevatorSubsystem::InitCounter() {
	counter->Reset();
}

bool ElevatorSubsystem::HasSwitchSet() {
	return counter->Get() > 0;
}

//Private
void ElevatorSubsystem::SetElevatorSpeed(float speed) {
	this->Elevator0.Set(speed);
	this->Elevator1.Set(speed);
}
