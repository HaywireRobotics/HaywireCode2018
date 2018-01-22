/*----------------------------------------------------------------------------*/
/* Copyright (c) 2017-2018 FIRST. All Rights Reserved.                        */
/* Open Source Software - may be modified and shared by FRC teams. The code   */
/* must be accompanied by the FIRST BSD license file in the root directory of */
/* the project.                                                               */
/*----------------------------------------------------------------------------*/
/*
#include <iostream>
#include <string>

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <VictorSP.h>
#include <Spark.h>
#include <Timer.h>
#include <Compressor.h>
#include <Solenoid.h>
#include <Commands/WaitCommand.h>

class Robot : public frc::IterativeRobot {
public:
	frc::Spark motor0 { 0 };
	frc::VictorSP motor1 { 1 };
	void RobotInit() {
		m_chooser.AddDefault(kAutoNameDefault, kAutoNameDefault);
		m_chooser.AddObject(kAutoNameCustom, kAutoNameCustom);
		frc::SmartDashboard::PutData("Auto Modes", &m_chooser);
	}

	*
	 * This autonomous (along with the chooser code above) shows how to
	 * select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString line to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional comparisons to
	 * the
	 * if-else structure below with additional strings. If using the
	 * SendableChooser make sure to add them to the chooser code above as
	 * well.
	 *
	void AutonomousInit() override {
//		m_autoSelected = m_chooser.GetSelected();
//		// m_autoSelected = SmartDashboard::GetString(
//		// 		"Auto Selector", kAutoNameDefault);
//		std::cout << "Auto selected: " << m_autoSelected << std::endl;
//
//		if (m_autoSelected == kAutoNameCustom) {
//			// Custom Auto goes here
//		} else {
//			// Default Auto goes here
//		}

		Compressor *c = new Compressor(0);
		c->SetClosedLoopControl(true);

		Solenoid *solo0 = new Solenoid(0);
		Solenoid *solo1 = new Solenoid(1);

		solo0->Set(true);
		frc::Wait(10.0);
		solo0->Set(false);
		solo1->Set(true);
		frc::Wait(10.0);
		solo1->Set(false);



//		motor0.SetSpeed(0.5);
//	    motor1.SetSpeed(0.1);
//		frc::Wait(3.0);
//		motor0.SetSpeed(0.0);
//		motor1.SetSpeed(0.0);


	}

	void AutonomousPeriodic() {
		if (m_autoSelected == kAutoNameCustom) {
			// Custom Auto goes here
		} else {
			// Default Auto goes here
		}
	}

	void TeleopInit() {}

	void TeleopPeriodic() {}

	void TestPeriodic() {}

private:
	frc::LiveWindow& m_lw = *LiveWindow::GetInstance();
	frc::SendableChooser<std::string> m_chooser;
	const std::string kAutoNameDefault = "Default";
	const std::string kAutoNameCustom = "My Auto";
	std::string m_autoSelected;
};

START_ROBOT_CLASS(Robot)
*/
