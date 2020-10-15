/*
 * GPIO_Test_G070.c
 *
 *  Created on: 2020. okt. 14.
 *      Author: BodnarB
 */

#define TEST_CASE_GPIO
#include "TestEnv.h"

void GPIO_Test(void);
void GPIO_TestCase_1(void);
int GetGpioModerValue(dtGPIOs value);
int GetGpioOtyperValue(dtGPIOs value);
int GetGpioOspeedrValue(dtGPIOs value);
int GetGpioPupdrValue(dtGPIOs value);

void GPIO_Test(void)
{
	GPIO_TestCase_1();
}

void GPIO_TestCase_1(void)
{
	int looper;
	int looper2;
	int looper3;
	int looper4;
	dtGPIOs looper5;
	dtGPIOConfig config;

	for(looper = Input; looper <= Alt15; looper++)
	{
		for(looper2 = PushPull; looper2 <= OpenDrain; looper2++)
		{
			for(looper3 = Low; looper3 <= VeryHigh; looper3++)
			{
				for(looper4 = NoPull; looper4 <= PullDown; looper4++)
				{
					for(looper5 = PortA_0; looper5 <= PortH_15; looper5++)
					{
						config.Mode = looper;
						config.PUPD = looper4;
						config.Speed = looper3;
						config.Type = looper2;
						
						if((looper5 <= PortD_15) || ((looper >= PortF_0) && (looper <= PortF_15)))
						{
							int moder;
							int Otyper;
							int Ospeedr;
							int Pupdr;

							if(looper == Output) moder = 1;
							else if(looper == Analog) moder = 3;
							else if(looper >= Alt0) moder = 2;
							else moder = 0;

							if(looper2 == PushPull) Otyper = 0;
							else Otyper = 1;

							if(looper3 == Low) Ospeedr = 0;
							else if(looper3 == Medium) Ospeedr = 1;
							else if(looper3 == High) Ospeedr = 2;
							else Ospeedr = 3;

							if(looper4 == NoPull) Pupdr = 0;
							else if(looper4 == PullUp) Pupdr = 1;
							else Pupdr = 2;

							GPIO_PinInit(looper5, config);
							ASSERT_EQ(GetGpioModerValue(looper5), moder);
							ASSERT_EQ(GetGpioOtyperValue(looper5), Otyper);
							ASSERT_EQ(GetGpioOspeedrValue(looper5), Ospeedr);
							ASSERT_EQ(GetGpioPupdrValue(looper5), Pupdr);
						}
					}
				}
			}
		}
	}
}

