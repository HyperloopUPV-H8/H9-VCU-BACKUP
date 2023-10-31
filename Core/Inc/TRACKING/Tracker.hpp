/*
 * Tracker.hpp
 *
 *  Created on: Oct 10, 2023
 *      Author: amancio
 */

#include "EncoderSensor.hpp"
#include "Pinout.hpp"

#pragma once

namespace VCU {
	class Tracker {

	public:
		Tracker();

		void read();

		float getPosition();
		float getAcceleration();
		float getSpeed();
		float getDirection();

	private:
		EncoderSensor trackerEncoder;

		double position;
		double direction;
		double acceleration;
		double speed;

	};
}
