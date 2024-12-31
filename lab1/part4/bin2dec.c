#include <stdio.h> 
#include <math.h>

int main(void) {
	long n1, n2;
	int dec = 0, p = 0, rem;
	printf("Enter a binary number: ");
	scanf("%ld", &n1);
	n2 = n1;
	while(n1 != 0) {
		rem = n1 % 10;	
		dec += rem * pow(2, p);
		n1 /= 10;
		++p; /* p is the current binary position */
	}
	printf("The decimal equivellant of %ld is: %d\n", n2, dec);
	return 0;
}