int GetGpioModerValue(dtGPIOs value)
{
	int GpioValue = 0;
	switch(value)
	{
	case PortA_0:
		GpioValue = TestGPIOA.MODER.Fields.PIN0;
		break;
	case PortA_1:
		GpioValue = TestGPIOA.MODER.Fields.PIN1;
		break;
	case PortA_2:
		GpioValue = TestGPIOA.MODER.Fields.PIN2;
		break;
	case PortA_3:
		GpioValue = TestGPIOA.MODER.Fields.PIN3;
		break;
	case PortA_4:
		GpioValue = TestGPIOA.MODER.Fields.PIN4;
		break;
	case PortA_5:
		GpioValue = TestGPIOA.MODER.Fields.PIN5;
		break;
	case PortA_6:
		GpioValue = TestGPIOA.MODER.Fields.PIN6;
		break;
	case PortA_7:
		GpioValue = TestGPIOA.MODER.Fields.PIN7;
		break;
	case PortA_8:
		GpioValue = TestGPIOA.MODER.Fields.PIN8;
		break;
	case PortA_9:
		GpioValue = TestGPIOA.MODER.Fields.PIN9;
		break;
	case PortA_10:
		GpioValue = TestGPIOA.MODER.Fields.PIN10;
		break;
	case PortA_11:
		GpioValue = TestGPIOA.MODER.Fields.PIN11;
		break;
	case PortA_12:
		GpioValue = TestGPIOA.MODER.Fields.PIN12;
		break;
	case PortA_13:
		GpioValue = TestGPIOA.MODER.Fields.PIN13;
		break;
	case PortA_14:
		GpioValue = TestGPIOA.MODER.Fields.PIN14;
		break;
	case PortA_15:
		GpioValue = TestGPIOA.MODER.Fields.PIN15;
		break;
	case PortB_0:
		GpioValue = TestGPIOB.MODER.Fields.PIN0;
		break;
	case PortB_1:
		GpioValue = TestGPIOB.MODER.Fields.PIN1;
		break;
	case PortB_2:
		GpioValue = TestGPIOB.MODER.Fields.PIN2;
		break;
	case PortB_3:
		GpioValue = TestGPIOB.MODER.Fields.PIN3;
		break;
	case PortB_4:
		GpioValue = TestGPIOB.MODER.Fields.PIN4;
		break;
	case PortB_5:
		GpioValue = TestGPIOB.MODER.Fields.PIN5;
		break;
	case PortB_6:
		GpioValue = TestGPIOB.MODER.Fields.PIN6;
		break;
	case PortB_7:
		GpioValue = TestGPIOB.MODER.Fields.PIN7;
		break;
	case PortB_8:
		GpioValue = TestGPIOB.MODER.Fields.PIN8;
		break;
	case PortB_9:
		GpioValue = TestGPIOB.MODER.Fields.PIN9;
		break;
	case PortB_10:
		GpioValue = TestGPIOB.MODER.Fields.PIN10;
		break;
	case PortB_11:
		GpioValue = TestGPIOB.MODER.Fields.PIN11;
		break;
	case PortB_12:
		GpioValue = TestGPIOB.MODER.Fields.PIN12;
		break;
	case PortB_13:
		GpioValue = TestGPIOB.MODER.Fields.PIN13;
		break;
	case PortB_14:
		GpioValue = TestGPIOB.MODER.Fields.PIN14;
		break;
	case PortB_15:
		GpioValue = TestGPIOB.MODER.Fields.PIN15;
		break;
	case PortC_0:
		GpioValue = TestGPIOC.MODER.Fields.PIN0;
		break;
	case PortC_1:
		GpioValue = TestGPIOC.MODER.Fields.PIN1;
		break;
	case PortC_2:
		GpioValue = TestGPIOC.MODER.Fields.PIN2;
		break;
	case PortC_3:
		GpioValue = TestGPIOC.MODER.Fields.PIN3;
		break;
	case PortC_4:
		GpioValue = TestGPIOC.MODER.Fields.PIN4;
		break;
	case PortC_5:
		GpioValue = TestGPIOC.MODER.Fields.PIN5;
		break;
	case PortC_6:
		GpioValue = TestGPIOC.MODER.Fields.PIN6;
		break;
	case PortC_7:
		GpioValue = TestGPIOC.MODER.Fields.PIN7;
		break;
	case PortC_8:
		GpioValue = TestGPIOC.MODER.Fields.PIN8;
		break;
	case PortC_9:
		GpioValue = TestGPIOC.MODER.Fields.PIN9;
		break;
	case PortC_10:
		GpioValue = TestGPIOC.MODER.Fields.PIN10;
		break;
	case PortC_11:
		GpioValue = TestGPIOC.MODER.Fields.PIN11;
		break;
	case PortC_12:
		GpioValue = TestGPIOC.MODER.Fields.PIN12;
		break;
	case PortC_13:
		GpioValue = TestGPIOC.MODER.Fields.PIN13;
		break;
	case PortC_14:
		GpioValue = TestGPIOC.MODER.Fields.PIN14;
		break;
	case PortC_15:
		GpioValue = TestGPIOC.MODER.Fields.PIN15;
		break;
	case PortD_0:
		GpioValue = TestGPIOD.MODER.Fields.PIN0;
		break;
	case PortD_1:
		GpioValue = TestGPIOD.MODER.Fields.PIN1;
		break;
	case PortD_2:
		GpioValue = TestGPIOD.MODER.Fields.PIN2;
		break;
	case PortD_3:
		GpioValue = TestGPIOD.MODER.Fields.PIN3;
		break;
	case PortD_4:
		GpioValue = TestGPIOD.MODER.Fields.PIN4;
		break;
	case PortD_5:
		GpioValue = TestGPIOD.MODER.Fields.PIN5;
		break;
	case PortD_6:
		GpioValue = TestGPIOD.MODER.Fields.PIN6;
		break;
	case PortD_7:
		GpioValue = TestGPIOD.MODER.Fields.PIN7;
		break;
	case PortD_8:
		GpioValue = TestGPIOD.MODER.Fields.PIN8;
		break;
	case PortD_9:
		GpioValue = TestGPIOD.MODER.Fields.PIN9;
		break;
	case PortD_10:
		GpioValue = TestGPIOD.MODER.Fields.PIN10;
		break;
	case PortD_11:
		GpioValue = TestGPIOD.MODER.Fields.PIN11;
		break;
	case PortD_12:
		GpioValue = TestGPIOD.MODER.Fields.PIN12;
		break;
	case PortD_13:
		GpioValue = TestGPIOD.MODER.Fields.PIN13;
		break;
	case PortD_14:
		GpioValue = TestGPIOD.MODER.Fields.PIN14;
		break;
	case PortD_15:
		GpioValue = TestGPIOD.MODER.Fields.PIN15;
		break;
	case PortF_0:
		GpioValue = TestGPIOF.MODER.Fields.PIN0;
		break;
	case PortF_1:
		GpioValue = TestGPIOF.MODER.Fields.PIN1;
		break;
	case PortF_2:
		GpioValue = TestGPIOF.MODER.Fields.PIN2;
		break;
	case PortF_3:
		GpioValue = TestGPIOF.MODER.Fields.PIN3;
		break;
	case PortF_4:
		GpioValue = TestGPIOF.MODER.Fields.PIN4;
		break;
	case PortF_5:
		GpioValue = TestGPIOF.MODER.Fields.PIN5;
		break;
	case PortF_6:
		GpioValue = TestGPIOF.MODER.Fields.PIN6;
		break;
	case PortF_7:
		GpioValue = TestGPIOF.MODER.Fields.PIN7;
		break;
	case PortF_8:
		GpioValue = TestGPIOF.MODER.Fields.PIN8;
		break;
	case PortF_9:
		GpioValue = TestGPIOF.MODER.Fields.PIN9;
		break;
	case PortF_10:
		GpioValue = TestGPIOF.MODER.Fields.PIN10;
		break;
	case PortF_11:
		GpioValue = TestGPIOF.MODER.Fields.PIN11;
		break;
	case PortF_12:
		GpioValue = TestGPIOF.MODER.Fields.PIN12;
		break;
	case PortF_13:
		GpioValue = TestGPIOF.MODER.Fields.PIN13;
		break;
	case PortF_14:
		GpioValue = TestGPIOF.MODER.Fields.PIN14;
		break;
	case PortF_15:
		GpioValue = TestGPIOF.MODER.Fields.PIN15;
		break;
	}
	return GpioValue;
}

