#include <REGX52.H>

void Delay(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms){
		i = 2;
		j = 230;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
}


void main(){
	static unsigned int LEDnum=0;
	P2=~0x01;
	while (1){
		if (P3_1==0){
			Delay(20);
			while (P3_1==0);
			Delay(20);
			
			if (LEDnum++>=7){
				LEDnum=0;
			}
			P2=~(0x01<<LEDnum);
		} 
		if (P3_0==0){
			Delay(20);
			while (P3_0==0);
			Delay(20);
			
			if (LEDnum--==0){
				LEDnum=7;
			}
			P2=~(0x01<<LEDnum);
		}
	}
}
	