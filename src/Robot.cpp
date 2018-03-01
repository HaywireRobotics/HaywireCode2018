/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include "Enums.h"
#include <CameraServer.h>
#include <Joystick.h>
#include <iostream>

RobotType robotType = practice;

std::shared_ptr<PneumaticsSubsystem> Robot::pneumaticsSubsystem = std::make_unique<PneumaticsSubsystem>();
std::shared_ptr<DriveTrainSubsystem> Robot::driveTrainSubsystem = std::make_unique<DriveTrainSubsystem>(robotType);
std::shared_ptr<ElevatorSubsystem> Robot::elevatorSubsystem = std::make_unique<ElevatorSubsystem>();
std::shared_ptr<ClimbySubsystem> Robot::climbySubsystem = std::make_unique<ClimbySubsystem>();
std::unique_ptr<OI> Robot::oi;

	void Robot::RobotInit() {
		//m_chooser.AddObject("My Auto", &m_myAuto);
		a_chooser.AddObject("DriveAcrossLine",0);
		a_chooser.AddObject("DriveSwitch", 1);



		//w_chooser.AddDefault("Switch", w_chooseSwitch);
		w_chooser.AddObject("Switch", w_chooseSwitch);

		frc::SmartDashboard::PutData("PushPiston", new PushPiston());
		frc::SmartDashboard::PutData("PullPiston", new PullPiston());
		frc::SmartDashboard::PutData("DriveForward", new DriveForward(2.0));
		frc::SmartDashboard::PutData("Drive Across Line", new autoDriveAcrossLine());
		frc::SmartDashboard::PutData("Switch Height", new SwitchHeightCommand());
		frc::SmartDashboard::PutData("Right DriveTurn", new DriveRightTurn(100.0));
		frc::SmartDashboard::PutData("Left DriveTurn", new DriveLeftTurn(-100.0));
		//frc::SmartDashboard::PutData("Command Modes", &m_chooser);
		frc::SmartDashboard::PutData("Auto Modes", &a_chooser);
		//frc::SmartDashboard::PutData("Angle", Robot::driveTrainSubsystem->gyro);
		frc::CameraServer::GetInstance()->StartAutomaticCapture();
		oi.reset(new OI());
	}

	/**
	 * This function is called once each time the robot enters Disabled
	 * mode.
	 * You can use it to reset any subsystem information you want to clear
	 * when
	 * the robot is disabled.
	 */
	void Robot::DisabledInit() {
		//this function is currently useless
	}

	void Robot::DisabledPeriodic() {
		frc::Scheduler::GetInstance()->Run();
	}

	/**
	 * This autonomous (along with the chooser code above) shows how to
	 * select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString code to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional commands to
	 * the
	 * chooser code above (like the commented example) or additional
	 * comparisons
	 * to the if-else structure below with additional strings & commands.
	 */
	void Robot::AutonomousInit() {
//		std::string autoSelected = frc::SmartDashboard::GetString(
//				"Auto Select;or", "Default");
//		if (autoSelected == "My Auto") {
//			m_autonomousCommand = &m_myAuto;
//		} else if (autoSelected == "PushPiston") {
//			m_autonomousCommand = &m_pushPiston;
//		}
//		else {
//			m_autonomousCommand = &m_defaultAuto;
//		}
		//this->gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();

		//m_autonomousCommand = m_chooser.GetSelected();

		std::string gameData;
		gameData = frc::DriverStation::GetInstance().GetGameSpecificMessage();
		a_autonomousSelect = a_chooser.GetSelected();

		switch (a_autonomousSelect)
		{
			case 0:
				a_autonomousCommand = new autoDriveAcrossLine();
				break;
			case 1:
				a_autonomousCommand = new DriveToSwitch(gameData);
				break;
		}
		if(a_autonomousCommand != nullptr)
	    {
	  		a_autonomousCommand->Start();
	    }
	}

	void Robot::AutonomousPeriodic() {
		frc::Scheduler::GetInstance()->Run();
	}

	void Robot::TeleopInit() {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interruted by another command, remove
		// this line or comment it out.
		if (a_autonomousCommand != nullptr) {
			a_autonomousCommand->Cancel();
			a_autonomousCommand = nullptr;
		}
	}

	void Robot::TeleopPeriodic() {
		frc::SmartDashboard::PutNumber(llvm::StringRef("Counter Amount"), Robot::elevatorSubsystem.get()->counter->Get());
		frc::SmartDashboard::PutNumber(llvm::StringRef("Angle"), Robot::driveTrainSubsystem.get()->GetGyroValue());
		frc::Scheduler::GetInstance()->Run();
	}

	void Robot::TestInit() {

	}

	void Robot::TestPeriodic() {
	}

	// Have it null by default so that if testing teleop it
	// doesn't have undefined behavior and potentially crash.



START_ROBOT_CLASS(Robot)
//
//This is a useless comment
//with lots of space
//
//
