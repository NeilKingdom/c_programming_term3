#include <stdio.h>

int main(void) {
	long n1, n2;
	int nc = 0;
	printf("Enter an integer: ");
	scanf("%ld", &n1);
	n2 = n1;
	while(n2 != 0) {
		n2 /= 10;	
		++nc;
	}
	printf("Number of digits in %ld is %d\n", n1, nc);
	return 0;
}
