/*
Name: Simple Tic-tac-toe game designed by C program 
Conversion File Name: 1613453_3.c
Copyright: Free
Author: Zhong Chu
Description:This program allows user to create account and play the game of tic-tac-toe with a computer.
The player can decide whether player or computer plays the first step.
The program can judge which player wins or it is a draw. 
The account will store how many times player wins, losses or reaches a draw after playing tic-tac-toe with computer.
*/

#include<stdio.h>		/*C libraries used in this program */
#include<stdlib.h>		
#include<windows.h>
#include<math.h>
#include<string.h>
#include<time.h> 

#define writer U2FsdGVkX1/v4qz+/9KJbFP1OvcNmsL5iANKrNwzaqVHQn7xg9dKpe9xbLj0hkEiea4WGUeP2IrCxG1TeilkYrDKrAl84RO50HTnMM294AE=
 /*some words using AES encryption algorithm */
 
typedef struct _entry	/*Declare structure type named entry containing a variable for each of the details to be stored*/
{
	char username[31];   /*To store the username*/
	char password[31];	 /*To store the password*/
	int wintime;	   	 /*To store the win time*/
	int losetime;		 /*To store the lose time*/
	int tietime;		 /*To store the tie time*/
}entry;

/*Function protoypes*/
void create();						/*A function to create a new item in the array*/
int Login();					    /*A function to login a new item in the array*/
void list();						  /*A function that lists the whole contents ofthe file*/
int winner(char board[11][11]);       /* Define a function named winner which could judge who is winner*/
int display_board(char board[11][11]);/* Define a function named isplay_board which could display the board*/
int peoplemove(char board[11][11]);	 /* Define a function named peoplemove which could let people make move in the board*/
void computermove(char board[11][11]);/* Define a function named computermove which could let people make move in the board*/
void game( entry *person);		    /* Define a function named game which could let people play game with computer */
void ReadPerson( );/*Define a function named Readperson which could Read all player information from the last saved fil*/
void SavePerson( );/*Define a function named SavePerson which could save this running result to the file*/

entry g_ArrPersons[200];/*To save all the players' information*/
int g_total;/*record the total number of people*/
int g_CurIndex;/*Record the array index of the current player*/
int a;			/* Initialize variable which is used to return the value of scanf*/
int number = 0; /* Initialize variable which is used to collect number*/
int player = 1; /* Represent players as numbers*/
int flag = 0; /* Used later in a while-loop*/
int win = 0; /* Initialize win condition flag*/
int row=0;
int column=0;

int main(int argc, char *argv[])
{
	int flag1 = 0, flag2, option;	/*Declare some integer variables: two used as flags for detecting status and one to accept user input*/
	char again='0';
	
	ReadPerson();                   /*After the program is running, all user information is read from the file and all of the user's information is stored in the array from the file*/

	while (flag1 == 0)				/*enter a while loop to keep the program running till the user selects option 4*/
	{
		Sleep(2000);
		system("cls");
		printf("\nPlease select one of the following options:\n\t1. Create a new entry\n\t2. Login\n\t3. Print all file entries\n\t4. Close the program\n\n");

		while (scanf("%d", &option) != 1 && (option<1 || option>4))		/* Display menu and get user entry - check user entry validity*/
		{
			printf("Invalid entry\n\n");
			Sleep(1000);
			fflush(stdin);
			system("cls");
			printf("Please select one of the following options:\n\t1. Create a new account\n\t2. Login\n\t3. Print all file entries\n\t4. Close the program\n\n");
		}

		switch (option)					/*switch used to perform selection - send the filename*/
		{
		case 1: create();	/*call function create*/
		break;
		case 2: flag2 = Login(/*&person, filename*/);
			again='0';
			if (flag2 == 0)			/*decide if persons details were found and print*/
			{
				system("cls");
		
				printf("Login successfully");
				printf("\n\n%s your win time is %d\nyour lose time is %d\nyour tietime is %d", 
					    g_ArrPersons[g_CurIndex].username,g_ArrPersons[g_CurIndex].wintime,g_ArrPersons[g_CurIndex].losetime,g_ArrPersons[g_CurIndex].tietime);					
				while (again!='2')/* play the game*/
				{
					game(&g_ArrPersons[g_CurIndex]);
					win=0;
					flag=0;
					printf("\n\n%s your win time is %d\nyour lose time is %d\nyour tietime is %d\n", 
						    g_ArrPersons[g_CurIndex].username,g_ArrPersons[g_CurIndex].wintime,g_ArrPersons[g_CurIndex].losetime,g_ArrPersons[g_CurIndex].tietime);
					printf("Do you want to play again\n 1.Yes      2.No\n");
					again=getchar();
					while(again!='1' && again!='2')
					{
						printf("Invalid choice, please enter again.\n");
						printf("Play again? 1.yes     2.no \n");
						again=getchar();
					}
				}
			}
			else
				printf("\n\nThe name does not exist in the system\n\n");
		break;
		case 3: list();	/*call function list - send the filename*/
		break;
		case 4: flag1 = 1; /*set flag 1 to end the program loop and close the program*/
		break;
	
		}

	}

	SavePerson( );/*save all the information before quit the program*/
	printf("\n\nThank you for using the software");
	Sleep(1000);

	return 0;			/*return 0 to the system indicating successful program execution and termination*/
}

