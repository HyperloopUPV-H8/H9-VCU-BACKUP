/*
 * ElectronicRegulator.hpp
 *
 *  Created on: Oct 15, 2023
 *      Author: amancio
 */
#pragma once

#include "LinearSensor.hpp"
#include "Pinout.hpp"
#include "ErrorHandler.hpp"

namespace VCU {

	class RegulatorSensor {
	public:
		RegulatorSensor() :
			regulator(
				Pinout2::REGULATOR_IN,
				regulatorSlope,
				regulatorOffset,
				&regulatorPressure
			)
		{}

		void read();
		float getPressure();

	private:
		float regulatorPressure;
		LinearSensor<float> regulator;

		constexpr static float regulatorSlope = 3.78787;
		constexpr static float regulatorOffset = -2.5;
	};
}
