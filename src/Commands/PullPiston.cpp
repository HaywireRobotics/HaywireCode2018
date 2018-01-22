#include "PullPiston.h"
#include "../Subsystems/PneumaticsSubsystem.h"
#include "../Robot.h"

PullPiston::PullPiston() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
}

// Called just before this Command runs the first time
void PullPiston::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void PullPiston::Execute() {
	Robot::pneumaticsSubsystem->SetSole1Open();
}

// Make this return true when this Command no longer needs to run execute()
bool PullPiston::IsFinished() {
	return true;
}

// Called once after isFinished returns true
void PullPiston::End() {

}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void PullPiston::Interrupted() {

}