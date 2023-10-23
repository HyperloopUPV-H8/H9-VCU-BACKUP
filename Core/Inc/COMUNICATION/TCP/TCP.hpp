/*
 * TCP.h
 *
 *  Created on: Oct 10, 2023
 *      Author: amancio
 */

#pragma once

#include "ServerSocket.hpp"
#include "ComunicationUtils.hpp"

namespace VCU {

	class TCP {
	public:
		TCP();
		void sendToControlStation(Order& order);

		void sendToOBCUUSocket(Order& order);
		void sendToBMSLSocket(Order& order);
		void SendToPCUSocket(Order& order);
		void sendToLCUSocket(Order& order);

		bool checkConnections();

	private:
		ServerSocket ControlStationSocket;
		Socket OBCCUSocket;
		Socket BMSLSocket;
		Socket PCUSocket;
		Socket LCUSocket;
	};
}
