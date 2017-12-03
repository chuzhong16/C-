/*
Name: Simple Tic-tac-toe game designed by C program 
Conversion File Name: 1611135_2.c
Copyright: Free
Author: Tong Wu
Description:This program allows two players to play Tic-tac-toe. Two players can decide the who plays the first step and 
judge which player wins or it is a draw.
*/
// player ='x' com='o'
#include <stdio.h>				// include function prototype in file of standard input output 'stdio.h'
#include <string.h>				// include function prototype about strings in file 'string.h'
#include <windows.h>			// include the library 'windows.h'
#include <time.h>
#include <stdlib.h>
#include <ctype.h>

char board[3][3];				// declare global two dimensional array variables which indicates the 9 space in the board
int brk[8]={0,0,0,0,0,0,0,0};

typedef int bool;				// declare boolean variable which is type of integer
#define false 0					// declare 'false' in boolean as integer '0'
#define true 1					// declare 'true' in boolean as integer '1'

void BoardNumSet();			
void BoardDisplay();			
void Playermove(char Player);
void Compmove();		
bool ResultCheck(bool theEnd);				
bool DrawCheck(bool theEnd2);							

int main()						// define a main function that has no returned value
{
	bool stop=false, theEnd=false,theEnd2=false;			// declare two boolean variables named 'stop', 'theEnd'	
	char Player='X',order,again;				// declare two character variable named 'Player' , 'choice'	
	int choice,shift=0,win,lose;					// declare one integer variable named 'choice'						// declare a character variable named 'order'	
	printf("-----------------------------\nWelcome, let's' play tic-tac-toe\n-----------------------------\n");			

	do
	{  
		if(shift==0){
			printf("Please choose whether Player or Computer go first.\n1.Player   2.Computer\n");
	
			order=getchar();
			getchar();
			while(order!='1' && order!='2'){
				printf("Invalid choice, please enter again.\n");
				printf("Please choose whether Player or Computer go first.\n1.Player   2.Computer\n");
				order=getchar();
				getchar();
			}		
			//printf("%c", Player);                    This line is used to test.	
			BoardNumSet();
			system("cls");		
		}	
		shift=1;
		BoardDisplay();
			
		if(order=='2'){
			Compmove();
			theEnd=ResultCheck(theEnd);	// assign the boolean value got from the subfunction 'ResultCheck' to the boolean variable 'theEnd'		
			theEnd2=DrawCheck(theEnd);			// assign the boolean value got from the subfunction 'DrawCheck' to the boolean variable 'theEnd'
			if(theEnd){
				printf("Computer wins\n");
				BoardDisplay();
			}
			if(theEnd2){
				theEnd=true;
				BoardDisplay();
			}
		}else if(order=='1'){
			Playermove(Player);
			theEnd=ResultCheck(theEnd);	// assign the boolean value got from the subfunction 'ResultCheck' to the boolean variable 'theEnd'		
			theEnd2=DrawCheck(theEnd);			// assign the boolean value got from the subfunction 'DrawCheck' to the boolean variable 'theEnd'
			if(theEnd){
				printf("Player wins\n");
				BoardDisplay();
			}
			if(theEnd2){
				theEnd=true;
				BoardDisplay();
			}	
		}
	
		if(theEnd){					// use 'if' to judge whether the game should be over		
			BoardNumSet();					// if 'theEnd' is true, then the game should be over and the numbers on board should be reset			
			theEnd=false;
			stop=true;
			
			printf("Play again? 1.yes 2.no\n");
			fflush(stdin);
			again=getchar();
			getchar();
			while(again!='1' && again!='2'){
				printf("Invalid choice, please enter again.\n");
				printf("Play again? 1.yes 2.no\n");
				again=getchar();
				getchar();
			}
			
			if(again=='1'){
				stop=false;
				shift=0;
			}else{
				printf("See you.");
			}		
		}
		
		if(order == '2'){
        	order = '1';					// if player'X' played former round, then player 'O' will play next round
        }else{
        	order = '2';
		}
       
        //printf("%c", stop);				   This line is used to test.       
        if(stop==false)		system("cls");	// use 'if' to judge whether it needs to clean the board before       
	}while(stop==false);					// use the condition 'stop' equals to 'false' to allow the loop to run until 'break'	
	return 0;								// indicate that the program ends
}

