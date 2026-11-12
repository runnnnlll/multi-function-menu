#include <REGX52.H>
#include "Delay.h"
#include "KEY.h"
#include "LCD1602.h"
#include "cai1.h"
#include "Timer2.h"
unsigned char asec=0, amin=0, ahour=0;
unsigned char change=0; 
unsigned int time_count = 0; 
int clock()
{
    unsigned char keyh;
    LCD_Init();
		Timer2_Init();
    LCD_ShowString(1,1,"Clock:");	
    LCD_ShowString(2,1,"  :  :");
    
    while(1)
    {
			  keyh = Key();
        LCD_ShowNum(2,1,ahour,2);	
        LCD_ShowNum(2,4,amin,2);
        LCD_ShowNum(2,7,asec,2);
        if(keyh==1)
        {
            change++;
            if(change>3) 
						change=0;
            if(change==0) 
						{	
							LCD_ShowString(1,10,"r");
							
						}
            else if(change==1) 
						LCD_ShowString(1,10,"h");//我选小时
            else if(change==2) 
						LCD_ShowString(1,10,"m");//分钟
            else LCD_ShowString(1,10,"s");//秒
        }
        
          if(change!=0)
        {
								if(keyh==2)//加佳佳
								{
										if(change== 1) 
								 { 
									 ahour++; 
									 if(ahour>=24) 
										ahour=0; 
								 }//控制小时加
										else if(change== 2) 
								{ 
										amin++; 
										if(amin>=60) 
										amin=0; 
								}//控制分钟加
										else if(change== 3) 
									{ 
											asec++;
											if(asec>=60)
											asec=0; 
									}//控制秒加
            }
            if(keyh==3)  //减减减
            {
									if(change== 1) 
									{ 
										if(ahour==0)
										ahour=23; 
										else ahour--; 
									}//控制小时减
									
									else if(change== 2) 
								 { 
									 if(amin==0)
									 amin=59;
									 else amin--;
								 }//控制分钟减
								 
									else if(change== 3) 
									{ if(asec==0) 
										asec=59; 
										else asec--;
									}//控制秒减
								 Delay(200);
            }
        }
        
        Delay(200);
				if(keyh==4)
       {	
            if(keyh==4)
           {
										 return 0;
            }
        }
    }
    
    return 0;
}
void Timer2_ISR() interrupt 5
{
    static unsigned int count;
    

    if(TF2 == 1)        
    {
        TF2 = 0;      
    }
    else if(EXF2 == 1)  
    {
        EXF2 = 0;       
    }
    
    count++;
    

    if(count >= 1000)
    {
        count = 0;
        
        if(change == 0)
        {
            asec++;
            if(asec >= 60)
            {
                asec = 0;
                amin++;
                if(amin >= 60)
                {
                    amin = 0;
                    ahour++;
                    if(ahour >= 24)
                    {
                        ahour = 0;
                    }
                }
            }
        }
    }
}