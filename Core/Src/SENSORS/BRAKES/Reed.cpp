/*
 * Reeds.cpp
 *
 *  Created on: Oct 22, 2023
 *      Author: amancio
 */

#include "Reed.hpp"

VCU::Reed::Reed(Pin& pin) : reed(pin, (PinState*)reedState) {
	reedState = ReedState::EXTENDED;
}

void VCU::Reed::read(){
	reed.read();
}

VCU::Reed::ReedState VCU::Reed::getReedState() {
	return reedState;
}
