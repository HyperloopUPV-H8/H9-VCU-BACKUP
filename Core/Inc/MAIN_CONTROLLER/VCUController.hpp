/*
 * VCUController.h
 *
 *  Created on: Oct 10, 2023
 *      Author: amancio
 */

#pragma once

#include "Brakes.hpp"
#include "PressureSensor.hpp"
#include "TemperatureSensor.hpp"
#include "TCP.hpp"
#include "UDP.hpp"
#include "Tracker.hpp"

#include "StateMachine.hpp"

namespace VCU {

	class VCUController {
	public:

		enum GeneralStateMachineStates{
			CONNECTING,
			OPERATIONAL,
			FAULT
		};

		VCUController();

		void read();
		static void update();

	private:

		StateMachine GeneralStateMachine;

		VCU::PressureSensor pSensor;
		VCU::TemperatureSensor tSensor;
		VCU::Tracker tracker;
		VCU::Brakes brakes;
		VCU::TCP tcp;
		VCU::UDP udp;
	};

}
