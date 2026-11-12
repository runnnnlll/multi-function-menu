#include <REGX52.H>
#include "Delay.h"
#include "key.h"
#include "Timer1.h"
#include "Nixie.h"
#include "LCD1602.h"
sbit LED=P2^0;
unsigned char Counter,Compare;
unsigned char Speed;
unsigned char keyc;
unsigned char PWM()
{
	  LCD_Init();
	  LCD_ShowString(1,1,"PWM");
    Timer1_Init();
	  Compare=5;
    while(1)
    {
        keyc=Key();
			  if(keyc==1)
				{
					Speed++;
					Speed%=4;
					if(Speed==0) {Compare=0;}
					if(Speed==1) {Compare=5;}
					if(Speed==2) {Compare=50;}
					if(Speed==3) {Compare=100;}
				}
			if(keyc==3)
			{	
				Delay(20);
				TR0 = 0;  // 停止定时器
            ET0 = 0;  // 关闭定时器中断
            LED = 1;  // 关闭LED
		  	return 0;
			}
    }
		
		
}
void Timer1_Routine() interrupt 3
	{
		TL1=0x9C;
		TH1=0xFF;
		Counter++;
		Counter%=100;
		if(Counter<Compare)
			LED=0;
		else
			LED=1;
		
		
	}
