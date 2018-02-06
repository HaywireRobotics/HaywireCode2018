/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "OI.h"
#include "RobotMap.h"
#include "Commands/TeleopCommand.h"
#include <WPILib.h>


OI::OI()
{
	// Process operator interface input here.

	 joystickManipulator.reset(new frc::Joystick(JoystickManipulatorPort));
	 joystickRight.reset(new frc::Joystick(JoystickRightPort));
	 joystickLeft.reset(new frc::Joystick(JoystickLeftPort));
	 joystickManipulator2.reset(new frc::Joystick(JoystickManipulator2Port));
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

	 std::shared_ptr<frc::Joystick> OI::getJoystickManipulator2()
	 {
		 return joystickManipulator2;
	 }
