/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/

#include "Robot.h"
#include <CameraServer.h>
#include <Joystick.h>

std::shared_ptr<PneumaticsSubsystem> Robot::pneumaticsSubsystem = std::make_unique<PneumaticsSubsystem>();
std::shared_ptr<DriveTrainSubsystem> Robot::driveTrainSubsystem = std::make_unique<DriveTrainSubsystem>();
std::shared_ptr<ElevatorSubsystem> Robot::elevatorSubsystem = std::make_unique<ElevatorSubsystem>();
std::unique_ptr<OI> Robot::oi;

	void Robot::RobotInit() {
		m_chooser.AddDefault("Drive Across Line", &m_autoDriveAcrossLine);
		m_chooser.AddObject("My Auto", &m_myAuto);
		m_chooser.AddObject("Push Piston", &m_pushPiston);
		m_chooser.AddObject("Drive Across Line", &m_autoDriveAcrossLine);
		m_chooser.AddObject("Score switch points CL", &m_autoGetPowerSwitchCL);

		w_chooser.AddObject("Switch", w_chooseSwitch);

		frc::SmartDashboard::PutData("PushPiston", new PushPiston());
		frc::SmartDashboard::PutData("PullPiston", new PullPiston());
		frc::SmartDashboard::PutData("DriveForward", new DriveForward(10.0));
		frc::SmartDashboard::PutData("Switch Height", new SwitchHeightCommand());
		frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
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
	void Robot::DisabledInit() {}

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
		m_autonomousCommand = m_chooser.GetSelected();

		if (m_autonomousCommand != nullptr) {
			m_autonomousCommand->Start();
		}
//		AddSequential(m_pushPiston);
	}

	void Robot::AutonomousPeriodic() {
		frc::Scheduler::GetInstance()->Run();
	}

	void Robot::TeleopInit() {
		// This makes sure that the autonomous stops running when
		// teleop starts running. If you want the autonomous to
		// continue until interrupted by another command, remove
		// this line or comment it out.
		if (m_autonomousCommand != nullptr) {
			m_autonomousCommand->Cancel();
			m_autonomousCommand = nullptr;
		}
	}

	void Robot::TeleopPeriodic() {
		frc::SmartDashboard::PutNumber(llvm::StringRef("Counter Amount"), Robot::elevatorSubsystem.get()->counter->Get());
		frc::Scheduler::GetInstance()->Run();
	}

	void Robot::TestInit() {

	}

	void Robot::TestPeriodic() {
		//lw->Run();
	}

	// Have it null by default so that if testing teleop it
	// doesn't have undefined behavior and potentially crash.



START_ROBOT_CLASS(Robot)
