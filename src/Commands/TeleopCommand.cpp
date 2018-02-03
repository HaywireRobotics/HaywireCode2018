#include "TeleopCommand.h"
#include "../Robot.h"
#include "../RobotMap.h"
#include "../Subsystems/DriveTrainSubsystem.h"
#include "../OI.h"
#include "../Commands/PushPiston.h"
#include "../Commands/PullPiston.h"

TeleopCommand::TeleopCommand() {
	// Use Requires() here to declare subsystem dependencies
	// eg. Requires(Robot::chassis.get());
	Requires(Robot::driveTrainSubsystem.get());
	Requires(Robot::elevatorSubsystem.get());
	Requires(Robot::climbySubsystem.get());
}

// Called just before this Command runs the first time
void TeleopCommand::Initialize() {

}

// Called repeatedly when this Command is scheduled to run
void TeleopCommand::Execute() {

	Robot::driveTrainSubsystem->takeJoystickInputs((Robot::oi->getJoystickRight().get()),(Robot::oi->getJoystickLeft().get()));

	if (Robot::elevatorSubsystem.get()->movingToPosition == false)
	{
		Robot::elevatorSubsystem.get()->ElevatorSet(Robot::oi->getJoystickManipulator().get()->GetY());
	}

	//Claw Open/Close Buttons
	if (Robot::oi->getJoystickManipulator().get()->GetRawButton(JMExtendPistonNum))
	{
		Robot::pneumaticsSubsystem.get()->SetSole1Open();
	}
	if (Robot::oi->getJoystickManipulator().get()->GetRawButton(JMRetractPistonNum))
	{
		Robot::pneumaticsSubsystem.get()->SetSole1Close();
	}

	//Cimby System Buttons
	if (Robot::oi->getJoystickManipulator().get()->GetRawButton(6))
	{
			Robot::climbySubsystem.get()->TapeControl(0.4);
	}
	else if (Robot::oi->getJoystickManipulator().get()->GetRawButton(7))
	{
			Robot::climbySubsystem.get()->TapeControl(-0.4);
	}
	else
	{
		Robot::climbySubsystem.get()->TapeControl(0.0);
	}

	if (Robot::oi->getJoystickManipulator().get()->GetRawButton(8))
	{
			Robot::climbySubsystem.get()->WinchControl(0.7);
	}
	if (Robot::oi->getJoystickManipulator().get()->GetRawButton(9))
	{
				Robot::climbySubsystem.get()->WinchControl(-0.7);
	}
	else
	{
		Robot::climbySubsystem.get()->WinchControl(0.0);
	}

	//Claw Pivot Buttons
	if (Robot::oi->getJoystickManipulator().get()->GetRawButton(3))
	{
			Robot::elevatorSubsystem.get()->ElevatorClaw(0.7);
	}
	else if (Robot::oi->getJoystickManipulator().get()->GetRawButton(4))
	{
			Robot::elevatorSubsystem.get()->ElevatorClaw(-0.7);
	}
	else {
		Robot::elevatorSubsystem.get()->ElevatorClaw(0.0);
	}


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
