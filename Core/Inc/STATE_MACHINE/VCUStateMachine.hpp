/*
 * StateMachine.hpp
 *
 *  Created on: Oct 18, 2023
 *      Author: amancio
 */

#pragma once

#include "StateMachine.hpp"

namespace VCU {
	class VCUStateMachine {
	public:
		VCUStateMachine();

		void changeState();

	private:
		State* states = {
				//TODO
		};

		StateMachine vcuStateMachine();


	};
}
