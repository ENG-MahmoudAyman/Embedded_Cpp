/*
 * MCAL_GPIO.cpp
 *
 *  Created on: Feb 14, 2024
 *      Author: engma
 */

#include <MCAL_GPIO.h>

void MCAL_GPIO::MCAL_GPIO_CLK_EN() {
	if (GPIOPort == GPIOA) {
		GPIOA_CLK_EN();
	} else if (GPIOPort == GPIOB) {
		GPIOB_CLK_EN();
	} else if (GPIOPort == GPIOC) {
		GPIOC_CLK_EN();
	} else if (GPIOPort == GPIOD) {
		GPIOD_CLK_EN();
	} else if (GPIOPort == GPIOE) {
		GPIOE_CLK_EN();
	}
}
