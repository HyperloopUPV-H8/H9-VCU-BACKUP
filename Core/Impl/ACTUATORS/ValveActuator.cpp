/*
 * ValveActuator.cpp
 *
 *  Created on: Oct 15, 2023
 *      Author: amancio
 */

#include <BRAKES/ACTUATORS/ValveActuator.hpp>

VCU::ValveActuator::ValveActuator(Pin& pin, State valveState) {

	VCU::ValveActuator::valveOutput = pin;
	VCU::ValveActuator::state = valveState;

	switch(valveState) {
		case State::CLOSED:
			VCU::ValveActuator::close();
			break;
		case State::OPEN:
			VCU::ValveActuator::open();
	}
}

VCU::ValveActuator::close() {
	VCU::ValveActuator::valveOutput.turn_off();
	VCU::ValveActuator::state = VCU::ValveActuator::State::CLOSED;
}

VCU::ValveActuator::open() {
	VCU::ValveActuator::valveOutput.turn_on();
	VCU::ValveActuator::state = VCU::ValveActuator::State::OPEN;
}

