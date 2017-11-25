#include <iostream>
#include <memory>
#include <string>

#include <IterativeRobot.h>
#include <LiveWindow/LiveWindow.h>
#include <SmartDashboard/SendableChooser.h>
#include <SmartDashboard/SmartDashboard.h>
#include <Timer.h>
#include <Spark.h>
#include <Talon.h>
#include <VictorSP.h>
#include <CameraServer.h>
#include <RobotDrive.h>
#include <Joystick.h>
#include <ADXRS450_Gyro.h>

class Robot: public frc::IterativeRobot {
	frc::Joystick stickLeft { 0 };
	frc::Joystick stickRight { 1 };
	frc::Joystick stickRoller { 2 };
	frc::Spark roller { 8 };
	frc::Talon gear { 7 };
	frc::VictorSP victorRF { 0 };
	frc::VictorSP victorRB { 1 };
	frc::VictorSP victorLF { 2 };
	frc::VictorSP victorLB { 3 };
	frc::RobotDrive myRobot { victorRF, victorRB, victorLF, victorLB }; // robot drive system
	frc::ADXRS450_Gyro gyro { frc::SPI::Port::kOnboardCS0 };


public:
	std::shared_ptr<NetworkTable> table;
	void RobotInit() {
		table = NetworkTable::GetTable("GRIP/myContoursReport");
		frc::CameraServer::GetInstance()->StartAutomaticCapture();
		//chooser.AddDefault(autoNameDefault, autoNameDefault);
		//chooser.AddObject(autoNameCustom, autoNameCustom);
		//frc::SmartDashboard::PutData("Auto Modes", &chooser);
		myRobot.SetExpiration(0.1);
	}

	/*
	 * This autonomous (along with the chooser code above) shows how to select
	 * between different autonomous modes using the dashboard. The sendable
	 * chooser code works with the Java SmartDashboard. If you prefer the
	 * LabVIEW Dashboard, remove all of the chooser code and uncomment the
	 * GetString line to get the auto name from the text box below the Gyro.
	 *
	 * You can add additional auto modes by adding additional comparisons to the
	 * if-else structure below with additional strings. If using the
	 * SendableChooser make sure to add them to the chooser code above as well.
	 */
	void AutonomousInit() override {
		//autoSelected = chooser.GetSelected();
		std::string autoSelected = SmartDashboard::GetString("Auto Selector",
				autoNameDefault);
		std::cout << "Auto selected: " << autoSelected << std::endl;
		static const float kP = 0.03;


		if (autoSelected == autoNameCustom)
		{
			// Custom Auto goes here
			std::cout << "Running custom Autonomous" << std::endl;
			myRobot.SetSafetyEnabled(false);
			float angle = gyro.GetAngle(); // get heading
			myRobot.Drive(-0.5, -angle * kP); // turn to correct heading
			frc::Wait(0.5);                // for 2 seconds
			myRobot.Drive(0.0, 0.0);  // stop robot
		}

		else if(SmartDashboard::GetNumber("DB/Slider 2",0)==1)
		{
			myRobot.SetSafetyEnabled(false);
			float angle = gyro.GetAngle(); // get heading
			myRobot.Drive(-0.5, -angle * kP); // turn to correct heading
			frc::Wait(5.0);                // for 2 seconds
			myRobot.Drive(0.0, 0.0);  // stop robot
		}

		else
		{
			// Default Auto goes here
			std::cout << "Running default Autonomous" << std::endl;
			myRobot.SetSafetyEnabled(false);
			float angle = gyro.GetAngle(); // get heading
			myRobot.Drive(-0.5, -angle * kP); // turn to correct heading
			frc::Wait(2.0);                // for 2 seconds
			myRobot.Drive(0.0, 0.0);  // stop robot
		}
	}

	void AutonomousPeriodic()
	{
		if (autoSelected == autoNameCustom)
		{
			// Custom Auto goes here
		}
		else
		{

		}
	}

	void TeleopInit()
	{
		myRobot.SetSafetyEnabled(true);
	}

	void TeleopPeriodic()
	{
		float rolStickY = 0.0;
		float rollerspeed = 0.0;
	    float gearspeed = 0.0;
	    float rolStickX = 0.0;
		rolStickY=stickRoller.GetY();
		rolStickX=stickRoller.GetX();

		std::vector<double> arr = table->GetNumberArray("area",
				llvm::ArrayRef<double>());

		std::vector<double> centerX = table->GetNumberArray("centerX",llvm::ArrayRef<double>());



		/*for (unsigned int i = 0; i < arr.size(); i++)
		 {
		 std::cout << arr[i] << " ";
		 }
		 std::cout << std::endl;
		 */

		gyro.GetAngle();



		if(centerX.size())//if there is a value in array centerX
		{
			//display value in position 0 of array centerX
			PrintStringToDashboard("DB/String 1", "Center X: ", centerX[0]);
		}
		else//if there is no value
		{
			//display negative one instead
			PrintStringToDashboard("DB/String 1", "Center X: ", -1);
		}

		//display size of array Areas
		PrintStringToDashboard("DB/String 0", "Areas: ", arr.size());



		// drive with tank drive (use right stick)
		myRobot.TankDrive(stickLeft, stickRight);

		// wait for a motor update time

		if (stickRoller.GetRawButton(2))
		{
			gearspeed = 0.3;
		}
		else if((rolStickY > 0.05) || (rolStickY < -0.05))
		{

			if (rolStickY < 0)
			{
				rollerspeed=rolStickY*0.4;
			}

			else
			{
				rollerspeed=rolStickY*0.8;
		    }

		}
		else
		{
			rollerspeed = 0;
		}

		roller.Set(rollerspeed);
		gear.Set(gearspeed);
	}

	void TestPeriodic() {
		lw->Run();
	}

	void PrintStringToDashboard(std::string field, std::string label, float numValue)
	{
				std::stringstream oStream;
				oStream<<numValue;
				std::string bufferString = label + oStream.str();
				SmartDashboard::PutString(field, bufferString);
	}

private:
	frc::LiveWindow* lw = LiveWindow::GetInstance();
	frc::SendableChooser<std::string> chooser;
	const std::string autoNameDefault = "Default";
	const std::string autoNameCustom = "My Auto";
	std::string autoSelected;
};

START_ROBOT_CLASS(Robot)
