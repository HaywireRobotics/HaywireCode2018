#include <CameraServer.h>
#include "CameraSubsystem.h"
#include "../RobotMap.h"

CameraSubsystem::CameraSubsystem() : Subsystem("ExampleSubsystem") {


	//this->camera1.SetResolution(320, 240);
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

std::vector<double> CameraSubsystem::GetCenterX() {
	return table->GetNumberArray("centerX", llvm::ArrayRef<double>()); //std::vector<double> centerX = table->GetNumberArray("centerX", llvm::ArrayRef<double>());
}
