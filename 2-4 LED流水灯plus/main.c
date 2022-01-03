#include <REGX52.H>
#include <INTRINS.H>

void Delaylms(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms){
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
}

void main(){
	unsigned int i,n=0x01;
	while (1){
		if (n==0x00){
			n=0x01;
		}
		i=~n;
		P2=i;
		n=n<<1;
		Delaylms(100);
	}
}