/*
	S/N: 040967309
	Name: Neil Kingdom
	Assignment: 02_CST8234_Net_Crypto
	Course: C Language
	Lab section: 20F_CST8234_010
	Prof: Surbhi Bahri
	Due: 2020/10/05
	Submission date: 2020/10/05
	Files:
		- crypto.c
		- decrypt.c
		- stdio.h
		- stdlib.h
		- math.h
	Purpose: This program mathematically decypts a 4 digit
		decimal number which has been encrypted by crypto.c
		The user must still input the encrypted number via
		scanf
*/

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define DIGITS 4

int decrypt(int input);

/*******************************************************************
	Name: decrypt
	Purpose: This method handles the math for reversing the
		encrypted number.
	Parameters: int input - The user input passed in from
		main
	Return: Returns exit status. This function always
		returns EXIT_SUCCESS (defined as 1 in stdlib)
	Version: 1.0
	Author: Neil Kingdom
*******************************************************************/
int decrypt(int input) {

	int rem, temp, i, j;
	int store[DIGITS];
	
	temp = input;
	i = DIGITS-1;
	while(temp != 0) {
		rem = temp % 10;
		store[i] = (rem + 3) % 10;
		temp /= 10;
		i--;
	}

	/*Swap 1st with 3rd, then 2nd with 4th*/
	temp = store[0];
	store[0] = store[2];
	store[2] = temp;

	temp = store[1];
	store[1] = store[3];
	store[3] = temp;

	/*Convert index values back to an integer*/
	temp = 0;
	for(i = 0, j = DIGITS-1; i < DIGITS; i++) {
		temp += store[i] * pow(10, j);
		j--;
	}

	printf("Decrypted number of %d is %d\n", input, temp);
	return EXIT_SUCCESS;
}

/*******************************************************************
	Name: main
	Purpose: The main method accepts user input through scanf, checks
		if it is a valid length, and then either return EXIT_FAILURE,
		or passes it on to crypto to be encrypted.
	Parameters: N/A
	Return: Returns the exit status. This function will return 
		EXIT_FAILURE if the integer is too long or too short
	Version: 1.0
	Author: Neil Kingdom
*******************************************************************/
int main(void) {

	int input, temp, i = 0;
	printf("Enter a 4 digit integer number: ");
	scanf("%d", &input);
	temp = input;

	while(temp != 0) {
		temp /= 10;
		i++;
	}

	if(i > DIGITS) {
		printf("Invalid number of digits %d in %d\n", i, input);
		return EXIT_FAILURE;
	}

	decrypt(input);
	return 0;
}
