/*
 * TemperatureSensor.cpp
 *
 *  Created on: Oct 10, 2023
 *      Author: amancio
 */

#include <TemperatureSensor.hpp>

VCU::TemperatureSensor::TemperatureSensor(float slope, float offset) :
	sensor(
		Pinout::ENVIRONMENT_TEMPERATURE,
		slope,
		offset,
		&temperature
	)
{}

float VCU::TemperatureSensor::getTemperature() {
	return temperature;
}

void VCU::TemperatureSensor::read(){
	sensor.read();
}