int GetGpioOtyperValue(dtGPIOs value)
{
	int GpioValue = 0;
	switch(value)
	{
	case PortA_0:
		GpioValue = TestGPIOA.OTYPER.Fields.PIN0;
		break;
	case PortA_1:
		GpioValue = TestGPIOA.OTYPER.Fields.PIN1;
		break;
	case PortA_2:
		GpioValue = TestGPIOA.OTYPER.Fields.PIN2;
		break;
	case PortA_3:
		GpioValue = TestGPIOA.OTYPER.Fields.PIN3;
		break;
	case PortA_4:
		GpioValue = TestGPIOA.OTYPER.Fields.PIN4;
		break;
	case PortA_5:
		GpioValue = TestGPIOA.OTYPER.Fields.PIN5;
		break;
	case PortA_6:
		GpioValue = TestGPIOA.OTYPER.Fields.PIN6;
		break;
	case PortA_7:
		GpioValue = TestGPIOA.OTYPER.Fields.PIN7;
		break;
	case PortA_8:
		GpioValue = TestGPIOA.OTYPER.Fields.PIN8;
		break;
	case PortA_9:
		GpioValue = TestGPIOA.OTYPER.Fields.PIN9;
		break;
	case PortA_10:
		GpioValue = TestGPIOA.OTYPER.Fields.PIN10;
		break;
	case PortA_11:
		GpioValue = TestGPIOA.OTYPER.Fields.PIN11;
		break;
	case PortA_12:
		GpioValue = TestGPIOA.OTYPER.Fields.PIN12;
		break;
	case PortA_13:
		GpioValue = TestGPIOA.OTYPER.Fields.PIN13;
		break;
	case PortA_14:
		GpioValue = TestGPIOA.OTYPER.Fields.PIN14;
		break;
	case PortA_15:
		GpioValue = TestGPIOA.OTYPER.Fields.PIN15;
		break;
	case PortB_0:
		GpioValue = TestGPIOB.OTYPER.Fields.PIN0;
		break;
	case PortB_1:
		GpioValue = TestGPIOB.OTYPER.Fields.PIN1;
		break;
	case PortB_2:
		GpioValue = TestGPIOB.OTYPER.Fields.PIN2;
		break;
	case PortB_3:
		GpioValue = TestGPIOB.OTYPER.Fields.PIN3;
		break;
	case PortB_4:
		GpioValue = TestGPIOB.OTYPER.Fields.PIN4;
		break;
	case PortB_5:
		GpioValue = TestGPIOB.OTYPER.Fields.PIN5;
		break;
	case PortB_6:
		GpioValue = TestGPIOB.OTYPER.Fields.PIN6;
		break;
	case PortB_7:
		GpioValue = TestGPIOB.OTYPER.Fields.PIN7;
		break;
	case PortB_8:
		GpioValue = TestGPIOB.OTYPER.Fields.PIN8;
		break;
	case PortB_9:
		GpioValue = TestGPIOB.OTYPER.Fields.PIN9;
		break;
	case PortB_10:
		GpioValue = TestGPIOB.OTYPER.Fields.PIN10;
		break;
	case PortB_11:
		GpioValue = TestGPIOB.OTYPER.Fields.PIN11;
		break;
	case PortB_12:
		GpioValue = TestGPIOB.OTYPER.Fields.PIN12;
		break;
	case PortB_13:
		GpioValue = TestGPIOB.OTYPER.Fields.PIN13;
		break;
	case PortB_14:
		GpioValue = TestGPIOB.OTYPER.Fields.PIN14;
		break;
	case PortB_15:
		GpioValue = TestGPIOB.OTYPER.Fields.PIN15;
		break;
	case PortC_0:
		GpioValue = TestGPIOC.OTYPER.Fields.PIN0;
		break;
	case PortC_1:
		GpioValue = TestGPIOC.OTYPER.Fields.PIN1;
		break;
	case PortC_2:
		GpioValue = TestGPIOC.OTYPER.Fields.PIN2;
		break;
	case PortC_3:
		GpioValue = TestGPIOC.OTYPER.Fields.PIN3;
		break;
	case PortC_4:
		GpioValue = TestGPIOC.OTYPER.Fields.PIN4;
		break;
	case PortC_5:
		GpioValue = TestGPIOC.OTYPER.Fields.PIN5;
		break;
	case PortC_6:
		GpioValue = TestGPIOC.OTYPER.Fields.PIN6;
		break;
	case PortC_7:
		GpioValue = TestGPIOC.OTYPER.Fields.PIN7;
		break;
	case PortC_8:
		GpioValue = TestGPIOC.OTYPER.Fields.PIN8;
		break;
	case PortC_9:
		GpioValue = TestGPIOC.OTYPER.Fields.PIN9;
		break;
	case PortC_10:
		GpioValue = TestGPIOC.OTYPER.Fields.PIN10;
		break;
	case PortC_11:
		GpioValue = TestGPIOC.OTYPER.Fields.PIN11;
		break;
	case PortC_12:
		GpioValue = TestGPIOC.OTYPER.Fields.PIN12;
		break;
	case PortC_13:
		GpioValue = TestGPIOC.OTYPER.Fields.PIN13;
		break;
	case PortC_14:
		GpioValue = TestGPIOC.OTYPER.Fields.PIN14;
		break;
	case PortC_15:
		GpioValue = TestGPIOC.OTYPER.Fields.PIN15;
		break;
	case PortD_0:
		GpioValue = TestGPIOD.OTYPER.Fields.PIN0;
		break;
	case PortD_1:
		GpioValue = TestGPIOD.OTYPER.Fields.PIN1;
		break;
	case PortD_2:
		GpioValue = TestGPIOD.OTYPER.Fields.PIN2;
		break;
	case PortD_3:
		GpioValue = TestGPIOD.OTYPER.Fields.PIN3;
		break;
	case PortD_4:
		GpioValue = TestGPIOD.OTYPER.Fields.PIN4;
		break;
	case PortD_5:
		GpioValue = TestGPIOD.OTYPER.Fields.PIN5;
		break;
	case PortD_6:
		GpioValue = TestGPIOD.OTYPER.Fields.PIN6;
		break;
	case PortD_7:
		GpioValue = TestGPIOD.OTYPER.Fields.PIN7;
		break;
	case PortD_8:
		GpioValue = TestGPIOD.OTYPER.Fields.PIN8;
		break;
	case PortD_9:
		GpioValue = TestGPIOD.OTYPER.Fields.PIN9;
		break;
	case PortD_10:
		GpioValue = TestGPIOD.OTYPER.Fields.PIN10;
		break;
	case PortD_11:
		GpioValue = TestGPIOD.OTYPER.Fields.PIN11;
		break;
	case PortD_12:
		GpioValue = TestGPIOD.OTYPER.Fields.PIN12;
		break;
	case PortD_13:
		GpioValue = TestGPIOD.OTYPER.Fields.PIN13;
		break;
	case PortD_14:
		GpioValue = TestGPIOD.OTYPER.Fields.PIN14;
		break;
	case PortD_15:
		GpioValue = TestGPIOD.OTYPER.Fields.PIN15;
		break;
	case PortF_0:
		GpioValue = TestGPIOF.OTYPER.Fields.PIN0;
		break;
	case PortF_1:
		GpioValue = TestGPIOF.OTYPER.Fields.PIN1;
		break;
	case PortF_2:
		GpioValue = TestGPIOF.OTYPER.Fields.PIN2;
		break;
	case PortF_3:
		GpioValue = TestGPIOF.OTYPER.Fields.PIN3;
		break;
	case PortF_4:
		GpioValue = TestGPIOF.OTYPER.Fields.PIN4;
		break;
	case PortF_5:
		GpioValue = TestGPIOF.OTYPER.Fields.PIN5;
		break;
	case PortF_6:
		GpioValue = TestGPIOF.OTYPER.Fields.PIN6;
		break;
	case PortF_7:
		GpioValue = TestGPIOF.OTYPER.Fields.PIN7;
		break;
	case PortF_8:
		GpioValue = TestGPIOF.OTYPER.Fields.PIN8;
		break;
	case PortF_9:
		GpioValue = TestGPIOF.OTYPER.Fields.PIN9;
		break;
	case PortF_10:
		GpioValue = TestGPIOF.OTYPER.Fields.PIN10;
		break;
	case PortF_11:
		GpioValue = TestGPIOF.OTYPER.Fields.PIN11;
		break;
	case PortF_12:
		GpioValue = TestGPIOF.OTYPER.Fields.PIN12;
		break;
	case PortF_13:
		GpioValue = TestGPIOF.OTYPER.Fields.PIN13;
		break;
	case PortF_14:
		GpioValue = TestGPIOF.OTYPER.Fields.PIN14;
		break;
	case PortF_15:
		GpioValue = TestGPIOF.OTYPER.Fields.PIN15;
		break;
	}
	return GpioValue;
}

