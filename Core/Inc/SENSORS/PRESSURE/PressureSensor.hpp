/*
 * Pressuresensor.hpp
 *
 *  Created on: Oct 10, 2023
 *      Author: amancio
 */
#pragma once

#include "LinearSensor.hpp"
#include "Pin.hpp"
#include "Pinout.hpp"

namespace VCU{

	class PressureSensor {
	public:
		PressureSensor(Pin pin, float slope, float offset);

		void read();
		float getPressure();

	private:
		float pressure;
        LinearSensor<float> pressureSensor;
	};
}
