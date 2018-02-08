#ifndef CameraSubsystem_H
#define CameraSubsystem_H

#include <Commands/Subsystem.h>

class CameraSubsystem : public frc::Subsystem {
private:
	// It's desirable that everything possible under private except
	// for methods that implement subsystem capabilities
	std::shared_ptr<NetworkTable> table;
	std::shared_ptr<NetworkTable> table1;
	cs::UsbCamera camera;
	cs::UsbCamera camera1;

public:
	CameraSubsystem();
	void InitDefaultCommand();
	void SetCameraTeleop();
	void SetCameraAuto();
};

#endif  // CameraSubsystem_H
