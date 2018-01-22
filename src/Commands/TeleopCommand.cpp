#include "TeleopCommand.h"
#include "../Robot.h"
#include "../Subsystems/DriveTrainSubsystem.h"
#include "../OI.h";

TeleopCommand::TeleopCommand() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::driveTrainSubsystem.get());
}

// Called just before this Command runs the first time
void TeleopCommand::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TeleopCommand::Execute() {
	Robot::driveTrainSubsystem->takeJoystickInputs((Robot::oi->getJoystickRight().get()),(Robot::oi->getJoystickLeft().get()));
}

// Make this return true when this Command no longer needs to run execute()
bool TeleopCommand::IsFinished() {
	return false;
}

// Called once after isFinished returns true
void TeleopCommand::End() {
	Robot::driveTrainSubsystem->stopRobot();
}

// Called when another command which requires one or more of the same
// subsystems is scheduled to run
void TeleopCommand::Interrupted() {
}
