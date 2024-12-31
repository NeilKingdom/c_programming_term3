typedef struct clientInfo {
	int AccNo;
	char firstName[20];
	char lastName[20];
	double accBalance;
} clientInfo;

int textFile();
int updateRecord(int acc_no);
int newRecord(int acc_no, char *fname, char *lname, double balance); 
int deleteRecord(int acc_no); 
