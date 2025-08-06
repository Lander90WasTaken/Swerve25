#include <subsystems/LEDS.h>

LEDS::LEDS(){
        m_led.Set(0);
        areTheyOnBro = false; // Turn off the LED initially
}

void LEDS::TeleopPeriodic(){

}

void LEDS::SetLEDColor(int redValue, int greenValue, int blueValue) {
        
}
void LEDS::TurnOnLED(bool value){
        m_led.Set(value);
        areTheyOnBro = true; // Turn on the LED
}

bool LEDS::areTheyOn(){
    return areTheyOnBro;
}