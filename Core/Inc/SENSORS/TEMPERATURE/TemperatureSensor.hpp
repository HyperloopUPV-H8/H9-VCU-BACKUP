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
		TemperatureSensor(float slope=121.9512195, float offset=196.3414634);

		void read();
		float getTemperature();

	private:
		float temperature;
        LinearSensor<float> sensor;
	};

}
