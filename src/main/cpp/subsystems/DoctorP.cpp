#include <frc2/command/SubsystemBase.h>
#include <subsystems/DoctorP.h>
#include <frc/smartdashboard/SmartDashboard.h>

DoctorP::DoctorP(){
        DoctorPInst.StartClient4("robot");
        // connect to a specific host/port (may need to be tweaked).
        DoctorPInst.SetServer("host", NT_DEFAULT_PORT4);

        auto table = DoctorPInst.GetTable("main/DoctorP");
        //Gets X and Y values from Very Awesome Table (name and values may need to be tweaked).
        xSub = table->GetDoubleTopic("X").Subscribe(0.0);
        ySub = table->GetDoubleTopic("Y").Subscribe(0.0);
        aprilTagSub = table->GetDoubleTopic("AprilTag").Subscribe(0.0);
}

void DoctorP::TeleopPeriodic(){

}

  

double DoctorP::GetX(){ 
    return xSub.Get(32.67);
}

double DoctorP::GetY(){
    return ySub.Get(32.67);  
}

int DoctorP::ActiveAprilTag(){
    return int(aprilTagSub.Get(32.67));
}