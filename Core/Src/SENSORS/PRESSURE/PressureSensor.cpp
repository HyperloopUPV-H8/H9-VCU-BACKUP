/*
 * Pressuresensor.cpp
 *
 *  Created on: Oct 10, 2023
 *      Author: amancio
 */

#include <SENSORS/PRESSURE/PressureSensor.hpp>

float VCU::PressureSensor::getPressure() {
	return VCU::PressureSensor::enviromental_preassure;
}

void VCU::PressureSensor::read() {
	VCU::PressureSensor::pressureSensor.read();
}
