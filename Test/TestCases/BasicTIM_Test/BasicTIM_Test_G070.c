/*
 * BasicTIM_Test_G070.c
 *
 *  Created on: 2020. okt. 9.
 *      Author: BodnarB
 */

#define TEST_CASE
#include "TestEnv.h"

void BasicTIM_Test(void);

void TestInterrupt(void);

void BasicTIM_Test(void)
{
	dtBasicTimConfig Config;

	int looper1;
	int looper2;
	int looper3;
	int looper4;
	int looper5;
	int looper6;
	int looper7;
	int looper8;

	for(Config.ARPreload = 0, looper1 = 0; looper1 < 2; looper1++, Config.ARPreload++)
	{
		for(Config.Enable = 0, looper2 = 0; looper2 < 2; looper2++, Config.Enable++)
		{
			for(Config.OnePulse = 0, looper3 = 0; looper3 < 2; looper3++, Config.OnePulse++)
			{
				for(Config.UpdateDisable = 0, looper4 = 0; looper4 < 2; looper4++, Config.UpdateDisable++)
				{
					for(Config.UpdateSource = 0, looper5 = 0; looper5 < 2; looper5++, Config.UpdateSource++)
					{
						for(Config.AutoReload = 0, looper6 = 0; looper6 < 65536; looper6+=64, Config.AutoReload++)
						{
							for(Config.Prescaler = 0, looper7 = 0; looper7 < 65536; looper7+=64, Config.Prescaler)
							{
								for(looper8 = 0; looper8 < 2; looper8++)
								{
									MemClear(&TestBasicTIM6, sizeof(TestBasicTIM6));
									ASSERT_EQ(TestBasicTIM6.CR1.Fields.CEN, 0);
									ASSERT_EQ(TestBasicTIM6.CR1.Fields.UDIS, 0);
									ASSERT_EQ(TestBasicTIM6.CR1.Fields.URS, 0);
									ASSERT_EQ(TestBasicTIM6.CR1.Fields.OPM, 0);
									ASSERT_EQ(TestBasicTIM6.CR1.Fields.ARPE, 0);
									ASSERT_EQ(TestBasicTIM6.ARR.Fields.ARR, 0);
									ASSERT_EQ(TestBasicTIM6.PSC.Fields.PSC, 0);
									ASSERT_EQ(TestBasicTIM6.DIER.Fields.UIE, 0);
									ASSERT_EQ(TestBasicTIM6.DIER.Fields.UDE, 0);
									if(looper8 == 0) BasicTIM_Set(TIM6, Config, 0);
									else BasicTIM_Set(TIM6, Config, &TestInterrupt);
									if(Config.ARPreload != 0) ASSERT_EQ(TestBasicTIM6.CR1.Fields.ARPE, 1);
									else ASSERT_EQ(TestBasicTIM6.CR1.Fields.ARPE, 0);
									if(Config.Enable != 0) ASSERT_EQ(TestBasicTIM6.CR1.Fields.CEN, 1);
									else ASSERT_EQ(TestBasicTIM6.CR1.Fields.CEN, 0);
									if(Config.OnePulse != 0) ASSERT_EQ(TestBasicTIM6.CR1.Fields.OPM, 1);
									else ASSERT_EQ(TestBasicTIM6.CR1.Fields.OPM, 0);
									if(Config.UpdateDisable != 0) ASSERT_EQ(TestBasicTIM6.CR1.Fields.UDIS, 1);
									else ASSERT_EQ(TestBasicTIM6.CR1.Fields.UDIS, 0);
									if(Config.UpdateSource != 0) ASSERT_EQ(TestBasicTIM6.CR1.Fields.URS, 1);
									else ASSERT_EQ(TestBasicTIM6.CR1.Fields.URS, 0);
									ASSERT_EQ(TestBasicTIM6.ARR.Fields.ARR, Config.AutoReload);
									ASSERT_EQ(TestBasicTIM6.PSC.Fields.PSC, Config.Prescaler);
									if(looper8 == 0) ASSERT_EQ(TestBasicTIM6.DIER.Fields.UIE, 0);
									else
									{
										ASSERT_EQ(TestBasicTIM6.DIER.Fields.UIE, 1);
									}
								}
							}
						}
					}
				}
			}
		}
	}

	for(Config.ARPreload = 0, looper1 = 0; looper1 < 2; looper1++, Config.ARPreload++)
	{
		for(Config.Enable = 0, looper2 = 0; looper2 < 2; looper2++, Config.Enable++)
		{
			for(Config.OnePulse = 0, looper3 = 0; looper3 < 2; looper3++, Config.OnePulse++)
			{
				for(Config.UpdateDisable = 0, looper4 = 0; looper4 < 2; looper4++, Config.UpdateDisable++)
				{
					for(Config.UpdateSource = 0, looper5 = 0; looper5 < 2; looper5++, Config.UpdateSource++)
					{
						for(Config.AutoReload = 0, looper6 = 0; looper6 < 65536; looper6+=32, Config.AutoReload++)
						{
							for(Config.Prescaler = 0, looper7 = 0; looper7 < 65536; looper7+=32, Config.Prescaler)
							{
								for(looper8 = 0; looper8 < 2; looper8++)
								{
									MemClear(&TestBasicTIM7, sizeof(TestBasicTIM7));
									ASSERT_EQ(TestBasicTIM7.CR1.Fields.CEN, 0);
									ASSERT_EQ(TestBasicTIM7.CR1.Fields.UDIS, 0);
									ASSERT_EQ(TestBasicTIM7.CR1.Fields.URS, 0);
									ASSERT_EQ(TestBasicTIM7.CR1.Fields.OPM, 0);
									ASSERT_EQ(TestBasicTIM7.CR1.Fields.ARPE, 0);
									ASSERT_EQ(TestBasicTIM7.ARR.Fields.ARR, 0);
									ASSERT_EQ(TestBasicTIM7.PSC.Fields.PSC, 0);
									ASSERT_EQ(TestBasicTIM7.DIER.Fields.UIE, 0);
									ASSERT_EQ(TestBasicTIM7.DIER.Fields.UDE, 0);
									if(looper8 == 0) BasicTIM_Set(TIM7, Config, 0);
									else BasicTIM_Set(TIM7, Config, &TestInterrupt);
									if(Config.ARPreload != 0) ASSERT_EQ(TestBasicTIM7.CR1.Fields.ARPE, 1);
									else ASSERT_EQ(TestBasicTIM7.CR1.Fields.ARPE, 0);
									if(Config.Enable != 0) ASSERT_EQ(TestBasicTIM7.CR1.Fields.CEN, 1);
									else ASSERT_EQ(TestBasicTIM7.CR1.Fields.CEN, 0);
									if(Config.OnePulse != 0) ASSERT_EQ(TestBasicTIM7.CR1.Fields.OPM, 1);
									else ASSERT_EQ(TestBasicTIM7.CR1.Fields.OPM, 0);
									if(Config.UpdateDisable != 0) ASSERT_EQ(TestBasicTIM7.CR1.Fields.UDIS, 1);
									else ASSERT_EQ(TestBasicTIM7.CR1.Fields.UDIS, 0);
									if(Config.UpdateSource != 0) ASSERT_EQ(TestBasicTIM7.CR1.Fields.URS, 1);
									else ASSERT_EQ(TestBasicTIM7.CR1.Fields.URS, 0);
									ASSERT_EQ(TestBasicTIM7.ARR.Fields.ARR, Config.AutoReload);
									ASSERT_EQ(TestBasicTIM7.PSC.Fields.PSC, Config.Prescaler);
									if(looper8 == 0) ASSERT_EQ(TestBasicTIM7.DIER.Fields.UIE, 0);
									else ASSERT_EQ(TestBasicTIM7.DIER.Fields.UIE, 1);
								}
							}
						}
					}
				}
			}
		}
	}
}


void TestInterrupt(void)
{

}
