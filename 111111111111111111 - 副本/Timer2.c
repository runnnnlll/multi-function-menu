
#include <REGX52.H>
void Timer2_Init(void)
{
   
    T2MOD = 0;        
    T2CON = 0;         
    
    RCAP2L = 0x18;      
    RCAP2H = 0xFC; 
    TL2 = 0x18;         
    TH2 = 0xFC;        
    
    TR2 = 1;            
    ET2 = 1;         
    EA = 1;           
}