#include <frc2/command/SubsystemBase.h>
#include <networktables/NetworkTableInstance.h>
#include <networktables/NetworkTable.h>


class DoctorP : public frc2::SubsystemBase {
    public:
     DoctorP();

     void GetX();

     void GetY();

     void TeleopPeriodic();



private:
    nt::NetworkTableInstance DoctorPInst= nt::NetworkTableInstance::Create();
    //inst may be subject to change as Mr.Baker Jr sees fit.
    
    nt::Value xVal;
    nt::Value yVal;
};