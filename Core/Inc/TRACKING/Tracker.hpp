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
			Tracker() :
				TrackerEncoder(
					Pinout2::TAPE1,Pinout2::TAPE2,
					&position,&direction,&speed,&acceleration
				)
			{}

			void read();

			float getPosition();
			float getAcceleration();
			float getSpeed();
			float getDirection();

		private:

			EncoderSensor TrackerEncoder;

			float position;
			float direction;
			float acceleration;
			float speed;

		};
}
