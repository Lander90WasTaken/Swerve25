

#include "subsystems/Climber.h"
#include "rev/SparkMax.h"
#include <rev/config/SparkMaxConfig.h>
#include <frc/smartdashboard/SmartDashboard.h>

using namespace ClimberConstants;

Climber::Climber(){
    SparkMaxConfig climbFollowerConfigObj;
    climbFollowerConfigObj.OpenLoopRampRate(1.75);
    m_climberMotor.Configure(climbFollowerConfigObj, SparkMax::ResetMode::kResetSafeParameters, SparkMax::PersistMode::kNoPersistParameters);
    m_climberEncoder.SetPosition(0);
}


void Climber::Periodic(){
    frc::SmartDashboard::PutNumber("climberEncoder",m_climberEncoder.GetPosition());
    Climber::InPosition();
}

void Climber::SimulationPeriodic(){

}

void Climber::RunClimber(double runSpeed){
    m_climberMotor.Set(runSpeed);
}

bool Climber::MovePigeon(){
    frc::SmartDashboard::PutNumber("pigeonServo",m_pigeonServo.GetPosition());
    if(m_pigeonServo.GetPosition() == 0.95){
        m_pigeonServo.SetPosition(0);
        frc::SmartDashboard::PutBoolean("pigeon in right place", false);
        return true;
    }
    else{
        m_pigeonServo.SetPosition(0.95);
        frc::SmartDashboard::PutBoolean("pigeon in right place", true);
        return false;
    }
}

double Climber::EncoderValue(){
    return m_climberEncoder.GetPosition();
}

void Climber::InPosition(){
    if(m_climberLimitSwitch.Get() == true){
        m_driverController.SetRumble(m_driverController.kRightRumble, 1);
        m_driverController.SetRumble(m_driverController.kLeftRumble, 1);
        m_leds.setLEDColor(0, 255, 0);
        m_driverController.SetRumble(m_driverController.kRightRumble, 0);
        m_driverController.SetRumble(m_driverController.kLeftRumble, 0);
    }
}