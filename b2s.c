#include <stdio.h>
#include <stdlib.h>

int main(){
	printf("bin to hex\r\n");
	char buffer[64];
	char *p;
	p = fgets(buffer, sizeof(buffer), stdin);
	if(p){
		unsigned i = strtoul(buffer, &p, 2);
		printf("%x", i);
	}

	return 0;
}