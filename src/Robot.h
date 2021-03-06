 #ifndef Robot_h
#define Robot_h
#include <Commands/CloseClaw.h>
#include <TimedRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Commands/Command.h>
#include <Commands/DriveToSwitchLeft.h>
#include <Commands/OpenClaw.h>
#include <Commands/Scheduler.h>
#include "Commands/ExampleCommand.h"
#include "Commands/MyAutoCommand.h"
#include "Commands/SwitchHeightCommand.h"
#include "Commands/DriveForward.h"
#include "Commands/autoDriveAcrossLine.h"
#include "Commands/DriveRightTurn.h"
#include "Commands/DriveLeftTurn.h"
#include "Commands/DriveToSwitchRight.h"
#include "Commands/DriveToSwitchCenter.h"
#include "Commands/DriveToScaleRight.h"
#include "Commands/DriveToScaleLeft.h"
#include "Subsystems/PneumaticsSubsystem.h"
#include "Subsystems/DriveTrainSubsystem.h"
#include "Subsystems/ElevatorSubsystem.h"
#include "Subsystems/ClimbySubsystem.h"
#include "Subsystems/CameraSubsystem.h"
#include "Subsystems/ClawSubsystem.h"
#include "OI.h"
#include "autoChoosers/ChooseSwitch.h"
#include "autoChoosers/autoChooserBase.h"



class Robot: public frc::TimedRobot {
public:
	static std::shared_ptr<PneumaticsSubsystem> pneumaticsSubsystem;
	static std::shared_ptr<DriveTrainSubsystem> driveTrainSubsystem;
	static std::shared_ptr<ElevatorSubsystem> elevatorSubsystem;
	static std::shared_ptr<ClimbySubsystem> climbySubsystem;
	static std::shared_ptr<CameraSubsystem> cameraSubsytem;
	static std::shared_ptr<ClawSubsystem> clawSubsystem;
	static std::unique_ptr<OI> oi;
//	static std::shared_ptr<NetworkTable> cameraVisionTable;
	frc::LiveWindow* lw = frc::LiveWindow::GetInstance();
	//static std::string gameData;
	void RobotInit() override;
	void RobotPeriodic() override;
	void DisabledInit() override;
	void DisabledPeriodic() override;
	void AutonomousInit() override;
	void AutonomousPeriodic() override;
	void TeleopInit() override;
	void TeleopPeriodic() override;
	void TestInit() override;
	void TestPeriodic() override;

private:
	frc::CommandGroup* a_autonomousCommand = nullptr;
	int a_autonomousSelect = 0;
	ExampleCommand m_defaultAuto;
	MyAutoCommand m_myAuto;
	CloseClaw m_pushPiston;
	OpenClaw m_pullPiston;
	frc::SendableChooser<int> a_chooser;

	ChooseSwitch w_chooseSwitch;
	frc::SendableChooser<autoChooserBase> w_chooser;
};

#endif
