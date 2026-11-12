#include <REGX52.H>
#include "Delay.h"
#include "KEY.h"
#include "LCD1602.h"
#include "cai1.h"
void UART_Init()		
{
	SCON = 0x50;//40变50 电脑接收	
	PCON |= 0x80;		
	TMOD &= 0x0F;		
	TMOD |= 0x20;		
	TL1 = 0xF4;		
	TH1 = 0xF4;		
	ET1 = 0;		
	TR1 = 1;	
EA=1;//ZHONGDUAN
ES=1;	
}

void UART_SendByte(unsigned char Byte)
{
	SBUF = Byte;
	while(TI == 0);	
	TI = 0;//发送
}

int send()
{
	unsigned char keyd;
	UART_Init();
	while(1)
	{
		LCD_Init();
		LCD_ShowString(1,1,"send");
		keyd=Key();
		if(keyd==3)
        {	
            if(keyd==3)//再确认
            {
										 return 0;
            }
        }
	}
}
void UART_Routine() interrupt 4
{
	if(RI==1)//接受
	{
		UART_SendByte(SBUF);
		RI=0;
	}
}