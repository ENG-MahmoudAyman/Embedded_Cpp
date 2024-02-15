/*
 * MCAL_GPIO_PIN_cpp.h
 *
 *  Created on: Feb 14, 2024
 *      Author: engma
 */

#ifndef INC_MCAL_GPIO_PIN_H_
#define INC_MCAL_GPIO_PIN_H_

#include <MCAL_GPIO.h>

class MCAL_GPIO_PIN: private MCAL_GPIO{
private:

	uint16 GPIO_PinNumber;       //Specifies GPIO Pins to be configured
								 //This Parameter must be a value of @ref GPIO_PINS_Define
	uint8 GPIO_PinMODE;          //Specifies GPIO Mode for the Selected Pins
								 //This Parameter must be a value of @ref GPIO_Modes
	uint8 GPIO_PinOutput_Speed; //Specifies GPIO Output Pins speed for the Selected Pins
								//This Parameter must be a value of @ref GPIO_Output_Speed
	uint8 Get_CRLH_Position();

public:
	// APIs Supported by "MCAL GPIO DRIVER"

	MCAL_GPIO_PIN(GPIO_TypeDef *GPIOx, uint16 PinNumber, uint8 PinMODE,
			uint8 PinOutput_Speed);
	MCAL_GPIO_PIN(GPIO_TypeDef *GPIOx, uint16 PinNumber, uint8 PinMODE);
	void MCAL_GPIO_PIN_SetConfig(GPIO_TypeDef *GPIOx, uint16 PinNumber,
			uint8 PinMODE, uint8 PinOutput_Speed);
	void MCAL_GPIO_PIN_SetConfig(GPIO_TypeDef *GPIOx, uint16 PinNumber,
			uint8 PinMODE);
	void MCAL_GPIO_PIN_Init();
	uint8 MCAL_GPIO_PIN_Read();
	void MCAL_GPIO_PIN_Write(uint8 Value);
	void MCAL_GPIO_PIN_Toggle();
	uint8 MCAL_GPIO_PIN_Lock();
};

#endif /* INC_MCAL_GPIO_PIN_H_ */
