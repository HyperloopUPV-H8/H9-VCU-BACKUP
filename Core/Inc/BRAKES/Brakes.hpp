/*
 * Brakes.h
 *
 *  Created on: Oct 11, 2023
 *      Author: amancio
 */

#pragma once

#include "ValveActuator.hpp"
#include "DigitalSensor.hpp"
#include "LookupSensor.hpp"
#include "LinearSensor.hpp"
#include "RegulatorActuator.hpp"
#include "RegulatorSensor.hpp"
#include "Reed.hpp"
#include "Pinout.hpp"
#include "PressureSensor.hpp"

#include "Time.hpp"
#include "SensorInterrupt.hpp"

namespace VCU {

	class Brakes {
	public:
		Brakes();
		
		void read();
		void brake();
		void unBrake();
		void enableEmergencyBrakes();
		void disableEmeregencyBrakes();
		void checkReeds();
		void setRegulatorPressure(float newPressure);

		void getHighPressureSensorPressure();
		void getLowPressureSensorPressure();
		void getLowPressureSensorPressure();

		void getReed1State();
		void getReed2State();
		void getReed3State();
		void getReed4State();

		void getValveActuatorState();

		void getRegulatorSensorPressure();
		
	private:

		constexpr static uint16_t ntcLookupTableSize = 256;
		double ntcLookupTable[ntcLookupTableSize];

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
		PinState emergencyTapeState;

		Reed reed1;
		Reed reed2;
		Reed reed3;
		Reed reed4;

		LookupSensor temperatureSensor1;
		double bottleTemperature1;

		LookupSensor temperatureSensor2;
		double bottleTemperature2;

		PressureSensor highPressureSensor;
		PressureSensor lowPressureSensor1;
		PressureSensor lowPressureSensor2;

	};

}
