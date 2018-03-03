#include <CameraServer.h>
#include "CameraSubsystem.h"
#include "../RobotMap.h"

CameraSubsystem::CameraSubsystem() : Subsystem("ExampleSubsystem") {

	this->camera = frc::CameraServer::GetInstance()->StartAutomaticCapture();
	this->camera1 = frc::CameraServer::GetInstance()->StartAutomaticCapture();

	table = NetworkTable::GetTable("CameraVision/");

	this->camera.SetResolution(320, 240);
	this->camera.SetFPS(30);
	this->camera1.SetResolution(320, 240);
}

void CameraSubsystem::InitDefaultCommand() {
	// Set the default command for a subsystem here.
	// SetDefaultCommand(new MySpecialCommand());
}

// Put methods for controlling this subsystem
// here. Call these from Commands.


void CameraSubsystem::SetCameraAuto() {
	this->camera.SetExposureManual(3.0);
}

void CameraSubsystem::SetCameraTeleop() {
	this->camera.SetExposureManual(40.0);
	this->camera.SetExposureAuto();
}

void CameraSubsystem::GetNetworkTable() {
	//return this->table;
}
