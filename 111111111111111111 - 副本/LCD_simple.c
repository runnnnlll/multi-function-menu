#include <REGX52.H>
#include "Delay.h"
// 简化的LCD命令写入函数
void LCD_WriteCommand(unsigned char Command)
{
    P2 = Command;  // 假设P2口连接LCD数据线
    // 简化控制信号时序
    // 根据实际硬件连接调整
}

// 简化的LCD数据写入函数
void LCD_WriteData(unsigned char Data)
{
    P2 = Data;  // 假设P2口连接LCD数据线
    // 简化控制信号时序
}

void LCD_SimpleInit()
{
    // 最简化的初始化序列
    Delay(15);
    LCD_WriteCommand(0x38); // 8位数据接口，2行显示
    Delay(5);
    LCD_WriteCommand(0x0C); // 显示开，光标关
    Delay(5);
    LCD_WriteCommand(0x06); // 文字不动，地址自动+1
    Delay(5);
    LCD_WriteCommand(0x01); // 清屏
    Delay(15);
}

void LCD_ShowCharSimple(unsigned char x, unsigned char y, unsigned char chr)
{
    unsigned char address;
    
    if (y == 0)
        address = 0x80 + x;
    else
        address = 0xC0 + x;
        
    LCD_WriteCommand(address);
    LCD_WriteData(chr);
}