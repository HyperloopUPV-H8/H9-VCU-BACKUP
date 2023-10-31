/*
 * Pressuresensor.cpp
 *
 *  Created on: Oct 10, 2023
 *      Author: amancio
 */

#include "PressureSensor.hpp"

VCU::PressureSensor::PressureSensor(Pin pin, float slope, float offset) : 
	pressureSensor(
		pin,
		slope,
		offset,
		&pressure
	)
{}

float VCU::PressureSensor::getPressure() {
	return pressure;
}

void VCU::PressureSensor::read() {
	pressureSensor.read();
}
