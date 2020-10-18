#include <stdio.h>
#include <stdlib.h>
#include <math.h>
/**************************************************************************
File: connect.c
All source files: connect.c
Version: 1.0
Author: Neil Kingdom
Student number: 040967309
Course: C Language
Lab section: 20F_CST8234_010 
Assignment #: 3
Assignment Name: Connectivity Problem
Due Date: 2020/10/19
Submission Date: 2020/10/18
Professor: Surbhi Bahri
Purpose: This program was created for the purpose of solving the
	connectivity problem. The program connects 'nodes' represented as
	integer values. If two nodes are connected, they will share the same
	integer value. The node matrix is displayed once the array is full.
**************************************************************************/

/**************************************************************************
Function: main
Version: 1.0
Author: Neil Kingdom
Param: void - Accepts no arguments
Return: Returns the exit status of the program. 
Purpose: In this program, the main function provides all functionality
	for the program. This includes the menu system and program logic. 
	Due to personal preference, I have chosen to use a pointer which will
	act as an array, rather than an actual array.
**************************************************************************/
int main(void) {
	
	const int N = 10;	
	int *id, *pa, *qa;
	int input, i, j, ln = 1, s = 0;

	/*Initialize arrays properly*/
	id = malloc(pow((sizeof(int) * N), 2));
	pa = malloc(sizeof(int) * N);
	qa = malloc(sizeof(int) * N);

	for(j = 0; j < N; j++) {
		*(id + j) = j;
		printf("%d ", *(id + j));
	}	
	
	i = 1;
	*pa = 0;
	*qa = 0;

	printf("\nEnter p: ");
	while(i <= (N+1) && (scanf("%d", &input) != EOF)) {

		if(!s) {	
			while(input < 0 || input >= N) {
				printf("%d is out of bounds, please try again: ", input);
				scanf("%d", &input);
			}
			*(pa + i) = input;
			s++;
			printf("Enter q: ");
		}
		else {
			while(input < 0 || input >= N) {
				printf("%d is out of bounds, please try again: ", input);
				scanf("%d", &input);
			}
			*(qa + i) = input;

			/*Set current row equal to previous row*/	
			for(j = 0; j < N; j++)
				*(id + i*N + j) = *(id + (i-1)*N + j);

			for(j = 0; j < N; j++) {
				/*Set all values of id[i][j] that are equal to id[i-1] at column pa[i] = value of id[i-1] at column qa[i]*/
				if(*(id + i*N + j) == *(id + (i-1)*N + *(pa + i))) 
					*(id + i*N + j) = *(id + (i-1)*N + *(qa + i)); 
				printf("%d ", *(id + i*N + j));
			}
			s--; i++; ln++;
			printf("\nEnter p: ");
		}
	}

	printf("\n\np\tq\n\n");
	for(i = 0; i < ln; i++) {
		printf("%d\t%d\t", *(pa + i), *(qa + i));
		for(j = 0; j < N; j++) {
			printf("%d ", *(id + i*N + j));
		}
		printf("\n");
	}
	return 0;
}
