/*
 * TCP.cpp
 *
 *  Created on: Oct 10, 2023
 *      Author: amancio
 */

#include "ComunicationUtils.hpp"
#include "TCP.hpp"

VCU::TCP::TCP() {
	VCU::TCP::ControlStationSocket = ServerSocket(VCU::VCU::VCU_IP, VCU::SERVER_PORT);
	VCU::TCP::OBCCUSocket = Socket(VCU::VCU::VCU_IP, VCU::CLIENT_PORT, VCU::OBCCU_IP, VCU::SERVER_PORT);
	VCU::TCP::BMSLSocket = Socket(VCU::VCU::VCU_IP, VCU::CLIENT_PORT, VCU::BMSL_IP, VCU::SERVER_PORT);
	VCU::TCP::PCUSocket = Socket(VCU::VCU::VCU_IP, VCU::CLIENT_PORT, VCU::PCU_IP, VCU::SERVER_PORT);
	VCU::TCP::LCUSocket = Socket(VCU::VCU::VCU_IP, VCU::CLIENT_PORT, VCU::LCU_MASTER_IP, VCU::SERVER_PORT);
}

VCU::TCP::sendToControlStation(Order& order) {
	ControlStationSocket.send_order(order);
}
VCU::TCP::sendToOBCUUSocket(Order& order) {
	OBCCUSocket.send_order(order);
}
VCU::TCP::sendToBMSLSocket(Order& order) {
	BMSLSocket.send_order(order);
}
VCU::TCP::SendToPCUSocket(Order& order) {
	PCUSocket.send_order(order);
}
VCU::TCP::sendToLCUSocket(Order& order) {
	LCUSocket.send_order(order);
}

VCU::TCP::checkConnections() {
	return ControlStationSocket.is_connected()
			&& LCUSocket.is_connected() && BMSLSocket.is_connected()
			&& PCUSocket.is_connected() && OBCCUSocket.is_connected();
}