void create()		/*function create definition*/
{
	entry person;			/*declare a structure*/
	char searchs[31],searchg[31];/* to store the name and password*/
	
	fflush(stdin);
	system("cls");

	printf("Please enter your name:\n\n\t");			/*Obtain each structure member information checking each for validity*/
	while (scanf("%s", searchs) == 0 || strlen(searchs)>30 )  /*The logic expression is evaluated from left to right so the scanf is evaluated first to ensure the string is read*/
	{																/*the right hand side checks the value obtained by the scanf to ensure the length of the string is less than maximum length*/
		printf("Please try again and make sure the name has less than 30 characters");
		fflush(stdin);
		Sleep(2000);
		system("cls");
		printf("Please enter the your name\n\n\t");
	}

	fflush(stdin);		/*Ensure input buffer is empty*/

	printf("Please enter the password:\n\n\t");
	while (scanf("%s", searchg) == 0 || strlen(searchg)>30)
	{
		printf("Please try again and make sure the password has less than 30 characters");
		fflush(stdin);
		Sleep(2000);
		system("cls");
		printf("Please enter the password:\n\n\t");
	}
	
	int i;
	for(i = 0;i<g_total;++i )/* to search the information in the array*/ 
	{
		if (!(strcmp(g_ArrPersons[i].username, searchs)) )	/*test to see if the loop finished because the name was found*/
		{
			printf("The user has already existed\nPlease try another name\n");
			scanf("%s", person.username);
			printf("Please enter the password\n");
			scanf("%s", person.password);
		}

	}
	strcpy(person.username,searchs);/*Store the contents of searchs in person.username*/
	strcpy(person.password,searchg);/*Store the contents of searchg in person.password*/
	
	person.wintime=0;
	person.losetime=0;
	person.tietime=0;
	
	fflush(stdin);
	
	
	g_ArrPersons[g_total] = person;/*The new created user does not write directly to the file but adds it to the array until the program exits and writes all the user information to the file*/
	g_total++;/*add one to the number of person*/
	printf("Create entry successfully");
}
int Login()
{
	char searchs[31], searchg[31];/* to store the name and password*/
	int i;
	fflush(stdin);

	printf("Please enter your name and password\n");
	while (scanf("%s", searchs) == 0 || strlen(searchs)>30 || scanf("%s", searchg) == 0 || strlen(searchg)>30) /*Test the entry of the persons name*/
	{
		printf("Please try again and make sure the names are seperated by a space and both are less than 30 characters long");
		fflush(stdin);
		Sleep(2000);
		system("cls");
		printf("Please your name and password\n\n");
	}

	fflush(stdin);

	for( i = 0;i<g_total;++i )/* to search the information in the array*/ 
	{
		if (!(strcmp(g_ArrPersons[i].username, searchs)) && !(strcmp(g_ArrPersons[i].password, searchg)))	/*test to see if the loop finished because the name was found*/
		{
			g_CurIndex = i;/*Record the index of the current user's array*/
			return 0;	/*return 0 to indicate the name was found and that the values have been written to the variable in function main*/
		}

	}
	return 1;/*1 means find nothing*/
}

