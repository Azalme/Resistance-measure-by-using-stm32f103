#include "bsp_adc.h"
#include "bsp_dma.h"	


//__IO uint16_t ADC_Count=0;


/**
  * @brief  ADC GPIO 初始化
  * @param  无
  * @retval 无
  */
void ADCx_GPIO_Config(void)
{
	GPIO_InitTypeDef GPIO_InitStructure;
	
	// 打开 ADC IO端口时钟
	ADC_GPIO_APBxClock_FUN ( ADC_GPIO_CLK, ENABLE );
	
	// 配置 ADC IO 引脚模式
	// 必须为模拟输入
	GPIO_InitStructure.GPIO_Pin = ADC_PIN;
	GPIO_InitStructure.GPIO_Mode = GPIO_Mode_AIN;
	
	// 初始化 ADC IO
	GPIO_Init(ADC_PORT, &GPIO_InitStructure);				
}

/**
  * @brief  配置ADC工作模式
  * @param  无
  * @retval 无
  */
void ADCx_Mode_Config(int a)
{
	ADC_InitTypeDef ADC_InitStructure;	
	
	// 打开ADC时钟
	ADC_APBxClock_FUN ( ADC_CLK, ENABLE );
	
	/****************************************/
	DMA_E2M_IT_Config();//DMA配置
	/****************************************/
	
	// ADC 模式配置
	// 只使用一个ADC，属于独立模式
	ADC_InitStructure.ADC_Mode = ADC_Mode_Independent;
	
	// 禁止扫描模式，多通道才要，单通道不需要
	ADC_InitStructure.ADC_ScanConvMode = ENABLE ; 
	// 连续转换模式
	ADC_InitStructure.ADC_ContinuousConvMode = ENABLE;

	// 不用外部触发转换，软件开启即可
	ADC_InitStructure.ADC_ExternalTrigConv = ADC_ExternalTrigConv_None; 

	// 转换结果右对齐
	ADC_InitStructure.ADC_DataAlign = ADC_DataAlign_Right;
	
	// 转换通道1个
	ADC_InitStructure.ADC_NbrOfChannel = 1;	
		
	// 初始化ADC
	ADC_Init(ADC1, &ADC_InitStructure);
	
	// 配置ADC时钟为PCLK2的8分频，即9MHz
	RCC_ADCCLKConfig(RCC_PCLK2_Div8); 
	
	// 配置 ADC 通道转换顺序和采样时间         一周期采样16点 则采样周期T=T/16       对应T=（12.5+adcSampleTime)*t(adc采样频率)（t=1/f)
																																									//或f(采样频率)=f(采样目标)*16=f(时钟频率)/（12.5+adcSampleTime)
																																									//配置sampletime为71时为6700HZ采样 1为40180HZ采样  41-13700
		if(a==-1)                                                                       //2232HZ
		{
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 1, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 2, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 3, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 4, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 5, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 6, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 7, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 8, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 9, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 10, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 11, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 12, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 13, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 14, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 15, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 16, ADC_SampleTime_239Cycles5);
		}									
			else
			if(a==0)                                                                       //2232HZ
		{
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 1, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 2, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 3, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 4, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 5, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 6, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 7, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 8, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 9, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 10, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 11, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 12, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 13, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 14, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 15, ADC_SampleTime_239Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 16, ADC_SampleTime_239Cycles5);
		}
	else																																						
	if(a==1)
	{
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 1, ADC_SampleTime_71Cycles5);       //6700HZ
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 2, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 3, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 4, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 5, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 6, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 7, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 8, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 9, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 10, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 11, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 12, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 13, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 14, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 15, ADC_SampleTime_71Cycles5);
	ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 16, ADC_SampleTime_71Cycles5);
	}
	else 
		if(a==2)                                                                       //13700HZ
		{
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 1, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 2, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 3, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 4, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 5, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 6, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 7, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 8, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 9, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 10, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 11, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 12, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 13, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 14, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 15, ADC_SampleTime_28Cycles5);
			ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 16, ADC_SampleTime_28Cycles5);
		}
	else 
		if(a==3)                                                                       //40180HZ
		{
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 1, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 2, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 3, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 4, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 5, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 6, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 7, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 8, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 9, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 10, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 11, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 12, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 13, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 14, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 15, ADC_SampleTime_1Cycles5);
				ADC_RegularChannelConfig(ADC1, ADC_CHANNEL, 16, ADC_SampleTime_1Cycles5);
		}
		
	// ADC 转换结束产生中断，在中断服务程序中读取转换值
	//ADC_ITConfig(ADCx, ADC_IT_EOC, ENABLE);                      //用于计数转换个数
	
		// 使能ADC DMA 请求
	ADC_DMACmd(ADC1, ENABLE);
	
	// 开启ADC ，并开始转换
	ADC_Cmd(ADC1, ENABLE);
	
	// 初始化ADC 校准寄存器  
	ADC_ResetCalibration(ADC1);
	// 等待校准寄存器初始化完成
	while(ADC_GetResetCalibrationStatus(ADC1));
	
	// ADC开始校准
	ADC_StartCalibration(ADC1);
	// 等待校准完成
	while(ADC_GetCalibrationStatus(ADC1));
	
	// 由于没有采用外部触发，所以使用软件触发ADC转换 
	ADC_SoftwareStartConvCmd(ADC1, ENABLE);                //由主函数控制
}
/*
static void ADC_NVIC_Config(void)
{
  NVIC_InitTypeDef NVIC_InitStructure;
	// 优先级分组
	NVIC_PriorityGroupConfig(NVIC_PriorityGroup_1);

  // 配置中断优先级
  NVIC_InitStructure.NVIC_IRQChannel = ADC_IRQ;
  NVIC_InitStructure.NVIC_IRQChannelPreemptionPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelSubPriority = 1;
  NVIC_InitStructure.NVIC_IRQChannelCmd = ENABLE;
  NVIC_Init(&NVIC_InitStructure);
}
*/

/**
  * @brief  ADC初始化
  * @param  无
  * @retval 无
  */
void ADCx_Init(int i)
{
	ADCx_GPIO_Config();
	ADCx_Mode_Config(i);
	//ADC_NVIC_Config();
}
/*********************************************END OF FILE**********************/
