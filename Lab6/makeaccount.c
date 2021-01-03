#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "makeaccount.h"

#define LEN	sizeof(clientInfo)

/********************************************************************************************
File: makeaccounts.c
Version: 1.0
Author: Neil Kingdom
Student #: 040967309
Course: C Language
Lab Section: CST8234_010
Assign #: 6 - Transaction Processing (Random Access Files)
Due: 2020/12/07
Submitted: 2020/12/06
Prof: Surbhi Bahri
Purpose: This file contains functions for managing user's banking accounts. It contains
	functions for exporting data, account creation, account deletion, and account updating
********************************************************************************************/

/********************************************************************************************
Function: textFile
Author: Neil Kingdom
Version: 1.0
Params: N/A 
Returns: Returns the exit status of the function
Purpose: This function exports the properly fomatted account data held in the binary file 
	'credit.dat' to a new text file 'accounts.txt'. If the file accounts.txt does not exist
	it is created before the export. Additionally, it overwrites any previously existing
	information with the information it recieves from credit.dat
********************************************************************************************/
int textFile() {
	int i;
	FILE *out, *in;
	clientInfo temp;

	if((in = fopen("credit.dat", "rb")) == NULL) {
		printf("Could not open file 'credit.dat'\n");
		fclose(in);
		return -1;
	}

	if((out = fopen("accounts.txt", "w")) == NULL) {
		printf("Could not open file 'accounts.txt'\n");
		fclose(out);
		return -1;
	}

	/*Write client accounts to accounts.txt*/
	fputs("Acc No.\t\tLast Name\tFirst Name\tBalance\n", out);
	for(i = 1; i <= 100+1; i++) {
		fread(&temp, LEN, 1, in); 
		if(temp.AccNo != 0)
			fprintf(out, "%d\t\t%s\t\t%s\t\t%.2f\n", temp.AccNo, temp.lastName, temp.firstName, temp.accBalance);
	}	

	fclose(in);
	fclose(out);
	
	printf("Accounts were successfully output to accounts.txt\n");	
	return 0;
}

/********************************************************************************************
Function: updateRecord
Author: Neil Kingdom
Version: 1.0
Params: acc_no - the account number belonging to the user to be updated 
Returns: Returns the exit status of the function
Purpose: This function updates existing account balances. It first seeks the account using
	the user's account no. as an offset, then overwrites it with the changes made by the
	user. The function first checks that the account exists before updating. 
********************************************************************************************/
int updateRecord(int acc_no) {
	FILE *fp;
	char sign, c;
	double balance;
	clientInfo update;

	if((fp = fopen("credit.dat", "rb+")) == NULL) {
		printf("Could not open file 'credit.dat'\n");
		fclose(fp);
		return -1;
	}

	/*Check if record exists*/		
	fseek(fp, acc_no * LEN, SEEK_SET);
	fread(&update, LEN, 1, fp);

	if(update.AccNo == 0) {
		printf("Account %d does not exist\n", acc_no);
		fclose(fp);
		return -1;
	}

	/*Update data*/
	else {
		printf("%d\t%s %s\t%.2f\n", acc_no, update.firstName, update.lastName, update.accBalance);
		printf("Enter charge(+) or payment(-): ");
		scanf("%c%lf", &sign, &balance);

		/*eat buffer chars*/
		while((c = getchar()) != '\n');

		if(sign == '+') {
			printf("Added %.2f to account balance\n", balance);
			update.accBalance += balance;
   	}   
		else if(sign == '-') {
			printf("Subtracted %.2f from account balance\n", balance);
			update.accBalance -= balance;
		}
		printf("%d\t%s %s\t%.2f\n", acc_no, update.firstName, update.lastName, update.accBalance);
	}

	fseek(fp, acc_no * LEN, SEEK_SET); 
	if(fwrite(&update, LEN, 1, fp) > 0) {
		printf("Account successfully updated\n");
	}
   else {
   	printf("Could not update account!\n"); 
	}

	fclose(fp);
	return 0;
}

/********************************************************************************************
Function: newRecord
Author: Neil Kingdom
Version: 1.0
Params: acc_no - the account number for the new user, fname - the first name of the new
	user, lname - the last name of the new user, balance - the initial balance of the new
	user 
Returns: Returns the exit status of the function
Purpose: This function adds a new account into credit.dat. menu.c first checks that the
	account does not already exist so that no accounts are overwritten. If the poisiton is
	available in the file, it is randomly accessed and the new user is written at the 
	correct offset 
********************************************************************************************/
int newRecord(int acc_no, char *fname, char *lname, double balance) {
	FILE *fp;
	clientInfo add;

	if((fp = fopen("credit.dat", "rb+")) == NULL) {
		printf("Could not open file 'credit.dat'\n");
		fclose(fp);
		return -1;
	}

	fseek(fp, acc_no * LEN, SEEK_SET);
	fread(&add, LEN, 1, fp);

	/*Add the data to the account*/
	add.AccNo = acc_no;
	strcpy(add.firstName, fname);
	strcpy(add.lastName, lname);
	add.accBalance = balance;

	fseek(fp, acc_no * LEN, SEEK_SET); /*fp incremented after fread*/
	if(fwrite(&add, LEN, 1, fp) > 0) {
		printf("Account successfully added to credit.dat\n");
	}
   else {
   	printf("Could not write to file!\n"); 
	}

	fclose(fp);
	return 0;
}

/********************************************************************************************
Function: deleteRecord
Author: Neil Kingdom
Version: 1.0
Params: acc_no - the account number belonging to the user to be deleted
Returns: Returns the exit status of the function
Purpose: This function deletes an existing account from credit.dat. First, it checks that
	the account exists, and if so, overwrites that location with an initalized struct of
	type clientInfo with 0 as the new account number. This effectively 'removes' the account
********************************************************************************************/
int deleteRecord(int acc_no) {
	FILE *fp;
	clientInfo delete;
	
	if((fp = fopen("credit.dat", "rb+")) == NULL) {
		printf("Could not open file 'credit.dat'\n");
		fclose(fp);
		return -1;
	} 

	fseek(fp, acc_no * LEN, SEEK_SET);
	fread(&delete, LEN, 1, fp);

	if(delete.AccNo == 0) {
		printf("Account %d does not exist\n", acc_no);
		fclose(fp);
		return -1;
	}

	/*Modify account*/
	delete.AccNo = 0;
	strcpy(delete.firstName, "");
	strcpy(delete.lastName, "");
	delete.accBalance = 0.0;
	
	/*Reinitialize account*/
	fseek(fp, acc_no * LEN, SEEK_SET);
	if(fwrite(&delete, LEN, 1, fp) > 0) {
		printf("Account successfully deleted from credit.dat\n");
	}
   else {
   	printf("Could not delete entry!\n"); 
	}

	fclose(fp);
	return 0;
}