void BoardNumSet(){							// define a sub function named 'BoardNumSet' used to set the 9 numbers in board
	int i=0,j=0,n=1;						// declare 3 integer number variables	
	for(i=0;i<3;i++){						// use the 'for' function to make the programs within it run 3 times	
		for(j=0;j<3;j++){					// use the 'for' function to make the programs within it run 3 times to cover 9 element in array		
			board[i][j]='0'+n;				// assign n to each element in array			
			n++;							// make n plus 1 each time to make the elements in array become 1-9 
		}
	}	
	return;									// indicate that the sub function ends
}

void BoardDisplay(){						// define a sub function named 'BoardDisplay' with no return value and variable

	int i=0,j=0;							// declare 2 integer number variables	
	for(i=0;i<3;i++){						// use the 'for' function to make the programs within it run 3 times	
		printf("   #   #   \n");			// display the board of Tic-tac-toe		
		for(j=0;j<3;j++){					// use the 'for' function to make the programs within it run 3 times		
			if(j<2){						// use 'if' to judge whether it is first 2 lines			
				printf(" %c #", board[i][j]); 		// display the number of the place in board of Tic-tac-toe				
			}else{							// use 'else' to approach the other situation, which means it is the third line			
				printf(" %c \n", board[i][j]);		// display the number of the place in board of Tic-tac-toe
			}
		}
		if(i<2){							// use 'if' to judge whether it is first 2 lines		
			printf("   #   #   \n##################\n");		// display the board of Tic-tac-toe if it is first 2 lines			
		}else{								// use 'else' to approach the other situation, which means it is the third line		
			printf("   #   #   \n");		// display the board of Tic-tac-toe if it is the third lines
		}
	}
	return;									// indicate that the sub function ends
}

void Playermove(char Player){			/* define a sub function named 'Playermove', 
whose type of input data is a character variable with a pointer and another character variable, without returned value*/

	int i=0,choice,j=0,check=1;							// declare 2 integer number variables	
	bool Wrongmove=true;					// declare 1 boolean variable named 'Wrongmove'
	printf("\nPlayer, it's your turn:");			// ask the player to choose one place to put		
	do{									// Use a 'do while' loop to enable the player to input again if he enters illegal input		
		while((scanf("%d",&choice))!=1){			// use the 'while' loop and '%d' in function 'scanf' to ensure the input to be 1 integer				
			printf("Please enter a number.\n");		// ask the player to enter again				
			fflush(stdin);							// clear the input buffer ready for the next character
		}
		if(choice<1||choice>9){						// use 'if' and 'strlen' to judge whether the input is legal			
			printf("Please enter a number which is in range.\n"); 			// if the length of 'order' is more than 1, it is a illegal input				
			// ask the user to input again			
		}else{							// use 'else' to approach the other situation, which means it is a legal input			
			check=0;					// if input is legal, change check's value to stop the loop				
		}		
	}while(check==1);
	
	do{										// Use a 'do while' loop to enable the player to input again if he enters illegal input	
		for(i=0;i<3;i++){					// use the 'for' function to make the programs within it run 3 times		
			for(j=0;j<3;j++){				// use the 'for' function to make the programs within it run 3 times			
				if(board[i][j]==choice+48){			// use 'if' to judge whether the place player chooses is occupied				
					board[i][j]=Player;				// assign the player's pattern, 'X' or 'O', to the position of board					
					Wrongmove=false;		// assign 'false' to 'Wrongmove', which means that this move is not wrong
				}
			}
		}
		if(Wrongmove==true){			// if this move is false
		
			printf("You can only choose the number that hasn't been choosed!\n");		// tell the player it is a wrong move				
			printf("Player, please enter again.\n");							// ask the player to enter again				
			scanf("%d",&choice);														// enable the player to enter again				
			getchar();																	// avoid 'enter' from influencing the data input
		}
	}while(Wrongmove==true);			// use the condition 'Wrongmove' equals to 'true' to allow the loop to run until it equals to 'false'
	
	return;
}

