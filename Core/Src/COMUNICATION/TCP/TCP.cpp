/*
 * TCP.cpp
 *
 *  Created on: Oct 10, 2023
 *      Author: amancio
 */

#include "TCP.hpp"

VCU::TCP::TCP() {
	ControlStationSocket = ServerSocket(VCU_IP, SERVER_PORT);
	OBCCUSocket = Socket(VCU_IP, CLIENT_PORT,OBCCU_IP,SERVER_PORT);
	BMSLSocket = Socket(VCU_IP, CLIENT_PORT, BMSL_IP, SERVER_PORT);
	PCUSocket = Socket(VCU_IP, CLIENT_PORT, PCU_IP, SERVER_PORT);
	LCUSocket = Socket(VCU_IP, CLIENT_PORT, LCU_MASTER_IP, SERVER_PORT);
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


