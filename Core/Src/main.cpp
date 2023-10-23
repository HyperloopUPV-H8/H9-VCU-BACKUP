#include "main.h"
#include "lwip.h"

#include "ST-LIB.hpp"

#include "../Impl/MAIN_CONTROLLER/VCUController.cpp"
#include "Runes/Runes.hpp"



//WIP
int main(void)
{
	VCU::VCUController vcuController;

	while(1) {
		vcuController.update();
	}
}

void Error_Handler(void) {
	ErrorHandler("HAL error handler triggered");
	while (1){}
}
