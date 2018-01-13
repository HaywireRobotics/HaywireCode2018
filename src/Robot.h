#include <Commands/Command.h>
#include <Commands/Scheduler.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <TimedRobot.h>

#include "Commands/ExampleCommand.h"
#include "Commands/MyAutoCommand.h"
#include "Commands/PushPiston.h"
#include "Subsystems/PneumaticsSubsystem.h"
#include <CameraServer.h>

class Robot: public frc::TimedRobot {
public:
//	static std::unique_ptr<OI>oi;
	static std::shared_ptr<PneumaticsSubsystem> pneumaticsSubsystem;

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
	frc::SendableChooser<frc::Command*> m_chooser;
};
