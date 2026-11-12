#include <REGX52.H>
#include "Delay.h"
#include "KEY.h"
#include "LCD1602.h"
#include "cai1.h"

sbit one = P2^1;  // 第一个灯

int light()
{
    unsigned char state=1;//和one状态同
    
    LCD_Init();
    LCD_ShowString(1,1,"Light");
    one = 1; //灭
    while(1)
    {			
        if(P3_1==0)
        {	
            Delay(20);// 消抖
            if(P3_1==0)//再确认
            {
                state = !state;
                if(state)
                {
                    one=1;//LED亮
                }
                else
                {
                    one=0;//灭
                }
                while(P3_1==0)//等释放
                {
                    Delay(10);
                }
                Delay(20);  //消抖
            }
        }
        if(P3_2==0)
        {	
            Delay(20);//消抖
            if(P3_2==0)//再确认
            {
              while(P3_2==0)//等释放
               {
                    Delay(10);
               }
                Delay(20);//释放消抖
                one = 1;//灭了
                return 0;
            }
        }
    }
}