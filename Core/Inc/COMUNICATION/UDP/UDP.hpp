/*
 * UDP.h
 *
 *  Created on: Oct 10, 2023
 *      Author: amancio
 */

#pragma once

#include "Packet.hpp"
#include "DatagramSocket.hpp"
#include "ComunicationUtils.hpp"

namespace VCU {

	class UDP {
	public:
		UDP();

		void sendToControlStation(Packet& packet);

		void sendToOBCUUSocket(Packet& packet);
		void sendToBMSLSocket(Packet& packet);
		void SendToPCUSocket(Packet& packet);
		void sendToLCUSocket(Packet& packet);

	private:

		DatagramSocket ControlStationSocket;
		DatagramSocket OBCCUSocket;
		DatagramSocket BMSLSocket;
		DatagramSocket PCUSocket;
		DatagramSocket LCUSocket;


	};
}
