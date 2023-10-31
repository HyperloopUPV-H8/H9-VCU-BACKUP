/*
 * Brakes.cpp
 *
 *  Created on: Oct 11, 2023
 *      Author: amancio
 */

#include "Brakes.hpp"

VCU::Brakes::Brakes() :

	valveActuator(Pinout::VALVE),
	regulatorActuator (Pinout::REGULATOR_OUT),
	regulatorSensor(),

	emergencyTape(
			Pinout::EMERGENCY_TAPE,
			[&](){emergencyTape.read();},
			&emergencyTapeState
	),

	emergencyTapeEnable(VCU::Pinout::EMERGENCY_TAPE_ENABLE),
	reed1(Pinout::REED1),
	reed2(Pinout::REED2),
	reed3(Pinout::REED3),
	reed4(Pinout::REED4),

	temperatureSensor1(
			Pinout::BOTTLE_TEMP1,
			ntcLookupTable,
			ntcLookupTableSize,
			bottleTemperature1
	),
	temperatureSensor2(
			Pinout::BOTTLE_TEMP2,
			ntcLookupTable,
			ntcLookupTableSize,
			bottleTemperature2
	),
	highPressureSensor(
			Pinout::HIGH_PRESSURE,
			highPressureSensorSlope,
			highPressureSensorOffset
	),
	lowPressureSensor1(
			Pinout::LOW_PRESSURE1,
			lowPressureSensorsSlope,
			lowPressureSensorsOffset
	),
	lowPressureSensor2(
			Pinout::LOW_PRESSURE2,
			lowPressureSensorsSlope,
			lowPressureSensorsOffset
	)
{
	brake();
	read();
	enableEmergencyBrakes();
	setRegulatorPressure(operatingPressure);
	read();
}

void VCU::Brakes::read() {

	regulatorSensor.read();

	emergencyTape.read();

	temperatureSensor1.read();
	temperatureSensor2.read();

	highPressureSensor.read();
	lowPressureSensor1.read();
	lowPressureSensor2.read();
}

void VCU::Brakes::brake() {
	valveActuator.close();
	Time::set_timeout(1, [&](){checkReeds();});
}

void VCU::Brakes::unBrake() {
	valveActuator.open();
	Time::set_timeout(1, [&](){checkReeds();});
}

void VCU::Brakes::enableEmergencyBrakes() {
	  emergencyTapeEnable.turn_on();
}

void VCU::Brakes::disableEmeregencyBrakes() {
	emergencyTapeEnable.turn_off();
}

void VCU::Brakes::checkReeds() {
	reed1.read();
	reed2.read();
	reed3.read();
	reed4.read();
}

void VCU::Brakes::setRegulatorPressure(float newPressure) {
	regulatorActuator.setPressure(newPressure);
}


