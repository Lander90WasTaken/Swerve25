
#include <frc2/command/SubsystemBase.h>
#include <frc/digitalOutput.h>


class LEDS : public frc2::SubsystemBase {
    public:
     LEDS();

    void TeleopPeriodic();

    //void SetLED(bool value);
    void setLEDColor(int redValue, int greenValue, int blueValue);
    //void TurnOffLED();
    //bool areTheyOn();


private:
    frc::DigitalOutput m_ledRed{3}; // PWM pin 1
    frc::DigitalOutput m_ledGreen{4}; // PWM pin 1
    frc::DigitalOutput m_ledBlue{5}; // PWM pin 1
    bool areTheyOnBro;
};