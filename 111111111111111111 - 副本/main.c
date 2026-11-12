#include <REGX52.H>
#include "Delay.h"
#include "KEY.h"
#include "LCD1602.h"
#include "cai1.h"
unsigned int b=0;
unsigned int c=0;
unsigned int d=0;
void main()
{
	unsigned char menu;


	while(1)
	{
		LCD_Init();
        LCD_ShowString(1,1,"1.LED");
        LCD_ShowString(1,9,"2.UART");
        LCD_ShowString(2,1,"3.TIMER");
        menu = cai1();
		Delay(200);
		if(menu==1)
			{
			  LCD_ShowString(1,1,"LED");
	      LCD_ShowString(2,1,"light");
				LCD_ShowString(2,13,"PWM");
		    LED();
			}
		else if(menu==2)
		{
			LCD_ShowString(1,1,"UART");
			LCD_ShowString(2,1,"send");
			LCD_ShowString(2,8,"rec");
		  UART1();
		}
		else if(menu==3)
		{
			LCD_ShowString(1,1,"TIMER");
			LCD_ShowString(2,1,"timers");
			LCD_ShowString(2,9,"clock");
			TIMER();
		}
	}
		
}
int LED()
			{
				unsigned char keyb;
				while(1)
				{
					keyb=Key();
					if(keyb==1)
		     {
					b++;
					if(b==3)
					{b=1;Delay(10);}
					if(b==1)
					{ 
						LCD_ShowString(2,6,"*");
						LCD_ShowString(2,16," ");
						Delay(10);
					}
					if(b==2)
					{
						LCD_ShowString(2,6," ");
						LCD_ShowString(2,16,"*");
						Delay(10);
					}
					
				}
				 	if(keyb==2)
				{
					if(b==1)
					{
						light();
						 LCD_ShowString(1,1,"LED           ");
             LCD_ShowString(2,1,"light*");
             LCD_ShowString(2,13,"PWM ");
						b=1;
					}
					if(b==2)
					{
						PWM();
						LCD_ShowString(1,1,"LED           ");
                LCD_ShowString(2,1,"light ");
                LCD_ShowString(2,13,"PWM*");
                b = 2;
					}
					
				}
				if(keyb==3)
			  {	
			  	Delay(20);
		    	return 0;
		 	  }
			}
				
		}
int UART1()
{
	unsigned char keyc;
				while(1)
				{
					keyc=Key();
					if(keyc==1)
		     {
					c++;
					if(c==3)
					{c=1;Delay(10);}
					if(c==1)
					{ 
						LCD_ShowString(2,1,"send*");
						LCD_ShowString(2,8,"rec ");
						Delay(10);
					}
					if(c==2)
					{
						LCD_ShowString(2,1,"send ");
						LCD_ShowString(2,8,"rec*");
						Delay(10);
					}
					
				}
				 	if(keyc==2)
				{
					if(c==1)
					{
				    send();
						LCD_ShowString(1,1,"UART        ");
						LCD_ShowString(2,1,"send*");
		 				LCD_ShowString(2,8,"rec ");
						c=1;
					}
					if(c==2)
					{
						rec();
						LCD_ShowString(1,1,"UART        ");
						LCD_ShowString(2,1,"send ");
						LCD_ShowString(2,8,"rec*");
            c=2;
					}
				}
				if(keyc==3)
			  {	
			  	Delay(20);
		    	return 0;
		 	  }
			}
				
		}
int TIMER()
{
	unsigned char keyf;
				while(1)
				{
					keyf=Key();
					if(keyf==1)
		     {
					d++;
					if(d==3)
					{d=1;Delay(10);}
					if(d==1)
					{ 
						
	      		LCD_ShowString(2,1,"timers*");
			      LCD_ShowString(2,9,"clock ");
						Delay(10);
					}
					if(d==2)
					{
						
	      		LCD_ShowString(2,1,"timers ");
			      LCD_ShowString(2,9,"clock*");
						Delay(10);
					}
					
				}
				 	if(keyf==2)
				{
					if(d==1)
					{
		  	    timers();
						LCD_ShowString(1,1,"TIMER");
						LCD_ShowString(2,1,"timers*");
			      LCD_ShowString(2,7,"  clock ");
						d=1;
					}
					if(d==2)
					{
				  	clock();
						LCD_ShowString(1,1,"TIMER      ");
						LCD_ShowString(2,1,"timers ");
			      LCD_ShowString(2,7,"  clock*");
            d=2;
					}
				}
				if(keyf==3)
			  {	
			  	Delay(20);
		    	return 0;
		 	  }
			}
}