void list()
{
	int i = 0;
	for ( i = 0;i<g_total;++i )/*print out all the information in the array*/
	{
		printf("username:\t\t%s\n", g_ArrPersons[i].username);
		printf("wintime:\t\t%d\n", g_ArrPersons[i].wintime);
		printf("losetime:\t\t%d\n", g_ArrPersons[i].losetime);
		printf("tietime:\t\t%d\n\n", g_ArrPersons[i].tietime);
	}
}
int winner(char board[11][11]) /* Placeholder for winner() function */
{
	int winner_number = 0; /*Returned to main function later*/
	int blank = 0; /* Used to tell if the game is over or there's a tie*/
	int i = 0; /* Initialize loop-counter (used to go through board to detect blank spaces)*/
	int j = 0; /* Initialize loop-counter (used to go through board to detect blank spaces)*/
	if (((board[1][1] == 'X') && (board[1][5] == 'X') && (board[1][9] == 'X')) || /* first row*/
		((board[1][1] == 'X') && (board[5][1] == 'X') && (board[9][1] == 'X')) || /* first column*/
		((board[1][1] == 'X') && (board[5][5] == 'X') && (board[9][9] == 'X')) || /* diagonal 1*/
		((board[5][1] == 'X') && (board[5][5] == 'X') && (board[5][9] == 'X')) || /* second row*/
		((board[9][1] == 'X') && (board[9][5] == 'X') && (board[9][9] == 'X')) || /* third row*/
		((board[1][5] == 'X') && (board[5][5] == 'X') && (board[9][5] == 'X')) || /* second column*/
		((board[1][9] == 'X') && (board[5][9] == 'X') && (board[9][9] == 'X')) || /* third column*/
		((board[1][9] == 'X') && (board[5][5] == 'X') && (board[9][1] == 'X')) /* diagonal 2*/
		)
	{
		winner_number = 1;
	} 
	else if (((board[1][1] == 'O') && (board[1][5] == 'O') && (board[1][9] == 'O')) || /* first row*/
			   ((board[1][1] == 'O') && (board[5][1] == 'O') && (board[9][1] == 'O')) || /* first column*/
			   ((board[1][1] == 'O') && (board[5][5] == 'O') && (board[9][9] == 'O')) || /* diagonal 1*/
			   ((board[5][1] == 'O') && (board[5][5] == 'O') && (board[5][9] == 'O')) || /* second row*/
			   ((board[9][1] == 'O') && (board[9][5] == 'O') && (board[9][9] == 'O')) || /* third row*/
			   ((board[1][5] == 'O') && (board[5][5] == 'O') && (board[9][5] == 'O')) || /* second column*/
			   ((board[1][9] == 'O') && (board[5][9] == 'O') && (board[9][9] == 'O')) || /* third column*/
			   ((board[1][9] == 'O') && (board[5][5] == 'O') && (board[9][1] == 'O')) /* diagonal 2*/
			   )
	{
		winner_number = 2;
	} 
	else 
			 {
					for (i = 1; i < 10; i=i+4) /* Go through each row*/
					{
						for (j = 1; j < 10; j=j+4) /* Go through each column*/
						{
							if (board[i][j] <= '9'&&board[i][j]>='1') 
							{
								blank = 1; /* 1 means there's still a blank*/
							}
						}
					}
					if (blank == 0) 
					{ /* It will still be 0 if no blanks were found*/
						winner_number = 3;
					}
			}
	return winner_number;
}
void game( entry *person)
{
	
	char board[11][11]=
	{
	{' ',' ',' ','#',' ',' ',' ','#',' ',' ',' '} ,
	{' ','1',' ','#',' ','2',' ','#',' ','3',' '} ,
	{' ',' ',' ','#',' ',' ',' ','#',' ',' ',' '} ,
	{'#','#','#','#','#','#','#','#','#','#','#'},
	{' ',' ',' ','#',' ',' ',' ','#',' ',' ',' '} ,
	{' ','4',' ','#',' ','5',' ','#',' ','6',' '} ,
	{' ',' ',' ','#',' ',' ',' ','#',' ',' ',' '} ,
	{'#','#','#','#','#','#','#','#','#','#','#'},
	{' ',' ',' ','#',' ',' ',' ','#',' ',' ',' '} ,
	{' ','7',' ','#',' ','8',' ','#',' ','9',' '} ,
	{' ',' ',' ','#',' ',' ',' ','#',' ',' ',' '} ,
	};     /* Initialize the board*/

	printf("\n Here is a blank Tic-Tac-Toe board for you To play with computer: \n");
	printf("let us choose who play first 1.You       2.Computer\n");
	scanf("%d",&player);
	if(player==1)
		printf("You play first\n");
	else if(player==2)
		printf("The computer play first\n");
	display_board(board); /* Show initial position of board */
	while (win == 0) /* Continue the game until a player wins*/
		{
			while (flag == 0)
			{
				if(player==1)
					peoplemove(board);
				else 
					{
					computermove(board);
					flag=1;
					}
			}
			system("cls");
			printf("\n The board now looks like this: \n");
			display_board(board); /* Update board*/		
			win = winner(board); // Check for winner
			if (win == 1) { /* Function winner() should return 1 if player 1 wins*/
				printf("\n You wins! \n");
				person->wintime++;
			} else if (win == 2) { /* Function winner() should return 2 if player 2 wins*/
				printf("\n Computer wins! \n");
				person->losetime++;
			} else if (win == 3) { /*/ Function winner() should return 3 if it's a tie.*/
				printf("\n It's a tie. \n");
				person->tietime++;
			} else {
				flag = 0; /* Reset*/
				win = 0;  /* Reset*/
			}
			if (player == 1) { /* Switch players (with below)*/
				player = 2; }
			else if (player == 2) {
				player = 1;}
		    else {
				printf("This isn't supposed to happen"); /* Just in case*/
			}
		}	
	printf(" \n ");  			
}

