/*
 * TemperatureSensor.hpp
 *
 *  Created on: Oct 10, 2023
 *      Author: amancio
 */
#pragma once

#include "LinearSensor.hpp"
#include <Pinout.hpp>

namespace VCU {

	class TemperatureSensor {
	public:
		TemperatureSensor() :
			temperatureSensor(
					Pinout2::ENVIRONMENT_TEMPERATURE,
					temperature_sensor_slope,
					temperature_sensor_offset,
					&enviromentalTemperature
			) {}

		void read();
		float getTemperature();

	private:
		float enviromentalTemperature;
        LinearSensor<float> temperatureSensor;

		constexpr static float temperature_sensor_slope = -121.9512195;
		constexpr static float temperature_sensor_offset = 196.3414634;
	};

}
