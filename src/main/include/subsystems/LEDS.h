
#include <frc2/command/SubsystemBase.h>
#include <frc/PWM.h>


class LEDs : public frc2::SubsystemBase {
    public:
     LEDs();

     void TeleopPeriodic();

    //void SetLED(bool value);
    
     void setLEDColor(int redValue, int greenValue, int blueValue);
    //void TurnOffLED();
    //bool areTheyOn();


private:
    frc::PWM m_ledRed{3}; // PWM pin 1
    frc::PWM m_ledGreen{4}; // PWM pin 1
    frc::PWM m_ledBlue{5}; // PWM pin 1
    bool areTheyOnBro;
};