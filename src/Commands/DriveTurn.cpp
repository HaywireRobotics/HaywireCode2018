#include "DriveTurn.h"
#include "Subsystems/DriveTrainSubsystem.h"
#include "../Robot.h"
#include <iostream>

DriveTurn::DriveTurn(int angle) {
	// Use Requires() here to declare subsystem dependencies
	Requires(Robot::driveTrainSubsystem.get());
	turnAngle = Robot::driveTrainSubsystem->GetGyroValue() + angle;
	std::cout << turnAngle << std::endl;
	this->speed = 0.5;
}

// Called just before this Command runs the first time
void DriveTurn::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void DriveTurn::Execute() {
	std::cout << "Executing" << std::endl;
	Robot::driveTrainSubsystem->TankDrive(this->speed, -1 * this->speed * 2);
	std::cout << "Finished Execute" << std::endl;
}

// Make this return true when this Command no longer needs to run execute()
bool DriveTurn::IsFinished() {
	return (Robot::driveTrainSubsystem->GetGyroValue() == this->turnAngle);
}

// Called once after isFinished returns true
void DriveTurn::End() {
	Robot::driveTrainSubsystem->stopRobot();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void DriveTurn::Interrupted() {

}
