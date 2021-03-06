#include "ElevatorSubsystem.h"
#include "../RobotMap.h"
#include <DigitalInput.h>
#include <Counter.h>
#include <iostream>

ElevatorSubsystem::ElevatorSubsystem() : Subsystem("ElevatorSubsystem") {
	magySwitch = new frc::DigitalInput(2);
	counter = new frc::Counter(magySwitch);
	movingToPosition = false;
}

void ElevatorSubsystem::InitDefaultCommand() {}

//Custom Public
void ElevatorSubsystem::ElevateUp(float speed) {
	this->SetElevatorSpeed(speed);
}

void ElevatorSubsystem::ElevateDown(float speed) {
	this->SetElevatorSpeed(-1 * speed);
}

void ElevatorSubsystem::ElevatorClaw(float speed)
{
	this->claw.Set(speed);
}

void ElevatorSubsystem::StopElevate() {
	this->SetElevatorSpeed(0.0);
}

void ElevatorSubsystem::ElevatorSet(float speed) {
	this->Elevator0.Set(speed);
	this->Elevator1.Set(speed);
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
