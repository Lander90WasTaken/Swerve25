#include <frc2/command/SubsystemBase.h>
#include <networktables/NetworkTableInstance.h>
#include <networktables/NetworkTable.h>
#include <networktables/DoubleTopic.h>


class DoctorP : public frc2::SubsystemBase {
    public:
     DoctorP();

     double GetX();

     double GetY();

     int ActiveAprilTag();

     void TeleopPeriodic();


private:
    nt::NetworkTableInstance DoctorPInst = nt::NetworkTableInstance::Create();
    //inst may be subject to change as Mr.Baker Jr sees fit.

    double xVal;
    double yVal;

    nt::DoubleSubscriber ySub;
    nt::DoubleSubscriber xSub;

};