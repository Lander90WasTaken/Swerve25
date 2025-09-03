
#pragma once

#include <rev/SparkMax.h>
#include <frc2/command/SubsystemBase.h>
#include <Constants.h>
#include <frc/AnalogInput.h>
#include <frc/Solenoid.h>

using namespace rev::spark;


class Pincher : public frc2::SubsystemBase{
    public:
        Pincher();

        void RunPincher();

        void Periodic() override;

        void SimulationPeriodic() override;

        double EncoderValue();

        void TogglePincher();

        void SetPincher(bool active);

    private:
        frc::AnalogInput m_limitSwitch{0};
        frc::Solenoid m_pincherSolenoid{frc::PneumaticsModuleType::REVPH, 0};
};