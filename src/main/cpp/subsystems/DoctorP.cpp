#include <frc2/command/SubsystemBase.h>
#include <subsystems/DoctorP.h>

DoctorP::DoctorP(){
        DoctorPInst.StartClient4("robot");
        // connect to a specific host/port (may need to be tweaked).
        DoctorPInst.SetServer("host", NT_DEFAULT_PORT4);

        auto table = DoctorPInst.GetTable("main/DoctorP");
        //Gets X and Y values from Very Awesome Table (name and values may need to be tweaked).
        xSub = table->GetDoubleTopic("X").Subscribe(0.0);
        ySub = table->GetDoubleTopic("Y").Subscribe(0.0);

}

void DoctorP::TeleopPeriodic(){
    xVal = xSub.Get();
    yVal = ySub.Get();
}

  

double DoctorP::GetX(){
    return xVal;
}

double DoctorP::GetY(){
    return yVal;  
}