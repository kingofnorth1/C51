#include <REGX52.H>
#include "Delay.h"
#include "Nixie.h"

void main(){
	while(1){
		Nixie(1,1);
		Nixie(2,2);
		Nixie(3,3);
		Nixie(4,4);
		Nixie(8,8);
		Nixie(7,8);
	}
}