#include "gpio.h"


void gpio_config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// 打开 ADC IO端口时钟
	RCC_APB2PeriphClockCmd ( RCC_APB2Periph_GPIOA ,ENABLE );        //A2 A11 A3 A12
	
	// 配置 ADC IO 引脚模式
	// 必须为模拟输入
	GPIO_InitStructure.GPIO_Pin = GPIO_Pin_2|GPIO_Pin_11|GPIO_Pin_3|GPIO_Pin_12;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_IPU;
	GPIO_InitStructure.GPIO_Speed= GPIO_Speed_10MHz;
	// 初始化 ADC IO
	GPIO_Init(GPIOA, &GPIO_InitStructure);				
}

int judge(void)
{	
	int a;
	if(GPIO_ReadInputDataBit(GPIO_Port, pin1)==0)a=0;
	else
		if(GPIO_ReadInputDataBit(GPIO_Port, pin2)==0)a=1;
	else
		if(GPIO_ReadInputDataBit(GPIO_Port, pin3)==0)a=2;
	else
		if(GPIO_ReadInputDataBit(GPIO_Port, pin4)==0)a=3;
	else a=-1;
	return a;
		
}






