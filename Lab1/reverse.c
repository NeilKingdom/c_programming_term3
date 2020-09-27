#include <stdio.h>

int main(void) {
	int n1, n2 = 0, rem;
	printf("Enter a number: ");
	scanf("%d", &n1);
	while(n1 != 0) {
		rem = n1 % 10;
		n2 = n2 * 10 + rem;
		n1 /= 10;
	}
	printf("The reverse number is: %d\n", n2);
	return 0;
}
