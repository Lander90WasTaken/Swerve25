#include <subsystems/LEDS.h>

LEDS::LEDS(){
        ..m_led.Set(0);
        //areTheyOnBro = false; // Turn off the LED initially
}

void LEDS::TeleopPeriodic(){

}

void LEDS::SetLEDColor(int redValue, int greenValue, int blueValue) {
        if(redValue <= 255 && greenValue <= 255 && blueValue <= 255){
                m_ledRed.SetPulseTime(255-redValue); //Inverts the color so the MOSFETs can allow the PWM signal to the lights.
                m_ledGreen.SetPulseTime(255-greenValue); //SetPulseTime may not be correct function and will need to be tested and likely changed.
                m_ledBlue.SetPulseTime(255-blueValue);
        } else{
                m_ledRed.SetPulseTime(255);
                m_ledGreen.SetPulseTime(0);
                m_ledBlue.SetPulseTime(0);
        }
}
/*void LEDS::TurnOnLED(bool value){
        m_led.Set(value);
        areTheyOnBro = true; // Turn on the LED
}

bool LEDS::areTheyOn(){
        return areTheyOnBro;
}*/