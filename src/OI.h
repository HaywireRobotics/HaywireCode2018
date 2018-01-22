/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#pragma once
#include <WPILib.h>
#include <Joystick.h>

class OI {
private:
	std::shared_ptr<frc::Joystick> joystickManipulator;
	std::shared_ptr<frc::Joystick> joystickRight;
	std::shared_ptr<frc::Joystick> joystickLeft;


	//std::shared_ptr<frc::JoystickButton> btnPushPiston;
	//std::shared_ptr<frc::JoystickButton> btnPullPiston;
	JoystickButton* btnPushPiston;// = new JoystickButton(joystickManipulator,1);
	JoystickButton* btnPullPiston;// = new JoystickButton(joystickManipulator,2);
public:
	OI();
	std::shared_ptr<frc::Joystick> getJoystickRight();
	std::shared_ptr<frc::Joystick> getJoystickLeft();
	std::shared_ptr<frc::Joystick> getJoystickManipulator();
};
