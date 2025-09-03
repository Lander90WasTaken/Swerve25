

#include "subsystems/Pincher.h"
#include "rev/SparkMax.h"
#include <rev/config/SparkMaxConfig.h>
#include <frc/smartdashboard/SmartDashboard.h>
#include <frc/DoubleSolenoid.h>

using namespace PincherConstants;

Pincher::Pincher(){
    SparkMaxConfig climbFollowerConfigObj;
    climbFollowerConfigObj.OpenLoopRampRate(1.75);
    //m_pincherMotor.Configure(climbFollowerConfigObj, SparkMax::ResetMode::kResetSafeParameters, SparkMax::PersistMode::kNoPersistParameters);
    m_pincherSolenoid.Set(0);
}


void Pincher::Periodic(){
    //frc::SmartDashboard::PutNumber("Absolutely Incredeeble Pincher Encoder Position Which is Functional in every way all the times",m_pincherEncoder.GetPosition());
}

void Pincher::SimulationPeriodic(){
    
}

void Pincher::SetPincher(bool active){
    m_pincherSolenoid.Set(active);
}

void Pincher::TogglePincher(){
    m_pincherSolenoid.Toggle();
}