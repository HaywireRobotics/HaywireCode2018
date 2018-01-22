/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include "Commands/TeleopCommand.h"
#include <WPILib.h>


OI::OI()
{
	// Process operator interface input here.

	 joystickManipulator.reset(new frc::Joystick(2));
	 joystickRight.reset(new frc::Joystick(1));
	 joystickLeft.reset(new frc::Joystick(0));

	 btnPushPiston = new frc::JoystickButton(joystickManipulator.get(), 1);
	 btnPullPiston = new frc::JoystickButton(joystickManipulator.get(), 2);
}

	std::shared_ptr<frc::Joystick> OI::getJoystickRight()
	{
	    return joystickRight;
	}

	 std::shared_ptr<frc::Joystick> OI::getJoystickLeft()
	 {
	    return joystickLeft;
	 }

	 std::shared_ptr<frc::Joystick> OI::getJoystickManipulator()
	 {
	    return joystickManipulator;
	 }

	 JoystickButton* OI::getbtnPushPiston() {
		 return btnPushPiston;
	 }

	 JoystickButton* OI::getbtnPullPiston() {
		 return btnPullPiston;
	 }
