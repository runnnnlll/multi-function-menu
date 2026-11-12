#include <REGX52.H>
#include "Delay.h"
#include "KEY.h"
#include "LCD1602.h"
unsigned char keyb;
unsigned int i=0;
 int cai1()
{
		LCD_Init();
		LCD_ShowString(1,1,"1.LED");
		LCD_ShowString(1,9,"2.UART");
		LCD_ShowString(2,1,"3.TIMER");
		while(1)
		{
			keyb=Key();
			if(keyb==1)
			{
					i++;
					if(i==4)
					{i=1;Delay(10);}
					if(i==1)
					{ 
						LCD_ShowString(1,1,"1.LED*");
						LCD_ShowString(1,9,"2.UART ");
						LCD_ShowString(2,1,"3.TIMER ");
						Delay(10);
					}
					if(i==2)
					{
						LCD_ShowString(1,1,"1.LED ");
						LCD_ShowString(1,9,"2.UART*");
						LCD_ShowString(2,1,"3.TIMER ");
						Delay(10);
					}
					if(i==3)
					{ 
						LCD_ShowString(1,1,"1.LED ");
						LCD_ShowString(1,9,"2.UART ");
						LCD_ShowString(2,1,"3.TIMER*");
						Delay(10);
					}
				}
//			Delay(20);
			if(keyb==2)
			{
				
				if(i==1)
				{
					
			    LCD_Init();					
					return 1;
				}
				if(i==2)
				{
					LCD_Init();
					
					return 2;
				}
				if(i==3)
				{
					LCD_Init();
					
					return 3;
				}
			}

			}
	}