void Compmove(){
	int i=0,j=0,a,check=0,check2=0;

	srand(time(NULL));
	for(i=0;i<3;i++){				
		if(board[i][0]==board[i][1] && board[i][0]=='X'&& brk[0]==0){		// judge whether the 3 elements in the line is the same		
			board[i][2]='O';
			brk[0]=1;
			break;				// assign 'true' to 'theEnd', which means the game is over
		}else if(board[i][1]==board[i][2] && board[i][1]=='X'&& brk[1]==0){		// judge whether the 3 elements in the line is the same		
			board[i][0]='O';
			brk[1]=1;
			break;					// assign 'true' to 'theEnd', which means the game is over
		}else if(board[i][0]==board[i][2] && board[i][0]=='X'&& brk[2]==0){
			board[i][1]='O';
			brk[2]=1;
			break;	
		}else if(board[0][i]==board[1][i] && board[0][i]=='X'&& brk[3]==0){		// judge whether the 3 elements in the line is the same		
			board[2][i]='O';
			brk[3]=1;
			break;					// assign 'true' to 'theEnd', which means the game is over
		}else if(board[1][i]==board[2][i] && board[1][i]=='X'&& brk[4]==0){
			board[0][i]='O';
			brk[4]=1;
			break;	
		}else if(board[0][i]==board[2][i] && board[1][i]=='X'&& brk[5]==0){
			board[1][i]='O';
			brk[5]=1;
			break;	
		}else if(board[0][0]==board[2][2] && board[0][0]=='X'&& brk[6]==0){
			board[1][1]='O';
			brk[6]=1;
			break;	
		}else if(board[0][2]==board[2][0] && board[0][2]=='X'&& brk[7]==0){
			board[1][1]='O';
			brk[7]=1;
			break;		
		}else{
			check2=1;
		}
	}

	if(check2==1){
		while(check==0){
			a=rand()%9+1;
			for(i=0;i<3;i++){					// use the 'for' function to make the programs within it run 3 times		
				for(j=0;j<3;j++){				// use the 'for' function to make the programs within it run 3 times			
					if(board[i][j]==a+48){			// use 'if' to judge whether the place player chooses is occupied				
						board[i][j]='O';				// assign the player's pattern, 'X' or 'O', to the position of board					
						check=1;		// assign 'false' to 'Wrongmove', which means that this move is not wrong
				}
			}
		}
		}
	}
		
}

bool ResultCheck(bool theEnd){				/* define a sub function named 'ResultCheck', 
whose input is one character variable and one boolean varaible and return value is a boolean value*/

	int i=0;							// declare 1 integer variable
	
	for(i=0;i<3;i++){					/* use the 'for' function to make the programs within it run 3 times, 
	which means the 3 elements in a row in 3 lines*/	
		if(board[i][0]==board[i][1] && board[i][1]==board[i][2]){		// judge whether the 3 elements in the line is the same		
			theEnd=true;				// assign 'true' to 'theEnd', which means the game is over
		}
	}
	for(i=0;i<3;i++){					/* use the 'for' function to make the programs within it run 3 times, 
	which means the 3 elements in a column in 3 columns*/				
		if(board[0][i]==board[1][i] && board[1][i]==board[2][i]){		// judge whether the 3 elements in the column is the same		
			theEnd=true;				// assign 'true' to 'theEnd', which means the game is over
		}
	}
	if(board[0][0]==board[1][1] && board[1][1]==board[2][2]){          	// judge whether the elements on diagonal line is the same	
		theEnd=true;					// assign 'true' to 'theEnd', which means the game is over
	}
	if(board[2][0]==board[1][1] && board[1][1]==board[0][2]){          	// judge whether the elements on diagonal line is the same	
		theEnd=true;					// assign 'true' to 'theEnd', which means the game is over
	}

	return theEnd;						// return the boolean value of 'theEnd'
}

bool DrawCheck(bool theEnd2){						/* define a sub function named 'DrawCheck', 
whose type of input data is boolean and return value is a boolean value */

	int i=0,j=0,n=1;					// declare 3 integer variables	
	int check=0;							// declare 1 integer variable which is used to check	
	for(i=0;i<3;i++){					// use the 'for' function to make the programs within it run 3 times 	
		for(j=0;j<3;j++){				// use the 'for' function to make the programs within it run 3 times		
			if(board[i][j]=='0'+n){		// check wheter the elements in board is the original number			
				check++;					// if it is true then the variable plus one
			}
			n++;						// make n plus 1 each time to make the number used to check become 1-9
		}
	}
	if(check==0){							// if 'cnt' equals to '0', that means there is no original number	
		theEnd2=true;					// assign 'true' to 'theEnd', which means the game is over		
		printf("*************\nIt's a draw.\n*************\n");	// tell the players it is a draw
	}
	return theEnd2;						// return the boolean value of 'theEnd'
}

