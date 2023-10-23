/*
 * RegulatorActuator.hpp
 *
 *  Created on: Oct 17, 2023
 *      Author: amancio
 */

#pragma once

#include "PWM.hpp"

namespace VCU {
	class RegulatorActuator {
	public:
		RegulatorActuator(Pin& PWMPin, float& pressure);

		void setPressure(float newPressure);
		float getPressure();

	private:

		static float calculate_duty_cycle(float pressure);

		static constexpr uint16_t pwm_frequency = 10000;
		static constexpr float max_pressure = 10.0f;
		static constexpr float min_pressure = 0.0f;

		PWM pwm;
		float& pressure;
	};
}
