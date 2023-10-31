/*
 * ValveActuator.hpp
 *
 *  Created on: Oct 15, 2023
 *      Author: amancio
 */

#pragma once

#include "DigitalOutput.hpp"
#include "Pin.hpp"

namespace VCU {

	class ValveActuator {
	public:
		enum ValveState {
			OPEN,
			CLOSED
		};

		ValveActuator(Pin& pin, ValveState valveState = ValveState::CLOSED);

		void close();
		void open();

		ValveState getState();

	private:
		DigitalOutput valveOutput;
		ValveState state;

	};
}
