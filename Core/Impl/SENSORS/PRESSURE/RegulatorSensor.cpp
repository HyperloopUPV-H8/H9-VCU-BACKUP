/*
 * RegulatorSensor.cpp
 *
 *  Created on: Oct 15, 2023
 *      Author: amancio
 */

#include <SENSORS/PRESSURE/RegulatorSensor.hpp>


float VCU::RegulatorSensor::getPressure() {
	return VCU::RegulatorSensor::regulatorPressure;
}

void VCU::RegulatorSensor::read() {
	VCU::RegulatorSensor::regulator.read();
}
