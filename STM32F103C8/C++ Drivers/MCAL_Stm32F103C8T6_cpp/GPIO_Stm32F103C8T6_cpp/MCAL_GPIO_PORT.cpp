/*
 * MCAL_GPIO_PORT.cpp
 *
 *  Created on: Feb 14, 2024
 *      Author: engma
 */

//-----------------------------
//Includes
//-----------------------------
#include <MCAL_GPIO_PORT.h>

MCAL_GPIO_PORT:: MCAL_GPIO_PORT(GPIO_TypeDef* GPIOx , uint8 PortMODE , uint8 PortOutput_Speed){
	this->GPIOPort = GPIOx;
	this->GPIO_PortMODE = PortMODE;
	this->GPIO_PortOutput_Speed = PortOutput_Speed;
}
MCAL_GPIO_PORT:: MCAL_GPIO_PORT(GPIO_TypeDef* GPIOx , uint8 PortMODE){
	this->GPIOPort = GPIOx;
	this->GPIO_PortMODE = PortMODE;
	if (PortMODE >= GPIO_MODE_OUTPUT_PP && PortMODE <= GPIO_MODE_OUTPUT_AF_OD){
		this->GPIO_PortOutput_Speed = GPIO_Output_Speed_10M;
	}
}
void MCAL_GPIO_PORT:: MCAL_GPIO_PORT_SetConfig(GPIO_TypeDef *GPIOx,
		uint8 PortMODE, uint8 PortOutput_Speed) {
	this->GPIOPort = GPIOx;
	this->GPIO_PortMODE = PortMODE;
	this->GPIO_PortOutput_Speed = PortOutput_Speed;
}

void MCAL_GPIO_PORT::MCAL_GPIO_PORT_SetConfig(GPIO_TypeDef *GPIOx,
		uint8 PortMODE) {
	this->GPIOPort = GPIOx;
	this->GPIO_PortMODE = PortMODE;
	if (PortMODE >= GPIO_MODE_OUTPUT_PP && PortMODE <= GPIO_MODE_OUTPUT_AF_OD){
		this->GPIO_PortOutput_Speed = GPIO_Output_Speed_10M;
	}
}

void MCAL_GPIO_PORT::MCAL_GPIO_PORT_Init() {
	MCAL_GPIO_CLK_EN();
	uint32 registervalues;
	switch (this->GPIO_PortMODE) {
	case (GPIO_MODE_Analog):
	case (GPIO_MODE_OUTPUT_PP):
		registervalues = 0;
		break;
	case (GPIO_MODE_INPUT_FLO):
	case (GPIO_MODE_OUTPUT_OD):
		registervalues = (0x44444444u);
		break;
	case (GPIO_MODE_INPUT_PU):
		registervalues = (0x55555555u);
		break;
	case (GPIO_MODE_OUTPUT_AF_PP):
		registervalues = (0x55555555u);
		this->GPIOPort->ODR |= 0xFFFF;
		break;
	case (GPIO_MODE_INPUT_PD):
		registervalues = 0x22222222;
		this->GPIOPort->ODR &= ~0xFFFF;
		break;
	case (GPIO_MODE_OUTPUT_AF_OD):
		registervalues = (0x66666666u);
		break;
	}

	switch (this->GPIO_PortOutput_Speed) {
	case (GPIO_Output_Speed_10M):
		registervalues |= (0x11111111u);
		break;
	case (GPIO_Output_Speed_2M):
		registervalues |= (0x22222222u);
		break;
	case (GPIO_Output_Speed_50M):
		registervalues |= (0x33333333u);
		break;
	}
	this->GPIOPort->CRL = 0;
	this->GPIOPort->CRH = 0;
	this->GPIOPort->CRL |= registervalues;
	this->GPIOPort->CRH |= registervalues;
}

void MCAL_GPIO_PORT::MCAL_GPIO_PORT_DeInit() {
	if (this->GPIOPort == GPIOA) {
		RCC->APB2RSTR |= (1 << 2);
		RCC->APB2RSTR &= ~(1 << 2);
	} else if (this->GPIOPort == GPIOB) {
		RCC->APB2RSTR |= (1 << 3);
		RCC->APB2RSTR &= ~(1 << 3);
	} else if (this->GPIOPort == GPIOC) {
		RCC->APB2RSTR |= (1 << 4);
		RCC->APB2RSTR &= ~(1 << 4);
	} else if (this->GPIOPort == GPIOD) {
		RCC->APB2RSTR |= (1 << 5);
		RCC->APB2RSTR &= ~(1 << 5);
	} else if (this->GPIOPort == GPIOE) {
		RCC->APB2RSTR |= (1 << 6);
		RCC->APB2RSTR &= ~(1 << 6);
	}
}
void MCAL_GPIO_PORT::MCAL_GPIO_PORT_Write(uint16 Value) {
	(this->GPIOPort->ODR) = (uint32) Value;
}

uint16 MCAL_GPIO_PORT::MCAL_GPIO_PORT_Read() {
	return (uint16) (this->GPIOPort->IDR);
}


