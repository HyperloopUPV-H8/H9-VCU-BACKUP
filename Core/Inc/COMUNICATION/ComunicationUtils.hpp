#pragma once

namespace VCU{
	const IPV4 VCU_IP = {"192.168.1.3"};
	const IPV4 LCU_MASTER_IP = {"192.168.1.4"};
	const IPV4 LCU_SLAVE_IP = {"192.168.1.5"};
	const IPV4 PCU_IP = {"192.168.1.6"};
	const IPV4 BLCU_IP = {"192.168.1.7"};
	const IPV4 BMSL_IP = {"192.168.1.8"};
	const IPV4 OBCCU_IP = {"192.168.1.9"};
	const IPV4 BACKEND_IP = {"192.168.0.9"};
	constexpr uint16_t SERVER_PORT = 50500;
	constexpr uint16_t CLIENT_PORT = 50501;
	constexpr uint16_t UDP_PORT = 50400;
}

enum class IncomingOrdersIDs: uint16_t{
	hardware_reset_order = 209,
	set_regulator_pressure_order = 210,
	brake_order = 216,
	unbrake_order = 217,
	disable_emergency_tape_order = 218,
	enable_emergency_tape_order = 219,

	heakthcheck_and_load = 220,
	healthcheck_and_unload = 221,
	start_static_lev_demostration = 222,
	start_dynamic_lev_demostration = 223,
	start_traction_demostration = 224,
	stop_demostration = 225,

	take_off = 226,
	landing = 227,
	start_crawling = 231,
	traction_data = 233,
	traction_end_data = 234,
};

enum class LevitationOrdes: uint16_t{
	TAKE_OFF = 300,
	LANDING = 301,
};

enum class TractionOrders: uint16_t{
	MOVE = 612,
	BRAKE = 613,
	TURN_OFF = 614,
};

enum class BatteryOrders: uint16_t{
	CLOSE_CONTACTORS = 903,
	OPEN_CONTACTORS = 902,
};
