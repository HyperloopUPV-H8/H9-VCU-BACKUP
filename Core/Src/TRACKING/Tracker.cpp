/*
 * Tracker.cpp
 *
 *  Created on: Oct 10, 2023
 *      Author: amancio
 */

#include "Tracker.hpp"

VCU::Tracker::Tracker() {
	VCU::Tracker::TrackerEncoder.start();
}

void VCU::Tracker::read() {
	VCU::Tracker::TrackerEncoder.read();
}

float VCU::Tracker::getPosition() {
	return VCU::Tracker::position;
}

float VCU::Tracker::getAcceleration() {
	return VCU::Tracker::acceleration;
}

float VCU::Tracker::getSpeed() {
	return VCU::Tracker::speed;
}

float VCU::Tracker::getDirection() {
	return VCU::Tracker::direction;
}
