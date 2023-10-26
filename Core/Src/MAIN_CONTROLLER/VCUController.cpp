/*
 * VCUController.cpp
 *
 *  Created on: Oct 10, 2023
 *      Author: amancio
 */

#include "VCUController.hpp"

VCU::VCUController::VCUController() :

VCU::VCUController::pSensor(),
VCU::VCUController::tSensor(),
VCU::VCUController::tracker(),
VCU::VCUController::brakes(), //meditar
VCU::VCUController::tcp(),
VCU::VCUController::udp()
{
	STLIB::start();
}

VCU::VCUController::read() {
	pSensor.read();
	tSensor.read();
	tracker.read();
	brakes.read();
}

VCU::VCUController::update() {

	VCU::VCUController::read();
	STLIB::update();
}

