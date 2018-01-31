#ifndef Robot_h
#define Robot_h
#include <TimedRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include "Commands/ExampleCommand.h"
#include "Commands/MyAutoCommand.h"
#include "Commands/PushPiston.h"
#include "Commands/PullPiston.h"
#include "Commands/SwitchHeightCommand.h"
#include "Commands/DriveForward.h"
#include "Commands/autoDriveAcrossLine.h"
#include "Commands/autoGetPowerSwitchCL.h"
#include "Subsystems/PneumaticsSubsystem.h"
#include "Subsystems/DriveTrainSubsystem.h"
#include "Subsystems/ElevatorSubsystem.h"
#include "OI.h"



class Robot: public frc::TimedRobot {
public:
	static std::shared_ptr<PneumaticsSubsystem> pneumaticsSubsystem;
	static std::shared_ptr<DriveTrainSubsystem> driveTrainSubsystem;
	static std::shared_ptr<ElevatorSubsystem> elevatorSubsystem;
	static std::unique_ptr<OI> oi;
	frc::LiveWindow* lw = frc::LiveWindow::GetInstance();
	void RobotInit() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestInit() override;
	void TestPeriodic() override;

private:
	frc::Command* m_autonomousCommand = nullptr;
	ExampleCommand m_defaultAuto;
	MyAutoCommand m_myAuto;
	PushPiston m_pushPiston;
	PullPiston m_pullPiston;
	autoDriveAcrossLine m_autoDriveAcrossLine;
	autoGetPowerSwitchCL m_autoGetPowerSwitchCL;
	frc::SendableChooser<frc::Command*> m_chooser;
};

#endif
