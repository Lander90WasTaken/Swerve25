#include <subsystems/LEDs.h>
#include <units/time.h>

LEDs::LEDs(){
        //m_led.Set(0);
        //areTheyOnBro = false; // Turn off the LED initially
}

void LEDs::TeleopPeriodic(){

}

void LEDs::setLEDColor(int redValue, int greenValue, int blueValue) {
        if(redValue <= 255 && greenValue <= 255 && blueValue <= 255){
                m_ledRed.SetPulseTime(units::microsecond_t{(double)(255-redValue)}); //Inverts the color so the MOSFETs can allow the PWM signal to the lights.
                m_ledGreen.SetPulseTime(units::microsecond_t{(double)(255-greenValue)}); //SetPulseTime may not be correct function and will need to be tested and likely changed.
                m_ledBlue.SetPulseTime(units::microsecond_t{(double)(255-blueValue)});
        } else{
                m_ledRed.SetPulseTime(units::microsecond_t{255});
                m_ledGreen.SetPulseTime(units::microsecond_t{0});
                m_ledBlue.SetPulseTime(units::microsecond_t{0});
        }
}
/*void LEDs::TurnOnLED(bool value){
        m_led.Set(value);
        areTheyOnBro = true; // Turn on the LED
}

bool LEDs::areTheyOn(){
        return areTheyOnBro;
}*/