int display_board(char board[11][11])/*Placeholder for display_board() function*/
{
	
	int i = 0; /* initialize loop counter*/
	int j = 0; /* initialize loop counter*/
	for (i = 0; i < 11; i++) 
	{
		printf("\n"); /* Each row should end in a newline*/
		for (j = 0; j < 11; j++) /* Go through each column*/
		{
			printf(" %c ", board[i][j]); /* Not just a statement for debugging this time around.*/
		}
	}
	printf(" \n "); /* just some extra whitespace for no reason*/
	return 0;
	
}
int peoplemove(char board[11][11])
{
	printf("\n It is Your turn"); /* Statement for begining*/
	printf("\n Please choose a number from 1 to 9\n");
	a = scanf("%d", &number);
	fflush(stdin); /*remove the data in the input buffer*/
	while (a == 0)
	{
		printf("\n Invalid chosen, please try again\n.");
		a=scanf("%d", &number);
		fflush(stdin);/*remove the data in the input buffer*/
				}
				while(number!=9&&number!=8&&number!=7&&number!=6&&number!=5&&number!=4&&number!=3&&number!=2&&number!=1)/*make sure the number is on board*/
				{
					printf("\n Invalid chosen, please try again\n.");
					scanf("%d",&number);
					fflush(stdin);/*remove the data in the input buffer*/
				}

				if (number==1){
					row=1;
					column=1;}
				else if(number==2){
					row=1;
					column=5;}
				else if(number==3){
					row=1;
					column=9;}
				else if(number==4){
					row=5;
					column=1;}
				else if(number==5){
					row=5;
					column=5;}
				else if(number==6){
					row=5;
					column=9;}
				else if(number==7){
					row=9;
					column=1;}
				else if(number==8){
					row=9;
					column=5;}
				else if(number==9){
					row=9;
					column=9;}
				else 
					printf("\n Invalid chosen, please try again.");
					
				if (player == 1 && board[row][column] <= '9'&& board[row][column] >= '1') {
					board[row][column] = 'X';
					flag = 1;
				} 
				 else if (board[row][column] == 'O') {
					printf("\n That space is taken by O. Please try again. \n");
				} else if (board[row][column] == 'X') {
					printf("\n That space is taken by X. Please try again. \n");
				} else {
					printf("This isn't supposed to happen"); /* Just in case*/
					exit(1); /* throw an error to get out of the loop*/
				}
				  number = 0; /* Reset*/

				return 0;
}
void computermove(char board[11][11])
{	
	int b,i,j,check; 
	check=0;
	srand(time(NULL));
	while(check==0)
	{
	b=rand()%9+1;					/*create a random number from 1 to9 */			
	for(i=1;i<11;i=i+4)
		for(j=1;j<11;j=j+4)
		{
			if(board[i][j]==b+48)
			{						/* use 'if' to judge whether the place player chooses is occupied*/				
				board[i][j]='O';
				check=1;			/* assign the player's pattern, 'X' or 'O', to the position of board*/					
			} 
		}
	}
}

void ReadPerson( )/*Read all player information from the last saved file*/
{
	entry person;		/*declare a structure*/
	char filename[21] = "admin.dat";
	FILE *fptr;			/*declare a file pointer*/
	int i = 0;

	g_total = g_CurIndex = 0;
	
	fptr = fopen(filename, "rb");	/*open the file*/
	
	if (fptr == NULL)				/*test success of opening file*/
	{
		printf("\n\nThere was a problem opening the file\n\n");
		Sleep(2000);
		return;
	}
	else		/*on successful opening of the file, read structures from file into the structure variable then print the values on the screen*/
	{
		while (fread(&person, sizeof( entry), 1, fptr) == 1)	/*while loop ends when reading the file returns the EOF marker value*/
		{
			g_ArrPersons[i] = person;/*Save the user information you read from the file to the array*/
			i++;
		}
		g_total = i;/*Record the total number of players read*/
	}
	
	fclose(fptr); 		/*close the file*/

}

void SavePerson( )/*save this running result to the file*/
{	
	FILE *fptr;
	int i =0;
	char filename[21] = "admin.dat";
	fptr = fopen(filename, "w");
	if ( fptr == NULL )
	{
		printf("\n\nThere was a problem opening the file\n\n");
		Sleep(2000);
	}

	for ( i = 0;i<g_total;++i )/*save all the information to the file*/
	{
		fwrite( &g_ArrPersons[i],sizeof(entry ),1,fptr );

	}
	fclose( fptr );
}



