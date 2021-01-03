#include <stdlib.h>
#include <time.h>
#include <stdio.h>
#include <string.h>

#include "02_Dice_A.h"

#define WIN 1
#define LOSE 0
#define BOL 1

int playGame(void) 
{

	char enter;
	int d1, d2, nroll = 1, sum = 0, pep = 0;	

	printf("ROLL THE DICE [ENTER]\n");
	printf("=====================================================\n");
	printf("      ROLL     DICE 1        DICE 2     TOTAL      PEP\n");
	printf("====================================================\n");

   enter	= getchar();
	if(enter == 'q') 
		return -1;	

	d1 = rollDice();
	d2 = rollDice();
	sum = d1+d2;
	pep = sum;

	printf("        %d           %d          %d           %d         %d", nroll, d1, d2, sum, pep);




	if(sum == 7 || sum == 11) 
	{
		printf("\n");
		printf("you rolled a %d and won on your first try\n", sum);
		return WIN;
	}

	else if(sum == 2 || sum == 3 || sum == 12) 
	{
		printf("\n");
		printf("you rolled a %d and lost\n", sum);
		return LOSE;
	}
	
	else 
	{
		while(BOL) 
	{
   
		enter	= getchar();
		if(enter == 'q') 
				return -1;	

			d1 = rollDice();
			d2 = rollDice();
			sum = d1+d2;
			nroll++;
	
			

		printf("        %d           %d          %d           %d         %d", nroll, d1, d2, sum, pep);




			if(sum == 7 || sum == 11 || sum == pep) 
			{
				printf("\n");
				printf("you rolled a %d and won\n", sum);
				return WIN;
			}


			else if(sum == 2 || sum == 3 || sum == 12) 
			{
				printf("\n");
				printf("you rolled a %d and lost\n", sum);
				return LOSE;
			}
		}
		printf("        %d           %d          %d           %d         %d", nroll, d1, d2, sum, pep);
	}
}

int rollDice(void) 
{
	int random =  rand()%6+1;
	return random;
}

int main(void) 
{

	char play;
	int games_won = 0, games_lost = 0, status;	

	status = playGame();

	if(status == LOSE) 
	{
		games_lost++;
	}

	else if(status == WIN) {
		games_won++;
	}

	else

	 {
		printf("\nThank you for playing!\nYou won %d games and lost %d games!\n", games_won, games_lost);
		return EXIT_SUCCESS;

	}

	

while(BOL) 
{
		printf("Play another game? [Y/N]: ");

		play = getchar();
		while(play != 'n' && play != 'y') 
		{
				printf("Invalid:\n ");
				play = getchar();
		}	


		switch(play) 
		{

			case 'y':
				status = playGame();	
				if(status == LOSE) 
				{
					games_lost++;
				}
				else if(status == WIN) 
				{
					games_won++;
				}
				else
					{
					printf("\nThank you for playing\n");
					printf("You won %d games and lost %d games!\n", games_won, games_lost);
					return EXIT_SUCCESS;
				}
			break;

			case 'n':
				printf("\nThank you for playing\n");
				printf("You won %d games and lost %d games!\n", games_won, games_lost);
				return EXIT_SUCCESS;
		}
	}
}
