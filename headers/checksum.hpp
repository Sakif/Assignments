#include <stdio.h>

int xorSum(){
	auto f=fopen ("Checksum.txt","r");
	auto sum=fgetc(f);
	auto nextchar=fgetc(f);
	while(nextchar!=EOF){
		sum^=nextchar;
		nextchar=fgetc(f);
	}
	fclose(f);
	return sum;
}