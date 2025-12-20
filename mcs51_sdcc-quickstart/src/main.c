/**
 * CPU: 89C52
 * Freq: 12MHz
*/

#include <reg52.h>
#include <stdio.h>
unsigned char connt = 0 ;
void delay_100ms(void) //@12MHz
{
    unsigned char i, j;

    i = 195;
    j = 138;

    do
    {
        while (--j)
            ;
    } while (--i);
}
void T0_Init(void)
{
    TMOD &= 0xf0 ;
    TMOD &= 0x01 ;
    TCON  = 0x10 ;
    IE    = 0x82 ;
    TH0   = 0xFC ;
    TL0   = 0x18 ;
    TCON  = 0x10 ;
}

void main(void)
{   T0_Init();
    while (1)
    {
    delay_100ms();
    P20 = 1;
    }
}

void T0_timer() interrupt 1 using 0
{   
    connt++ ;
    if(connt >= 200 )
    {
        P20   = 0 ;
        connt = 0 ;
    }
    

    TH0   = 0xFC ;
    TL0   = 0x18 ; 
}
