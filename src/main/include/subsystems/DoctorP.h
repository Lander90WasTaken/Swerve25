#include <frc2/command/SubsystemBase.h>
#include <networktables/NetworkTableInstance.h>
#include <networktables/NetworkTable.h>
#include <networktables/DoubleTopic.h>
#include <vector>


class DoctorP : public frc2::SubsystemBase {
    public:
     DoctorP();

     double GetX();

     double GetY();

     void TeleopPeriodic();



private:
    nt::NetworkTableInstance DoctorPInst= nt::NetworkTableInstance::Create();
    //inst may be subject to change as Mr.Baker Jr sees fit.
    nt::DoubleSubscriber ySub;
    nt::DoubleSubscriber xSub;
    double xVal;
    double yVal;
};