#include <REGX52.H>
void Timer1_Init(void)
{
		TMOD &= 0x0F;      
    TMOD |= 0x10;     
    TL1 = 0x9C;       
    TH1 = 0xFF;       
    TR1 = 1;          
    ET1 = 1;        
}