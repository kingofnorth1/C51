#include <REGX52.H>
#include "LCD1602.h"
#include "Delay.h"

int Result;

void main(){
	LCD_Init();
	while (1){
		Result++;
		Delay(200);
		LCD_ShowNum(1,1,Result,3);
	}
}