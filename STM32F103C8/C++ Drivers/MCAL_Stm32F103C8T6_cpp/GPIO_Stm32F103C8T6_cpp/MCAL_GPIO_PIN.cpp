/*
 * MCAL_GPIO_PIN.cpp
 *
 *  Created on: Feb 14, 2024
 *      Author: engma
 */

//-----------------------------
//Includes
//-----------------------------
#include <MCAL_GPIO_PIN.h>

uint8 MCAL_GPIO_PIN::Get_CRLH_Position() {
	switch (this->GPIO_PinNumber) {
	case GPIO_PIN_0:
	case GPIO_PIN_8:
		return 0;
		break;
	case GPIO_PIN_1:
	case GPIO_PIN_9:
		return 4;
		break;
	case GPIO_PIN_2:
	case GPIO_PIN_10:
		return 8;
		break;
	case GPIO_PIN_3:
	case GPIO_PIN_11:
		return 12;
		break;
	case GPIO_PIN_4:
	case GPIO_PIN_12:
		return 16;
		break;
	case GPIO_PIN_5:
	case GPIO_PIN_13:
		return 20;
		break;
	case GPIO_PIN_6:
	case GPIO_PIN_14:
		return 24;
		break;
	case GPIO_PIN_7:
	case GPIO_PIN_15:
		return 28;
		break;
	default:
		return 0;
		break;
	}
}

MCAL_GPIO_PIN::MCAL_GPIO_PIN(GPIO_TypeDef *GPIOx, uint16 PinNumber,
		uint8 PinMODE, uint8 PinOutput_Speed) {
	this->GPIOPort = GPIOx;
	this->GPIO_PinNumber = PinNumber;
	this->GPIO_PinMODE = PinMODE;
	this->GPIO_PinOutput_Speed = PinOutput_Speed;
}

MCAL_GPIO_PIN::MCAL_GPIO_PIN(GPIO_TypeDef *GPIOx, uint16 PinNumber,
		uint8 PinMODE) {
	this->GPIOPort = GPIOx;
	this->GPIO_PinNumber = PinNumber;
	this->GPIO_PinMODE = PinMODE;
	if (PinMODE >= GPIO_MODE_OUTPUT_PP && PinMODE <= GPIO_MODE_OUTPUT_AF_OD){
		this->GPIO_PinOutput_Speed = GPIO_Output_Speed_10M;
	}
}

void MCAL_GPIO_PIN::MCAL_GPIO_PIN_SetConfig(GPIO_TypeDef *GPIOx,
		uint16 PinNumber, uint8 PinMODE, uint8 PinOutput_Speed) {
	this->GPIOPort = GPIOx;
	this->GPIO_PinNumber = PinNumber;
	this->GPIO_PinMODE = PinMODE;
	this->GPIO_PinOutput_Speed = PinOutput_Speed;
}

void MCAL_GPIO_PIN::MCAL_GPIO_PIN_SetConfig(GPIO_TypeDef *GPIOx,
		uint16 PinNumber, uint8 PinMODE) {
	this->GPIOPort = GPIOx;
	this->GPIO_PinNumber = PinNumber;
	this->GPIO_PinMODE = PinMODE;
	if (PinMODE >= GPIO_MODE_OUTPUT_PP && PinMODE <= GPIO_MODE_OUTPUT_AF_OD){
		this->GPIO_PinOutput_Speed = GPIO_Output_Speed_10M;
	}

}

void MCAL_GPIO_PIN::MCAL_GPIO_PIN_Init() {
	MCAL_GPIO_CLK_EN();
	//Port configuration register low (GPIOx_CRL) (x=A..E) Pin 0 >>> 7
	//Port configuration register low (GPIOx_CRH) (x=A..E) Pin 8 >>> 15
	vuint32 *ConfigReg = NULL;
	uint8 PIN_Config;
	uint8 CRLH_Shift = Get_CRLH_Position();
	ConfigReg =
			(this->GPIO_PinNumber < GPIO_PIN_8) ?
					&this->GPIOPort->CRL : &this->GPIOPort->CRH;
	//clear CNFy[1:0] PinMODEy[1:0]
	(*ConfigReg) &= ~(0xF << CRLH_Shift);
	//PIN is output
	if ((this->GPIO_PinMODE == GPIO_MODE_OUTPUT_PP)
			|| (this->GPIO_PinMODE == GPIO_MODE_OUTPUT_OD)
			|| (this->GPIO_PinMODE == GPIO_MODE_OUTPUT_AF_PP)
			|| (this->GPIO_PinMODE == GPIO_MODE_OUTPUT_AF_OD)) {
		PIN_Config = ((((this->GPIO_PinMODE - 4) << 2)
				| (this->GPIO_PinOutput_Speed)) & 0x0F);
	}
	//PIN is input PinMODEy[1:0] = 00: Input PinMODE (reset state)
	else {
		if ((this->GPIO_PinMODE == GPIO_MODE_Analog)
				|| (this->GPIO_PinMODE == GPIO_MODE_INPUT_FLO)) {
			PIN_Config = (((this->GPIO_PinMODE) << 2) & 0x0C);
		} else {	//Pull up or down Input PinMODE Is Selected
			PIN_Config = (((GPIO_MODE_INPUT_PU) << 2) & 0x0C);
			if (this->GPIO_PinMODE == GPIO_MODE_INPUT_PU) {	//Pull up Input PinMODE Is Selected
				//Table 20. Port bit configuration table PINy ODRx register = 1
				this->GPIOPort->ODR |= (GPIO_PinNumber);
			} else {			//Pull down Input PinMODE Is Selected
				//Table 20. Port bit configuration table PINy ODRx register = 0
				this->GPIOPort->ODR &= ~(GPIO_PinNumber);
			}
		}
	}
	(*ConfigReg) |= PIN_Config << CRLH_Shift;

}

uint8 MCAL_GPIO_PIN::MCAL_GPIO_PIN_Read() {
	uint8 PinStatus;
	if ((this->GPIOPort->IDR) & GPIO_PinNumber) {
		PinStatus = GPIO_PIN_HIGH;
	} else {
		PinStatus = GPIO_PIN_LOW;
	}
	return PinStatus;
}

void MCAL_GPIO_PIN::MCAL_GPIO_PIN_Write(uint8 Value) {
	if (Value) {
		//(GPIOx->ODR)|= PinNumber;
		(this->GPIOPort->BSRR) = (uint32) GPIO_PinNumber;
	} else {
		//(GPIOx->ODR)&= ~PinNumber;
		(this->GPIOPort->BRR) = (uint32) GPIO_PinNumber;
	}
}

void MCAL_GPIO_PIN::MCAL_GPIO_PIN_Toggle() {
}

uint8 MCAL_GPIO_PIN::MCAL_GPIO_PIN_Lock() {
	vuint32 Temp = (1 << 16) | (uint32) GPIO_PinNumber;
//	Bit 16 LCKK[16]: Lock key
//	LOCK key writing sequence:
//	Write 1
	this->GPIOPort->LCKR = Temp;
//	Write 0
	this->GPIOPort->LCKR = (uint32) GPIO_PinNumber;
//	Write 1
	this->GPIOPort->LCKR = Temp;
//	Read 0
	Temp = this->GPIOPort->LCKR;
//	Read 1 (this read is optional but confirms that the lock is active)
	if ((this->GPIOPort->LCKR) & (1 << 16)) {
		return GPIO_PIN_Lock_Enabled;
	} else {
		return GPIO_PIN_Lock_Error;
	}

	//	Note: During the LOCK Key Writing sequence, the value of LCK[15:0] must not change.

}