int GetGpioOspeedrValue(dtGPIOs value)
{
	int GpioValue = 0;
	switch(value)
	{
	case PortA_0:
		GpioValue = TestGPIOA.OSPEEDER.Fields.PIN0;
		break;
	case PortA_1:
		GpioValue = TestGPIOA.OSPEEDER.Fields.PIN1;
		break;
	case PortA_2:
		GpioValue = TestGPIOA.OSPEEDER.Fields.PIN2;
		break;
	case PortA_3:
		GpioValue = TestGPIOA.OSPEEDER.Fields.PIN3;
		break;
	case PortA_4:
		GpioValue = TestGPIOA.OSPEEDER.Fields.PIN4;
		break;
	case PortA_5:
		GpioValue = TestGPIOA.OSPEEDER.Fields.PIN5;
		break;
	case PortA_6:
		GpioValue = TestGPIOA.OSPEEDER.Fields.PIN6;
		break;
	case PortA_7:
		GpioValue = TestGPIOA.OSPEEDER.Fields.PIN7;
		break;
	case PortA_8:
		GpioValue = TestGPIOA.OSPEEDER.Fields.PIN8;
		break;
	case PortA_9:
		GpioValue = TestGPIOA.OSPEEDER.Fields.PIN9;
		break;
	case PortA_10:
		GpioValue = TestGPIOA.OSPEEDER.Fields.PIN10;
		break;
	case PortA_11:
		GpioValue = TestGPIOA.OSPEEDER.Fields.PIN11;
		break;
	case PortA_12:
		GpioValue = TestGPIOA.OSPEEDER.Fields.PIN12;
		break;
	case PortA_13:
		GpioValue = TestGPIOA.OSPEEDER.Fields.PIN13;
		break;
	case PortA_14:
		GpioValue = TestGPIOA.OSPEEDER.Fields.PIN14;
		break;
	case PortA_15:
		GpioValue = TestGPIOA.OSPEEDER.Fields.PIN15;
		break;
	case PortB_0:
		GpioValue = TestGPIOB.OSPEEDER.Fields.PIN0;
		break;
	case PortB_1:
		GpioValue = TestGPIOB.OSPEEDER.Fields.PIN1;
		break;
	case PortB_2:
		GpioValue = TestGPIOB.OSPEEDER.Fields.PIN2;
		break;
	case PortB_3:
		GpioValue = TestGPIOB.OSPEEDER.Fields.PIN3;
		break;
	case PortB_4:
		GpioValue = TestGPIOB.OSPEEDER.Fields.PIN4;
		break;
	case PortB_5:
		GpioValue = TestGPIOB.OSPEEDER.Fields.PIN5;
		break;
	case PortB_6:
		GpioValue = TestGPIOB.OSPEEDER.Fields.PIN6;
		break;
	case PortB_7:
		GpioValue = TestGPIOB.OSPEEDER.Fields.PIN7;
		break;
	case PortB_8:
		GpioValue = TestGPIOB.OSPEEDER.Fields.PIN8;
		break;
	case PortB_9:
		GpioValue = TestGPIOB.OSPEEDER.Fields.PIN9;
		break;
	case PortB_10:
		GpioValue = TestGPIOB.OSPEEDER.Fields.PIN10;
		break;
	case PortB_11:
		GpioValue = TestGPIOB.OSPEEDER.Fields.PIN11;
		break;
	case PortB_12:
		GpioValue = TestGPIOB.OSPEEDER.Fields.PIN12;
		break;
	case PortB_13:
		GpioValue = TestGPIOB.OSPEEDER.Fields.PIN13;
		break;
	case PortB_14:
		GpioValue = TestGPIOB.OSPEEDER.Fields.PIN14;
		break;
	case PortB_15:
		GpioValue = TestGPIOB.OSPEEDER.Fields.PIN15;
		break;
	case PortC_0:
		GpioValue = TestGPIOC.OSPEEDER.Fields.PIN0;
		break;
	case PortC_1:
		GpioValue = TestGPIOC.OSPEEDER.Fields.PIN1;
		break;
	case PortC_2:
		GpioValue = TestGPIOC.OSPEEDER.Fields.PIN2;
		break;
	case PortC_3:
		GpioValue = TestGPIOC.OSPEEDER.Fields.PIN3;
		break;
	case PortC_4:
		GpioValue = TestGPIOC.OSPEEDER.Fields.PIN4;
		break;
	case PortC_5:
		GpioValue = TestGPIOC.OSPEEDER.Fields.PIN5;
		break;
	case PortC_6:
		GpioValue = TestGPIOC.OSPEEDER.Fields.PIN6;
		break;
	case PortC_7:
		GpioValue = TestGPIOC.OSPEEDER.Fields.PIN7;
		break;
	case PortC_8:
		GpioValue = TestGPIOC.OSPEEDER.Fields.PIN8;
		break;
	case PortC_9:
		GpioValue = TestGPIOC.OSPEEDER.Fields.PIN9;
		break;
	case PortC_10:
		GpioValue = TestGPIOC.OSPEEDER.Fields.PIN10;
		break;
	case PortC_11:
		GpioValue = TestGPIOC.OSPEEDER.Fields.PIN11;
		break;
	case PortC_12:
		GpioValue = TestGPIOC.OSPEEDER.Fields.PIN12;
		break;
	case PortC_13:
		GpioValue = TestGPIOC.OSPEEDER.Fields.PIN13;
		break;
	case PortC_14:
		GpioValue = TestGPIOC.OSPEEDER.Fields.PIN14;
		break;
	case PortC_15:
		GpioValue = TestGPIOC.OSPEEDER.Fields.PIN15;
		break;
	case PortD_0:
		GpioValue = TestGPIOD.OSPEEDER.Fields.PIN0;
		break;
	case PortD_1:
		GpioValue = TestGPIOD.OSPEEDER.Fields.PIN1;
		break;
	case PortD_2:
		GpioValue = TestGPIOD.OSPEEDER.Fields.PIN2;
		break;
	case PortD_3:
		GpioValue = TestGPIOD.OSPEEDER.Fields.PIN3;
		break;
	case PortD_4:
		GpioValue = TestGPIOD.OSPEEDER.Fields.PIN4;
		break;
	case PortD_5:
		GpioValue = TestGPIOD.OSPEEDER.Fields.PIN5;
		break;
	case PortD_6:
		GpioValue = TestGPIOD.OSPEEDER.Fields.PIN6;
		break;
	case PortD_7:
		GpioValue = TestGPIOD.OSPEEDER.Fields.PIN7;
		break;
	case PortD_8:
		GpioValue = TestGPIOD.OSPEEDER.Fields.PIN8;
		break;
	case PortD_9:
		GpioValue = TestGPIOD.OSPEEDER.Fields.PIN9;
		break;
	case PortD_10:
		GpioValue = TestGPIOD.OSPEEDER.Fields.PIN10;
		break;
	case PortD_11:
		GpioValue = TestGPIOD.OSPEEDER.Fields.PIN11;
		break;
	case PortD_12:
		GpioValue = TestGPIOD.OSPEEDER.Fields.PIN12;
		break;
	case PortD_13:
		GpioValue = TestGPIOD.OSPEEDER.Fields.PIN13;
		break;
	case PortD_14:
		GpioValue = TestGPIOD.OSPEEDER.Fields.PIN14;
		break;
	case PortD_15:
		GpioValue = TestGPIOD.OSPEEDER.Fields.PIN15;
		break;
	case PortF_0:
		GpioValue = TestGPIOF.OSPEEDER.Fields.PIN0;
		break;
	case PortF_1:
		GpioValue = TestGPIOF.OSPEEDER.Fields.PIN1;
		break;
	case PortF_2:
		GpioValue = TestGPIOF.OSPEEDER.Fields.PIN2;
		break;
	case PortF_3:
		GpioValue = TestGPIOF.OSPEEDER.Fields.PIN3;
		break;
	case PortF_4:
		GpioValue = TestGPIOF.OSPEEDER.Fields.PIN4;
		break;
	case PortF_5:
		GpioValue = TestGPIOF.OSPEEDER.Fields.PIN5;
		break;
	case PortF_6:
		GpioValue = TestGPIOF.OSPEEDER.Fields.PIN6;
		break;
	case PortF_7:
		GpioValue = TestGPIOF.OSPEEDER.Fields.PIN7;
		break;
	case PortF_8:
		GpioValue = TestGPIOF.OSPEEDER.Fields.PIN8;
		break;
	case PortF_9:
		GpioValue = TestGPIOF.OSPEEDER.Fields.PIN9;
		break;
	case PortF_10:
		GpioValue = TestGPIOF.OSPEEDER.Fields.PIN10;
		break;
	case PortF_11:
		GpioValue = TestGPIOF.OSPEEDER.Fields.PIN11;
		break;
	case PortF_12:
		GpioValue = TestGPIOF.OSPEEDER.Fields.PIN12;
		break;
	case PortF_13:
		GpioValue = TestGPIOF.OSPEEDER.Fields.PIN13;
		break;
	case PortF_14:
		GpioValue = TestGPIOF.OSPEEDER.Fields.PIN14;
		break;
	case PortF_15:
		GpioValue = TestGPIOF.OSPEEDER.Fields.PIN15;
		break;
	}
	return GpioValue;
}

