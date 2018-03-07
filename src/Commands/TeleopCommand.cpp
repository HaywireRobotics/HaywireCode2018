#include <Commands/CloseClaw.h>
#include <Commands/OpenClaw.h>
#include "TeleopCommand.h"
#include "../Robot.h"
#include "../RobotMap.h"
#include "../Subsystems/DriveTrainSubsystem.h"
#include "../OI.h"
#include "../Enums.h"
#include <iostream>


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

	//Tank Drive
	Robot::driveTrainSubsystem->takeJoystickInputs((Robot::oi->getJoystickRight().get()),(Robot::oi->getJoystickLeft().get()));

	//Lifting The Lift
	if (Robot::elevatorSubsystem.get()->movingToPosition == false)
	{
		Robot::elevatorSubsystem.get()->ElevatorSet(Robot::oi->getJoystickManipulator2().get()->GetY());
	}

	//Claw Open/Close Buttons
	if (Robot::oi->getJoystickManipulator().get()->GetRawButton(JMExtendPistonNum))
	{
		switch(Robot::driveTrainSubsystem.get()->GetRobotType()) {
			case competition:
				Robot::pneumaticsSubsystem.get()->SetSole1Open();
				break;
			case practice:
				Robot::pneumaticsSubsystem.get()->SetSole1Close();
				break;
		}
	}
	else if (Robot::oi->getJoystickManipulator().get()->GetRawButton(JMRetractPistonNum))
	{
		switch(Robot::driveTrainSubsystem.get()->GetRobotType()) {
			case competition:
				Robot::pneumaticsSubsystem.get()->SetSole1Close();
				break;
			case practice:
				Robot::pneumaticsSubsystem.get()->SetSole1Open();
				break;
		}
	}

	//Tape Buttons
	if (Robot::oi->getJoystickManipulator().get()->GetRawButton(JMTapeOut))
	{
			Robot::climbySubsystem.get()->TapeControl(0.55);
	}
	else if (Robot::oi->getJoystickManipulator().get()->GetRawButton(JMTapeIn))
	{
			Robot::climbySubsystem.get()->TapeControl(-0.55);
	}
	else
	{
		Robot::climbySubsystem.get()->TapeControl(0.0);
	}


	//Winch Control
	if (Robot::oi->getJoystickManipulator().get()->GetRawButton(JMWinchIn))
	{
			Robot::climbySubsystem.get()->WinchControl(1.0);
	}
	else if (Robot::oi->getJoystickManipulator().get()->GetRawButton(JMWinchOut))
	{
				Robot::climbySubsystem.get()->WinchControl(-1.0);
	}
	else
	{
		Robot::climbySubsystem.get()->WinchControl(0.0);
	}

	//Claw Pivot Controls
	if (Robot::oi->getJoystickManipulator().get()->GetRawButton(JMClawRotatePos)) {
		Robot::elevatorSubsystem.get()->ElevatorClaw(0.4);
	}
	else if (Robot::oi->getJoystickManipulator().get()->GetRawButton(JMClawRotateNeg)) {
		Robot::elevatorSubsystem.get()->ElevatorClaw(-0.4);
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
