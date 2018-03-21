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

	 this->camera = frc::CameraServer::GetInstance()->StartAutomaticCapture();
	 this->camera1 = frc::CameraServer::GetInstance()->StartAutomaticCapture();

	 	//table = NetworkTable::GetTable("CameraVision/");

	 this->camera.SetResolution(640, 480);
//	 this->camera.SetResolution(320, 240);
	 this->camera.SetFPS(15);
//	 this->camera.SetExposureManual(3.0);
//	 this->camera.SetExposureManual(40.0);
	 this->camera.SetExposureAuto();

	 this->camera1.SetResolution(640, 480);
	 this->camera1.SetFPS(15);
	 this->camera1.SetExposureAuto();


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


	 void OI::SetCameraAuto() {
	 	this->camera.SetExposureManual(3.0);
	 }

	 void OI::SetCameraTeleop() {
	 	this->camera.SetExposureManual(40.0);
	 	this->camera.SetExposureAuto();
	 }

	 void OI::GetNetworkTable() {
	 	//return this->table;
	 }

	 std::vector<double> OI::GetCenterX() {
	 	return table->GetNumberArray("centerX", llvm::ArrayRef<double>()); //std::vector<double> centerX = table->GetNumberArray("centerX", llvm::ArrayRef<double>());
	 }
