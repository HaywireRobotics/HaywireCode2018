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
#include "Subsystems/ClimbySubsystem.h"
#include "OI.h"
#include "autoChoosers/ChooseSwitch.h"
#include "autoChoosers/autoChooserBase.h"



class Robot: public frc::TimedRobot {
public:
	static std::shared_ptr<PneumaticsSubsystem> pneumaticsSubsystem;
	static std::shared_ptr<DriveTrainSubsystem> driveTrainSubsystem;
	static std::shared_ptr<ElevatorSubsystem> elevatorSubsystem;
	static std::shared_ptr<ClimbySubsystem> climbySubsystem;
	static std::unique_ptr<OI> oi;
	frc::LiveWindow* lw = frc::LiveWindow::GetInstance();
	//static std::string gameData;
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
	frc::CommandGroup* a_autonomousCommand = nullptr;
	ExampleCommand m_defaultAuto;
	MyAutoCommand m_myAuto;
	PushPiston m_pushPiston;
	PullPiston m_pullPiston;
	autoDriveAcrossLine a_autoDriveAcrossLine;
	autoGetPowerSwitchCL a_autoGetPowerSwitchCL;
	frc::SendableChooser<frc::Command*> m_chooser;
	frc::SendableChooser<frc::CommandGroup*> a_chooser;

	ChooseSwitch w_chooseSwitch;
	frc::SendableChooser<autoChooserBase> w_chooser;
};

#endif
