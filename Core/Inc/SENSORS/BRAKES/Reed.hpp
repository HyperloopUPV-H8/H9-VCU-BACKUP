/*
 * Reed.hpp
 *
 *  Created on: Oct 22, 2023
 *      Author: amancio
 */

#pragma once
#include "DigitalSensor.hpp"

namespace VCU {
	class Reed {
	public:
		enum ReedState{
			EXTENDED,
			RETRACTED
		};

		Reed(Pin& pin, ) : reed(pin, (PinState*)reedState){}

		void read();
		ReedState getReedState();

	private:

		DigitalSensor reed;
		ReedState* reedState = EXTENDED;
	};
}
