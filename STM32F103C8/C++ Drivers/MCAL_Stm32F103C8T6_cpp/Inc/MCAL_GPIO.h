/*
 * GPIO_Stm32F103x8.h
 *
 *  Created on: Jan 4, 2024
 *      Author: engma
 */

#ifndef INC_MCAL_GPIO_H_
#define INC_MCAL_GPIO_H_

//-----------------------------
//Includes
//-----------------------------

#include "platform_Types.h"
#include "Stm32F103x8.h"

//@ref GPIO_PIN_State
#define GPIO_PIN_HIGH                    1
#define GPIO_PIN_LOW                     0

//@ref GPIO_PIN_Lock_Ack
#define GPIO_PIN_Lock_Enabled            1
#define GPIO_PIN_Lock_Error              0

//==============================
//Macros Configuration Reference
//==============================

//@ref GPIO_PINS_Define
#define GPIO_PIN_0                    ((uint16)0x0001)  /* PIN 0 Is Selected */
#define GPIO_PIN_1                    ((uint16)0x0002)  /* PIN 1 Is Selected */
#define GPIO_PIN_2                    ((uint16)0x0004)  /* PIN 2 Is Selected */
#define GPIO_PIN_3                    ((uint16)0x0008)  /* PIN 3 Is Selected */
#define GPIO_PIN_4                    ((uint16)0x0010)  /* PIN 4 Is Selected */
#define GPIO_PIN_5                    ((uint16)0x0020)  /* PIN 5 Is Selected */
#define GPIO_PIN_6                    ((uint16)0x0040)  /* PIN 6 Is Selected */
#define GPIO_PIN_7                    ((uint16)0x0080)  /* PIN 7 Is Selected */
#define GPIO_PIN_8                    ((uint16)0x0100)  /* PIN 8 Is Selected */
#define GPIO_PIN_9                    ((uint16)0x0200)  /* PIN 9 Is Selected */
#define GPIO_PIN_10                   ((uint16)0x0400)  /* PIN 10 Is Selected */
#define GPIO_PIN_11                   ((uint16)0x0800)  /* PIN 11 Is Selected */
#define GPIO_PIN_12                   ((uint16)0x1000)  /* PIN 12 Is Selected */
#define GPIO_PIN_13                   ((uint16)0x2000)  /* PIN 13 Is Selected */
#define GPIO_PIN_14                   ((uint16)0x4000)  /* PIN 14 Is Selected */
#define GPIO_PIN_15                   ((uint16)0x8000)  /* PIN 15 Is Selected */
#define GPIO_PIN_ALL                  ((uint16)0xFFFF)  /* ALL PINS  Are Selected */

//@ref GPIO_Modes
#define GPIO_MODE_Analog              ((uint8)0x0000u)  /* Analog mode Is Selected */
#define GPIO_MODE_INPUT_FLO           ((uint8)0x0001u)  /* Floating Input mode Is Selected */
#define GPIO_MODE_INPUT_AF            ((uint8)0x0001u)  /* Alternative Input mode Is Selected (Floating Input)*/
#define GPIO_MODE_INPUT_PU            ((uint8)0x0002u)  /* Pull up Input mode Is Selected */
#define GPIO_MODE_INPUT_PD            ((uint8)0x0003u)  /* Pull down Input mode Is Selected */
#define GPIO_MODE_OUTPUT_PP           ((uint8)0x0004u)  /* Push Pull Output mode Is Selected */
#define GPIO_MODE_OUTPUT_OD           ((uint8)0x0005u)  /* Open drain Output mode Is Selected */
#define GPIO_MODE_OUTPUT_AF_PP        ((uint8)0x0006u)  /* Alternative Push Pull Output mode Is Selected */
#define GPIO_MODE_OUTPUT_AF_OD        ((uint8)0x0007u)  /* Alternative Open drain Output mode Is Selected */


//@ref GPIO_Output_Speed
#define GPIO_Output_Speed_10M         ((uint8)0x0001u)  /* Max Speed 10MHZ Output Is Selected */
#define GPIO_Output_Speed_2M          ((uint8)0x0002u)  /* Max Speed 2MHZ Output Is Selected */
#define GPIO_Output_Speed_50M         ((uint8)0x0003u)  /* Max Speed 50MHZ Output Is Selected */

class MCAL_GPIO{
private:
	MCAL_GPIO(){};
	GPIO_TypeDef *GPIOPort;
	void MCAL_GPIO_CLK_EN();
	friend class MCAL_GPIO_PORT;
	friend class MCAL_GPIO_PIN;
};

#endif /* INC_MCAL_GPIO_H_ */
