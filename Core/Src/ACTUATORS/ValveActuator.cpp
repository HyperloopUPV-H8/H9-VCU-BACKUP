/*
 * ValveActuator.cpp
 *
 *  Created on: Oct 15, 2023
 *      Author: amancio
 */

#include "ValveActuator.hpp"

VCU::ValveActuator::ValveActuator(Pin& pin, ValveState valveState) {

	valveOutput = pin;
	state = valveState;

	switch(valveState) {
		case ValveState::CLOSED:
			close();
			break;
		case ValveState::OPEN:
			open();
	}
}

void VCU::ValveActuator::close() {
	valveOutput.turn_off();
	state = ValveState::CLOSED;
}

void VCU::ValveActuator::open() {
	valveOutput.turn_on();
	state = ValveState::OPEN;
}

VCU::ValveActuator::ValveState VCU::ValveActuator::getState() {
	return state;
}
