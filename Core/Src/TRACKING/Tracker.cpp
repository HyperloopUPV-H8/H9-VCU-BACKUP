/*
 * Tracker.cpp
 *
 *  Created on: Oct 10, 2023
 *      Author: amancio
 */

#include "Tracker.hpp"

VCU::Tracker::Tracker() :
	trackerEncoder(
		Pinout::TAPE1, Pinout::TAPE2,
		&position, &direction, &speed, &acceleration
	)
{
	trackerEncoder.start();
}

void VCU::Tracker::read() {
	trackerEncoder.read();
}

float VCU::Tracker::getPosition() {
	return position;
}

float VCU::Tracker::getAcceleration() {
	return acceleration;
}

float VCU::Tracker::getSpeed() {
	return speed;
}

float VCU::Tracker::getDirection() {
	return direction;
}
