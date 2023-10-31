/*
 * RegulatorSensor.cpp
 *
 *  Created on: Oct 15, 2023
 *      Author: amancio
 */

#include "RegulatorSensor.hpp"

VCU::RegulatorSensor::RegulatorSensor() :
	regulator(
		Pinout::REGULATOR_IN,
		regulatorSlope,
		regulatorOffset,
		&pressure
	)
{}

float VCU::RegulatorSensor::getPressure() {
	return pressure;
}

void VCU::RegulatorSensor::read() {
	regulator.read();
}
