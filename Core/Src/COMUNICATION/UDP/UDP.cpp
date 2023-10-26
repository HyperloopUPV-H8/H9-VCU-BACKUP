/*
 * UDP.cpp
 *
 *  Created on: Oct 10, 2023
 *      Author: amancio
 */

#include "UDP.hpp"

VCU::UDP::UDP() {

	ControlStationSocket = DatagramSocket(VCU::VCU::VCU_IP, VCU::UDP_PORT, VCU::BACKEND_IP, VCU::UDP_PORT);
	ControlStationSocket.reconnect();

	OBCCUSocket = DatagramSocket(VCU::VCU::VCU_IP, VCU::UDP_PORT, VCU::OBCCU_IP, VCU::UDP_PORT);
	OBCCUSocket.reconnect();

	BMSLSocket = DatagramSocket(VCU::VCU_IP, VCU::UDP_PORT, VCU::BMSL_IP, VCU::UDP_PORT);
	BMSLSocket.reconnect();

	PCUSocket = DatagramSocket(VCU::VCU_IP, VCU::UDP_PORT, VCU::PCU_IP, VCU::UDP_PORT);
	PCUSocket.reconnect();

	LCUSocket = DatagramSocket(VCU::VCU_IP, VCU::UDP_PORT, VCU::LCU_MASTER_IP, VCU::UDP_PORT);
	LCUSocket.reconnect();

}

void sendToControlStation(Packet& packet) {
	VCU::UDP::ControlStationSocket.send(packet);
}

void VCU::UDPsendToOBCUUSocket(Packet& packet) {
	VCU::UDP::OBCCUSocket.send(packet);
}
void VCU::UDPsendToBMSLSOcket(Packet& packet) {
	VCU::UDP::BMSLSocket.send(packet);
}
void VCU::UDPSendToPCUSocket(Packet& packet) {
	VCU::UDP::PCUSocket.send(packet);
}
void VCU::UDPsendToLCUSocket(Packet& packet) {
	VCU::UDP::LCUSocket.send(packet);
}
