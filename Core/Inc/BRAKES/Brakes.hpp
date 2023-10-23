/*
 * Brakes.h
 *
 *  Created on: Oct 11, 2023
 *      Author: amancio
 */

#pragma once

#include "Reed.hpp"
#include "ValveActuator.hpp"
#include "DigitalSensor.hpp"
#include "LookupSensor.hpp"
#include "LinearSensor.hpp"
#include "RegulatorActuator.hpp"
#include "RegulatorSensor.hpp"
#include "SensorInterrupt.hpp"
#include "Reed.hpp"
#include "Pinout.hpp"
#include "Data.hpp"

#include "Time.hpp"

namespace VCU {

	class Brakes {
	public:
		Brakes(VCU::Data& data);
		void read();
		void brake();
		void unBrake();
		void enableEmergencyBrakes();
		void disableEmeregencyBrakes();
		void checkReeds();
		void setRegulatorPressure(float newPressure);

	private:

		constexpr static uint16_t ntcLookupTableSize = 256;

		constexpr static float highPressureSensorSlope = 0.006681691;
		constexpr static float highPressureSensorOffset = -43.75;

		constexpr static float lowPressureSensorsSlope = 0.000190905;
		constexpr static float lowPressureSensorsOffset = -1.25;

		constexpr static float operatingPressure = 8.0f;

		ValveActuator valveActuator;
		RegulatorActuator regulatorActuator;
		RegulatorSensor regulatorSensor;

		SensorInterrupt emergencyTape;
		DigitalOutput emergencyTapeEnable;

		Reed reed1;
		Reed reed2;
		Reed reed3;
		Reed reed4;

		Data data;

		double ntcLookupTable[ntcLookupTableSize];

		LookupSensor temperatureSensor1;
		LookupSensor temperatureSensor2;

		LinearSensor<float> highPressureSensor;
		LinearSensor<float> lowPressureSensor1;
		LinearSensor<float> lowPressureSensor2;

};

}
