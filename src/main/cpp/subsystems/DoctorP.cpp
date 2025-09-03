#include <frc2/command/SubsystemBase.h>
#include <subsystems/DoctorP.h>

DoctorP::DoctorP(){
        DoctorPInst.StartClient4("robot");
        // connect to a roboRIO with team number 3267
        DoctorPInst.SetServerTeam(3267);
        // starting a DS client will try to get the roboRIO address from the DS application
        DoctorPInst.StartDSClient();
        // connect to a specific host/port (may need to be tweaked).
        DoctorPInst.SetServer("host", NT_DEFAULT_PORT4);
}

void DoctorP::TeleopPeriodic(){
    auto table = DoctorPInst.GetTable("Very Awesome Table");
    xVal = table->GetValue("X");
    //Gets X and Y values from Very Awesome Table (name and values may need to be tweaked).
    auto table = DoctorPInst.GetTable("Very Awesome Table");
    yVal = table->GetValue("Y");
}

void DoctorP::GetX(){
    auto table = DoctorPInst.GetTable("Very Awesome Table");
    yVal = table->GetValue("X");
}

void DoctorP::GetY(){
    auto table = DoctorPInst.GetTable("Very Awesome Table");
    yVal = table->GetValue("Y");
    
}