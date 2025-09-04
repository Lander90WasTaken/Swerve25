
#pragma once

#include <rev/SparkMax.h>
#include <frc2/command/SubsystemBase.h>
#include <Constants.h>
#include <frc/PWM.h>
#include "Constants.h"

using namespace rev::spark;


class Loader : public frc2::SubsystemBase{
    public:
        Loader();

        void RunLoader();

        void Periodic() override;

        void SimulationPeriodic() override;

        double EncoderValue();


    private:
        SparkMax m_loaderMotor{LoaderConstants::kLoaderMotorCanId, SparkLowLevel::MotorType::kBrushless};
        SparkRelativeEncoder m_loaderEncoder = m_loaderMotor.GetEncoder();

};