int GetGpioPupdrValue(dtGPIOs value)
{
	int GpioValue = 0;
	switch(value)
	{
	case PortA_0:
		GpioValue = TestGPIOA.PUPDR.Fields.PIN0;
		break;
	case PortA_1:
		GpioValue = TestGPIOA.PUPDR.Fields.PIN1;
		break;
	case PortA_2:
		GpioValue = TestGPIOA.PUPDR.Fields.PIN2;
		break;
	case PortA_3:
		GpioValue = TestGPIOA.PUPDR.Fields.PIN3;
		break;
	case PortA_4:
		GpioValue = TestGPIOA.PUPDR.Fields.PIN4;
		break;
	case PortA_5:
		GpioValue = TestGPIOA.PUPDR.Fields.PIN5;
		break;
	case PortA_6:
		GpioValue = TestGPIOA.PUPDR.Fields.PIN6;
		break;
	case PortA_7:
		GpioValue = TestGPIOA.PUPDR.Fields.PIN7;
		break;
	case PortA_8:
		GpioValue = TestGPIOA.PUPDR.Fields.PIN8;
		break;
	case PortA_9:
		GpioValue = TestGPIOA.PUPDR.Fields.PIN9;
		break;
	case PortA_10:
		GpioValue = TestGPIOA.PUPDR.Fields.PIN10;
		break;
	case PortA_11:
		GpioValue = TestGPIOA.PUPDR.Fields.PIN11;
		break;
	case PortA_12:
		GpioValue = TestGPIOA.PUPDR.Fields.PIN12;
		break;
	case PortA_13:
		GpioValue = TestGPIOA.PUPDR.Fields.PIN13;
		break;
	case PortA_14:
		GpioValue = TestGPIOA.PUPDR.Fields.PIN14;
		break;
	case PortA_15:
		GpioValue = TestGPIOA.PUPDR.Fields.PIN15;
		break;
	case PortB_0:
		GpioValue = TestGPIOB.PUPDR.Fields.PIN0;
		break;
	case PortB_1:
		GpioValue = TestGPIOB.PUPDR.Fields.PIN1;
		break;
	case PortB_2:
		GpioValue = TestGPIOB.PUPDR.Fields.PIN2;
		break;
	case PortB_3:
		GpioValue = TestGPIOB.PUPDR.Fields.PIN3;
		break;
	case PortB_4:
		GpioValue = TestGPIOB.PUPDR.Fields.PIN4;
		break;
	case PortB_5:
		GpioValue = TestGPIOB.PUPDR.Fields.PIN5;
		break;
	case PortB_6:
		GpioValue = TestGPIOB.PUPDR.Fields.PIN6;
		break;
	case PortB_7:
		GpioValue = TestGPIOB.PUPDR.Fields.PIN7;
		break;
	case PortB_8:
		GpioValue = TestGPIOB.PUPDR.Fields.PIN8;
		break;
	case PortB_9:
		GpioValue = TestGPIOB.PUPDR.Fields.PIN9;
		break;
	case PortB_10:
		GpioValue = TestGPIOB.PUPDR.Fields.PIN10;
		break;
	case PortB_11:
		GpioValue = TestGPIOB.PUPDR.Fields.PIN11;
		break;
	case PortB_12:
		GpioValue = TestGPIOB.PUPDR.Fields.PIN12;
		break;
	case PortB_13:
		GpioValue = TestGPIOB.PUPDR.Fields.PIN13;
		break;
	case PortB_14:
		GpioValue = TestGPIOB.PUPDR.Fields.PIN14;
		break;
	case PortB_15:
		GpioValue = TestGPIOB.PUPDR.Fields.PIN15;
		break;
	case PortC_0:
		GpioValue = TestGPIOC.PUPDR.Fields.PIN0;
		break;
	case PortC_1:
		GpioValue = TestGPIOC.PUPDR.Fields.PIN1;
		break;
	case PortC_2:
		GpioValue = TestGPIOC.PUPDR.Fields.PIN2;
		break;
	case PortC_3:
		GpioValue = TestGPIOC.PUPDR.Fields.PIN3;
		break;
	case PortC_4:
		GpioValue = TestGPIOC.PUPDR.Fields.PIN4;
		break;
	case PortC_5:
		GpioValue = TestGPIOC.PUPDR.Fields.PIN5;
		break;
	case PortC_6:
		GpioValue = TestGPIOC.PUPDR.Fields.PIN6;
		break;
	case PortC_7:
		GpioValue = TestGPIOC.PUPDR.Fields.PIN7;
		break;
	case PortC_8:
		GpioValue = TestGPIOC.PUPDR.Fields.PIN8;
		break;
	case PortC_9:
		GpioValue = TestGPIOC.PUPDR.Fields.PIN9;
		break;
	case PortC_10:
		GpioValue = TestGPIOC.PUPDR.Fields.PIN10;
		break;
	case PortC_11:
		GpioValue = TestGPIOC.PUPDR.Fields.PIN11;
		break;
	case PortC_12:
		GpioValue = TestGPIOC.PUPDR.Fields.PIN12;
		break;
	case PortC_13:
		GpioValue = TestGPIOC.PUPDR.Fields.PIN13;
		break;
	case PortC_14:
		GpioValue = TestGPIOC.PUPDR.Fields.PIN14;
		break;
	case PortC_15:
		GpioValue = TestGPIOC.PUPDR.Fields.PIN15;
		break;
	case PortD_0:
		GpioValue = TestGPIOD.PUPDR.Fields.PIN0;
		break;
	case PortD_1:
		GpioValue = TestGPIOD.PUPDR.Fields.PIN1;
		break;
	case PortD_2:
		GpioValue = TestGPIOD.PUPDR.Fields.PIN2;
		break;
	case PortD_3:
		GpioValue = TestGPIOD.PUPDR.Fields.PIN3;
		break;
	case PortD_4:
		GpioValue = TestGPIOD.PUPDR.Fields.PIN4;
		break;
	case PortD_5:
		GpioValue = TestGPIOD.PUPDR.Fields.PIN5;
		break;
	case PortD_6:
		GpioValue = TestGPIOD.PUPDR.Fields.PIN6;
		break;
	case PortD_7:
		GpioValue = TestGPIOD.PUPDR.Fields.PIN7;
		break;
	case PortD_8:
		GpioValue = TestGPIOD.PUPDR.Fields.PIN8;
		break;
	case PortD_9:
		GpioValue = TestGPIOD.PUPDR.Fields.PIN9;
		break;
	case PortD_10:
		GpioValue = TestGPIOD.PUPDR.Fields.PIN10;
		break;
	case PortD_11:
		GpioValue = TestGPIOD.PUPDR.Fields.PIN11;
		break;
	case PortD_12:
		GpioValue = TestGPIOD.PUPDR.Fields.PIN12;
		break;
	case PortD_13:
		GpioValue = TestGPIOD.PUPDR.Fields.PIN13;
		break;
	case PortD_14:
		GpioValue = TestGPIOD.PUPDR.Fields.PIN14;
		break;
	case PortD_15:
		GpioValue = TestGPIOD.PUPDR.Fields.PIN15;
		break;
	case PortF_0:
		GpioValue = TestGPIOF.PUPDR.Fields.PIN0;
		break;
	case PortF_1:
		GpioValue = TestGPIOF.PUPDR.Fields.PIN1;
		break;
	case PortF_2:
		GpioValue = TestGPIOF.PUPDR.Fields.PIN2;
		break;
	case PortF_3:
		GpioValue = TestGPIOF.PUPDR.Fields.PIN3;
		break;
	case PortF_4:
		GpioValue = TestGPIOF.PUPDR.Fields.PIN4;
		break;
	case PortF_5:
		GpioValue = TestGPIOF.PUPDR.Fields.PIN5;
		break;
	case PortF_6:
		GpioValue = TestGPIOF.PUPDR.Fields.PIN6;
		break;
	case PortF_7:
		GpioValue = TestGPIOF.PUPDR.Fields.PIN7;
		break;
	case PortF_8:
		GpioValue = TestGPIOF.PUPDR.Fields.PIN8;
		break;
	case PortF_9:
		GpioValue = TestGPIOF.PUPDR.Fields.PIN9;
		break;
	case PortF_10:
		GpioValue = TestGPIOF.PUPDR.Fields.PIN10;
		break;
	case PortF_11:
		GpioValue = TestGPIOF.PUPDR.Fields.PIN11;
		break;
	case PortF_12:
		GpioValue = TestGPIOF.PUPDR.Fields.PIN12;
		break;
	case PortF_13:
		GpioValue = TestGPIOF.PUPDR.Fields.PIN13;
		break;
	case PortF_14:
		GpioValue = TestGPIOF.PUPDR.Fields.PIN14;
		break;
	case PortF_15:
		GpioValue = TestGPIOF.PUPDR.Fields.PIN15;
		break;
	}
	return GpioValue;
}
