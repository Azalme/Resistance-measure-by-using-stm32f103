#ifndef __GPIO_H
#define	__GPIO_H


#include "stm32f10x.h"

#define pin1  GPIO_Pin_2
#define pin2  GPIO_Pin_11
#define pin3  GPIO_Pin_3
#define pin4  GPIO_Pin_12

#define GPIO_Port GPIOA

int judge(void);
void gpio_config(void);


#endif
