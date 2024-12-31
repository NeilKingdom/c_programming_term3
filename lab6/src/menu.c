#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "make_account.h"

/**************************************************************************
Author: Neil Kingdom
Studnt #: 040967309
Assign #: 6 - Transaction Processing (Random Access Files)
Course: CST8234_010 - C Language
Prof: Surbhi Bahri
Due: 2020/12/07
Submitted: 2020/12/06
Files: menu.c, makeaccounts.c, makeaccounts.h, makefile
**************************************************************************/
int prompt(int floor, int ceil, int digits);

/**************************************************************************
Function: prompt
Author: Neil Kingdom
Version: 1.0
Params: floor - minimum value to be entered, ceil - max value to be
	entered, digits - the expected number of digits required
Returns: Returns filtered input
Purpose: This function is used for limiting user input when it comes to
	entering integer values eg. for the menu or for user account #s
**************************************************************************/
int prompt(int floor, int ceil, int digits) {
   int len, i, exit, rtn = 0;
   char buff[100];
   char *input;

	do {
		exit = 0;
   	input = fgets(buff, sizeof(buff), stdin);
   	len = strlen(input)-1;

      /*Check if input has too many digits*/
      if(len > digits) {
         printf("Input has more digits than expected.\nPlease try again: ");
			exit = 1;
      }

		/*Check if any characters exist*/
		if(exit == 0) {
			for(i = 0; i < len; i++) {
				if(*(input+i) < '0' || *(input+i) > '9') {
					printf("Must enter a valid integer.\nPlease try again: ");
					exit = 1;
					break;
				}
			}
		}

		/*Put string into integer form*/
		if(exit == 0) {
			rtn = i = 0;
			len = strlen(input)-1;
			while(i < len) {
				rtn += pow(10, i) * (input[len-i-1]-'0');
				i++;
			}
		}

		if(exit == 0 && (rtn < floor || rtn > ceil)) {
			printf("Number is out of bounds.\nPlease try again: ");
			exit = 1;
		}
   } while(exit);

	fflush(stdout);
   return rtn;
}

/**************************************************************************
Function: main
Author: Neil Kingdom
Version: 1.0
Params: N/A
Returns: Returns the exit status of the program
Purpose: The main function contains the program loop that will display
	the menu and call functions from makeaccounts.h based on user input.
	Before the program loop begins, it also initializes a file 'credit.dat'
**************************************************************************/
int main(void) {
	int i, option, loop = 1, acc_no = 0;
	char fname[20], lname[20], c;
	double balance;
	FILE *fp;
	clientInfo randomClient = {0, "", "", 0.0};

	/******* INIT CREDIT.DAT *******/
	if((fp = fopen("credit.dat", "wb")) == NULL) {
		printf("Error opening file 'credit.dat'\n");
	}
	else {
		for(i = 1; i <= 100; i++) {
			fwrite(&randomClient, sizeof(clientInfo), 1, fp);
		}
		fclose(fp);
	}

	/************* MENU **************/
	while(loop) {
		printf("\n");
		printf("1) Create formatted list of all accounts\n");
		printf("2) Update an existing account\n");
		printf("3) Add a new account\n");
		printf("4) Delete an existing record\n");
		printf("5) Exit\n");
		printf("Please make your selection: ");
		option = prompt(1, 5, 1);

		switch(option) {
			case 1:
				textFile();
				break;
			case 2:
				printf("Please enter the account number that you would like to update (1-100): ");
				acc_no = prompt(1, 100, 3);
				updateRecord(acc_no);
				break;
			case 3:
   			if((fp = fopen("credit.dat", "r")) == NULL) {
      			printf("Could not open file 'credit.dat'\n");
      			fclose(fp);
					break;
   			}

   			/*Check if record already exists*/
				printf("Please enter the account number for the new client (1-100): ");
				acc_no = prompt(1, 100, 3);
   			fseek(fp, acc_no * sizeof(clientInfo), SEEK_SET);
   			fread(&randomClient, sizeof(clientInfo), 1, fp);

   			if(randomClient.AccNo != 0) {
      			printf("Account %d already exists and cannot be overwitten\n", acc_no);
      			fclose(fp);
					break;
   			}

				printf("Please enter the first name of the client: ");
				scanf("%s", fname);
				printf("Please enter the first name of the client: ");
				scanf("%s", lname);
				printf("Please enter the account balance of the client: ");
				scanf("%lf", &balance);
				newRecord(acc_no, fname, lname, balance);
				/*Function seems to have issues with left over chars in buffer*/
				while((c = getchar()) != '\n');
				break;
			case 4:
				printf("Please enter the account number of the account you wish to delete (1-100): ");
				acc_no = prompt(1, 100, 3);
				deleteRecord(acc_no);
				break;
			case 5:
				printf("Exiting...\n");
				loop = 0;
				break;
		}
	}
	return 0;
}
