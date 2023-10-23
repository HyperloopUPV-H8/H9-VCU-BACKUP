/*
 * Brakes.cpp
 *
 *  Created on: Oct 11, 2023
 *      Author: amancio
 */

#include "Brakes.hpp"

VCU::Brakes::Brakes(VCU::Data& data) :

	VCU::Brakes::valveActuator(Pinout::VALVE, data.valve_state),
	VCU::Brakes::regulatorActuator (
			Pinout::REGULATOR_OUT,
			data.regulator_real_pressure
	),
	VCU::Brakes::regulatorSensor(),

	VCU::Brakes::emergencyTape(
			Pinout::EMERGENCY_TAPE,
			[&](){emergencyTape.read();},
			VCU::Brakes::emergencyTapeState
	),
	VCU::Brakes::emergencyTapeEnable(Pinout2::EMERGENCY_TAPE_ENABLE),

	VCU::Brakes::reed1(Pinout::REED1, data.reed1),
	VCU::Brakes::reed2(Pinout::REED2, data.reed2),
	VCU::Brakes::reed3(Pinout::REED3, data.reed3),
	VCU::Brakes::reed4(Pinout::REED4, data.reed4),

	VCU::Brakes::temperatureSensor1(
			Pinout::BOTTLE_TEMP1,
			ntcLookupTable,
			ntcLookupTableSize,
			&data.bottle_temperature1
	),
	VCU::Brakes::temperatureSensor2(
			Pinout::BOTTLE_TEMP2,
			ntcLookupTable,
			ntcLookupTableSize,
			&data.bottle_temperature2
	),
	VCU::Brakes::highPressureSensor(
			Pinout::HIGH_PRESSURE,
			highPressureSensorSlope,
			highPressureSensorOffset,
			&data.high_pressure1
	),
	VCU::Brakes::lowPressureSensor1(
			Pinout::LOW_PRESSURE1,
			lowPressureSensorsSlope,
			lowPressureSensorsOffset,
			&data.low_pressure1
	),
	VCU::Brakes::lowPressureSensor2(
			Pinout::LOW_PRESSURE2,
			lowPressureSensorsSlope,
			lowPressureSensorsOffset,
			&data.low_pressure2
	)
{
	VCU::Brakes::brake();
	VCU::Brakes::read();
	VCU::Brakes::enable_emergency_brakes();
	VCU::Brakes::regulatorActuator.set_pressure(VCU::Brakes::operatingPressure);
	VCU::Brakes::read();
}

void VCU::Brakes::read() {

	VCU::Brakes::regulatorSensor.read();
	VCU::Brakes::regulatorSensor.read();

	VCU::Brakes::emergencyTape.read();

	VCU::Brakes::temperatureSensor1.read();
	VCU::Brakes::temperatureSensor2.read();

	VCU::Brakes::highPressureSensor.read();
	VCU::Brakes::lowPressureSensor1.read();
	VCU::Brakes::lowPressureSensor2.read();

}

void VCU::Brakes::brake() {
	VCU::Brakes::valveActuator.close();
	Time::set_timeout(1, [&](){check_reeds();});
}

void VCU::Brakes::unBrake() {
	VCU::Brakes::valveActuator.open();
	Time::set_timeout(1, [&](){check_reeds();});
}

void VCU::Brakes::enableEmergencyBrakes() {
	  VCU::Brakes::emergencyTapeEnable.turn_on();
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

void VCU::Brakes::setRegulatorPressure(float newPressure ) {
	VCU::Brakes::regulatorActuator.setPressure(newPressure);
}


