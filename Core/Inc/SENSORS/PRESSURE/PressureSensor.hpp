/*
 * Pressuresensor.hpp
 *
 *  Created on: Oct 10, 2023
 *      Author: amancio
 */
#pragma once

#include "LinearSensor.hpp"
#include <Pinout.hpp>

namespace VCU{

	class PressureSensor {
	public:
		PressureSensor() :
			pressureSensor(
				Pinout2::ENVIRONMENT_PRESSURE,
				pressure_sensor_slope,
				pressure_sensor_offset,
				&ambientPreassure
			)
		{}

		void read();
		float getPressure();

	private:
		float ambientPreassure;
        LinearSensor<float> pressureSensor;

		constexpr static float pressure_sensor_slope = 0.379129905;
		constexpr static float pressure_sensor_offset = -0.125 - 0.03; //-0.03 Ajuste manual
	};
}
