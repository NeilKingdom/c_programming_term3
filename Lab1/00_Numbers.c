#include <stdio.h>

int main(void) {
	int i;
	for(i = 1; i <= 100; i++) {
		if(!(i%3) && !(i%5)) {
			printf("%d I'm a multiple of 3 && 5!!!\n", i);
		}
		else if(!(i%3)) {
			printf("%d I'm a multiple of 3!!!\n", i);
		}
		else if(!(i%5)) {
			printf("%d I'm a multiple of 5!!!\n", i);
		}
		else {
			printf("%d\n", i);
		}
	}
	return 0;
} 
