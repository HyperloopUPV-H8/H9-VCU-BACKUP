/*
 * TemperatureSensor.cpp
 *
 *  Created on: Oct 10, 2023
 *      Author: amancio
 */

#include <TemperatureSensor.hpp>

float VCU::TemperatureSensor::getTemperature(){
	return VCU::TemperatureSensor::enviromentalTemperature;
}

void VCU::TemperatureSensor::read(){
	VCU::TemperatureSensor::temperatureSensor.read();
}
