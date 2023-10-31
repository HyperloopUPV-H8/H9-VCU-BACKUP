/*
 * RegulatorActuator.cpp
 *
 *  Created on: Oct 17, 2023
 *      Author: amancio
 */

#include "RegulatorActuator.hpp"

VCU::RegulatorActuator::RegulatorActuator(Pin& PWMPin, float pressure) :
	pwm(PWMPin),
	pressure(pressure)
{
	  pwm.set_frequency(VCU::RegulatorActuator::pwm_frequency);
	  pwm.set_duty_cycle(calculate_duty_cycle(pressure));
	  pwm.turn_on();
}

VCU::RegulatorActuator::RegulatorActuator(Pin& PWMPin) {
	RegulatorActuator(PWMPin, 1.1f);
}

void VCU::RegulatorActuator::setPressure(float newPressure) {
	  if(newPressure < min_pressure || newPressure > max_pressure){
			ErrorHandler("Pressure value of \"%f\" is out of range. Expected value between 0.0 and 10.0", pressure);
			return;
	  }
	  pressure = newPressure;
	  pwm.set_duty_cycle(calculate_duty_cycle(pressure));
}

float VCU::RegulatorActuator::getPressure() {
	return pressure;
}

float VCU::RegulatorActuator::calculate_duty_cycle(float pressure){
	return ((1.6f * pressure + 4.0f) * ( 0.168f / 3.3f)) * 100.0f;
}
