#include <REGX52.H>
#include "Delay.h"
#include "LCD1602.h"
#include "MatrixKey.h"

unsigned char KeyNum;
unsigned int Password,count;

void main(){
	LCD_Init();
	LCD_ShowString(1,1,"Password:");
	while (1){
		KeyNum=MatrixKey();
		if (KeyNum){
			if (KeyNum<=10&&count<4){ //如果s1~s10按键按下,输入密码，如果输入次数小于4
				Password*=10;			//密码左移一位
				Password+=KeyNum%10;	//获取一位密码
				count++;				//计次加一
				LCD_ShowNum(2,1,Password,4);	//更新显示
			}
			if (KeyNum==11){
				if (Password==2345){	//如果密码等于正确密码
	 				LCD_ShowString(1,14,"OK ");	//显示ok
					Password=0;
					count=0;
					Delay(20);
					LCD_ShowNum(2,1,Password,4);	//更新显示
				}
				else {
					LCD_ShowString(1,14,"ERR");
					Password=0;
					count=0;
					Delay(20);
					LCD_ShowNum(2,1,Password,4);	//更新显示
				}
			}
			if (KeyNum==12){	//如果S12按键按下
				Password/=10;
				count=0;
				Delay(20);
				LCD_ShowNum(2,1,Password,4);	//更新显示
			}
		}
	}
}