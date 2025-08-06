
#pragma once

#include <rev/SparkMax.h>
#include <frc2/command/SubsystemBase.h>
#include <Constants.h>
#include <frc/PWM.h>

using namespace rev::spark;


class Pincher : public frc2::SubsystemBase{
    public:
        Pincher();

        void RunPincher();

        void Periodic() override;

        void SimulationPeriodic() override;

        double EncoderValue();

    private:
        frc::AnalogInput m_limitSwitch{0}
        frc::Solenoid m_pincherSolenoid{frc::PneumaticsModuleType::REVPH, 0, 1};
};