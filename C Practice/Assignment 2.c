#include <stdio.h>
#include <stdlib.h>
#include <string.h>
 
int winner(char board[11][11]); 
int display_board(char board[11][11]);

int main()
{
	int number = 0; /* Initialize variable which is used to collect number*/
	int player = 1; /* Represent players as numbers*/
	int flag = 0; /* Used later in a while-loop*/
	int won = 0; /* Initialize win condition flag*/
	int row=0;
	int column=0;
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
	};
	
	
	printf("\n Here is a blank Tic-Tac-Toe board for you and a friend to play Tic-Tac-Toe on: \n");
	display_board(board); /* Show initial position of board */
	while (won == 0) /* Continue the game until a player wins*/
		{
			while (flag == 0)
			{
				printf("\n It is player #%i's turn. \n", player); /* Statement for begining*/
				printf("\n Please choose a number from 1 to 9\n");
				scanf("%d",&number);
				while(number!=9&&number!=8&&number!=7&&number!=6&&number!=5&&number!=4&&number!=3&&number!=2&&number!=1)
				{
					printf("\n Invalid chosen, please try again\n.");
					scanf("%d",&number);
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
				} else if (player == 2 && board[row][column] <= '9'&& board[row][column] >= '1') {
					board[row][column] = 'O';
					flag = 2;
				} else if (board[row][column] == 'O') {
					printf("\n That space is taken by O. Please try again. \n");
				} else if (board[row][column] == 'X') {
					printf("\n That space is taken by X. Please try again. \n");
				} else {
					printf("This isn't supposed to happen"); // Just in case
					exit(1); // throw an error to get out of the loop
				}
				  number = 0; /* Reset*/
			}
			
			printf("\n The board now looks like this: \n");
			display_board(board); // Update board
			won = winner(board); // Check for winner
			if (won == 1) { // Function winner() should return 1 if player 1 wins
				printf("\n Player 1 wins! \n");
			} else if (won == 2) { // Function winner() should return 2 if player 2 wins
				printf("\n Player 2 wins! \n");
			} else if (won == 3) { // Function winner() should return 3 if it's a tie.
				printf("\n It's a tie. \n");
			} else {
				flag = 0; /* Reset*/
				won = 0;  /* Reset*/
			}
			if (player == 1) { // Switch players (with below)
				player = 2; 
			} else if (player == 2) {
				player = 1;
			} else {
				printf("This isn't supposed to happen"); // Just in case
			}
		}	
	printf(" \n "); 
    return 0;	
			
}

int display_board(char board[11][11])/*Placeholder for display_board() functio*/
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
	} else if (((board[1][1] == 'O') && (board[1][5] == 'O') && (board[1][9] == 'O')) || /* first row*/
			   ((board[1][1] == 'O') && (board[5][1] == 'O') && (board[9][1] == 'O')) || /* first column*/
			   ((board[1][1] == 'O') && (board[5][5] == 'O') && (board[9][9] == 'O')) || /* diagonal 1*/
			   ((board[5][1] == 'O') && (board[5][5] == 'O') && (board[5][9] == 'O')) || /* second row*/
			   ((board[9][1] == 'O') && (board[5][9] == 'O') && (board[9][9] == 'O')) || /* third row*/
			   ((board[1][5] == 'O') && (board[5][5] == 'O') && (board[9][5] == 'O')) || /* second column*/
			   ((board[1][9] == 'O') && (board[5][9] == 'O') && (board[9][9] == 'O')) || /* third column*/
			   ((board[1][9] == 'O') && (board[5][5] == 'O') && (board[9][1] == 'O')) /* diagonal 2*/
			   )
	{
		winner_number = 2;
	} else 
			{blank = 1; /* 1 means there's still a blank*/
		if (blank == 0) { 
			winner_number = 3;  /*It will still be 0 if no blanks were found*/
		}}
	return winner_number;
}