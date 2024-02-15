
#include <MCAL_GPIO_PIN.h>
#include <MCAL_GPIO_PORT.h>
#include "platform_Types.h"

int main(void){
	MCAL_GPIO_PORT PortB(GPIOB,GPIO_MODE_OUTPUT_PP, GPIO_Output_Speed_10M);
	PortB.MCAL_GPIO_PORT_Init();
	MCAL_GPIO_PIN PA1(GPIOA, GPIO_PIN_1, GPIO_MODE_INPUT_PU);
	PA1.MCAL_GPIO_PIN_Init();
while(1){
		if (PA1.MCAL_GPIO_PIN_Read()) {
			PortB.MCAL_GPIO_PORT_Write(0xFF);
			for (uint32 i = 0; i < 6000; i++);
			PortB.MCAL_GPIO_PORT_Write(0x0);
			for (int i = 0; i < 6000; i++);
		} else {
			PortB.MCAL_GPIO_PORT_Write(0x0);
		}
}
return 0;
}
