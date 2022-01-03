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
	unsigned int n,i=0x01;
	while (1){
		if (P3_1==0){
			Delay(20);
			while (P3_1==0);
			Delay(20);
			
			if (i==0x00){
				i=0x01;
			}
			n=~i;
			P2=n;
			i=i<<1;
		}
	}
}
	