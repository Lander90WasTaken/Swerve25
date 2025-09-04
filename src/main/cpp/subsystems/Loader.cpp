

#include "subsystems/Loader.h"
#include "rev/SparkMax.h"
#include <rev/config/SparkMaxConfig.h>
#include <frc/smartdashboard/SmartDashboard.h>

using namespace LoaderConstants;

Loader::Loader(){
    SparkMaxConfig climbFollowerConfigObj;
    climbFollowerConfigObj.OpenLoopRampRate(1.75);
    m_loaderMotor.Configure(climbFollowerConfigObj, SparkMax::ResetMode::kResetSafeParameters, SparkMax::PersistMode::kNoPersistParameters);
    m_loaderEncoder.SetPosition(0);
}


void Loader::Periodic(){
    frc::SmartDashboard::PutNumber("Absolutely Incredeble Loader Encoder Position Which is Functional in every way all the time",m_loaderEncoder.GetPosition());
}

void Loader::SimulationPeriodic(){

}

void Loader::RunLoader(){
    m_loaderMotor.Set(0.3);
}

double Loader::EncoderValue(){
    return m_loaderEncoder.GetPosition();
}