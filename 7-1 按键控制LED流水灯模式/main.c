#include <REGX52.H>  
#include "Timer0.h"
#include "Key.h"
#include <INTRINS.H>


unsigned char KeyNum,LEDMode;
void main(){
	P2=0xFE;
	Timer0Init();
	while (1){
		KeyNum=Key();
		if (KeyNum){
			if (KeyNum==1){  //当独立按键按下时,则LEDMode加1,
				LEDMode++;   //因此中断查询时LEDMode值改变同时改变位移方向
				if (LEDMode>=2)LEDMode=0;
			}
		}
	}
}

void Timer0_Routine() interrupt 1{
	static unsigned int T0Count;
	TL0 = 0x18;		//设置定时初值
	TH0 = 0xFC;		//设置定时初值
	T0Count++;
	if (T0Count>=500){
		T0Count=0; 
		if (LEDMode==0)
			P2=_crol_(P2,1);
		if (LEDMode==1)
			P2=_cror_(P2,1);
	}
}