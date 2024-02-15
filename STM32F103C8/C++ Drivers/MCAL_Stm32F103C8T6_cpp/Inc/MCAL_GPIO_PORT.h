/*
 * MCAL_GPIO_PORT_cpp.h
 *
 *  Created on: Feb 14, 2024
 *      Author: engma
 */

#ifndef INC_MCAL_GPIO_PORT_H_
#define INC_MCAL_GPIO_PORT_H_

#include <MCAL_GPIO.h>

class MCAL_GPIO_PORT: private MCAL_GPIO{
private:
	vuint8 GPIO_PortMODE;         //Specifies GPIO Mode for the Selected Pins
								 //This Parameter must be a value of @ref GPIO_Modes
	vuint8 GPIO_PortOutput_Speed; //Specifies GPIO Output Pins speed for the Selected Pins
								 //This Parameter must be a value of @ref GPIO_Output_Speed
public:

	MCAL_GPIO_PORT(GPIO_TypeDef *GPIOx, uint8 PortMODE, uint8 PortOutput_Speed);
	MCAL_GPIO_PORT(GPIO_TypeDef *GPIOx, uint8 PortMODE);
	void MCAL_GPIO_PORT_SetConfig(GPIO_TypeDef *GPIOx, uint8 PortMODE,
			uint8 PortOutput_Speed);
	void MCAL_GPIO_PORT_SetConfig(GPIO_TypeDef *GPIOx, uint8 PortMODE);
	void MCAL_GPIO_PORT_Init();
	void MCAL_GPIO_PORT_DeInit();
	void MCAL_GPIO_PORT_Write(uint16 Value);
	uint16 MCAL_GPIO_PORT_Read();
};



#endif /* INC_MCAL_GPIO_PORT_H_ */
