#include <stdio.h>
#include <stdlib.h>

#define N 9

int HUMAN=0;
int COMP=1;

void printBoard( int board[]);
int isBoardFull( int board[]);
void makeMove(int board[],int cell,int side);
int is3inARow(int board[],int side);
int isAWin(int board[],int side); 
int maxf(int *scoreList,int moveCount,int *moveList,int *bestMove);
int minf(int *scoreList,int moveCount,int *moveList,int *bestMove);
int minMax(int board[], int side, int *depth);
int getComputerMove(int *board,int side);
int getHumanMove(int *board);
void game();

int main() 
{
	char again;
	int Yes=1;
	while(Yes)
	{
	game();
	fflush(stdin);
	//sleep(50);
	printf("Y of N\n");
	scanf("%c",&again);
	if(again=='Y')
	{
		Yes=1;
	}
	else 
	{
		Yes=0;
	}
	}
	system("pause"); 
	return 0;	/*return the value of 0 to main function*/
}

// initialize the borad with empty cells


// print the board on console
void printBoard(int board[])
{

	char neirong[3] = { 'O','X','-' };

	printf("\n The BOARD now is\n\n");
	for(int i=0; i<N; i++) 
	{
		if(i != 0 && i%3 == 0)
			printf("\n\n");
		printf(" %c ",neirong[board[i]]);
	}
	printf("\n\n");
}

// checks if the board is full or not
// returns 1(true) if full
// returns 0(false) if even one cell is empty
int isBoardFull(int board[])
{

	for(int i=0; i<N; i++)
		if(board[i] == 2)
			return 0;
	return 1;
}

// makes a move on the given cell by given side
void makeMove(int board[],int cell,int side) 
{
	board[cell] = side;
}


// checks if a 3 is formed by a side
// returns 1 if yes
// returns 0 if no
int is3inARow(int board[],int side) 
{

	// horizontal
	if(board[0] == side && board[1] == side && board[2] == side)
		return 1;
	if(board[3] == side && board[4] == side && board[5] == side)
		return 1;
	if(board[6] == side && board[7] == side && board[8] == side)
		return 1;

	// vertical
	if(board[0] == side && board[3] == side && board[6] == side)
		return 1;
	if(board[1] == side && board[4] == side && board[7] == side)
		return 1;
	if(board[2] == side && board[5] == side && board[8] == side)
		return 1;

	// diagonal
	if(board[0] == side && board[4] == side && board[8] == side)
		return 1;
	if(board[2] == side && board[4] == side && board[6] == side)
		return 1;

	return 0;
}

// returns score for side
// +10 if particular side wins
// -10 if particular side loses
//  0 if draw or not yet complete
int isAWin(int board[],int side) 
{

	if(is3inARow(board,side))
		return 10;
	if(is3inARow(board,!side))
		return -10;
	return 0;
}

// returns which moves gives the maximum score
int maxf(int *scoreList,int moveCount,int *moveList,int *bestMove) 
{
    
    if(!moveCount)
    	return 0;

    int max = -20;
    
    for(int i=0;i<moveCount;i++) 
	{
        if(scoreList[i] > max) 
		{
            max = scoreList[i];
            *bestMove = moveList[i];
        }
    }
    return max;
}

// returns which moves gives the minimum score
int minf(int *scoreList,int moveCount,int *moveList,int *bestMove) 
{
    
    if(!moveCount)
    	return 0;

    int min = +20;
    
    for(int i=0;i<moveCount;i++) {
        if(scoreList[i] < min) {
            min = scoreList[i];
            *bestMove = moveList[i];
        }
    }
    return min;
}

int minMax(int board[], int side, int *depth) {

	int moveList[N];
	int moveCount = 0;
	int bestMove = 9;
	int scoreList[N];
	int bestScore;

	bestScore = isAWin(board,COMP);
	if(bestScore)
		return bestScore - *depth;

	// fill the moveList[]
	for(int i=0;i<N;i++) {
		if(board[i] == 2)
			moveList[moveCount++] = i;
	}

	// loop through all moves
	int move;
	for(int i=0;i<moveCount;i++) {

		move = moveList[i];
		makeMove(board,move,side);

		(*depth)++;
		scoreList[i] = minMax(board,!side,depth);
		(*depth)--;

		makeMove(board,move,2);
	}

	if(side == COMP) {
		// MAX
		bestScore = max(scoreList,moveCount,moveList,&bestMove);
	}
	if(side == HUMAN) {
		// MIN
		bestScore = min(scoreList,moveCount,moveList,&bestMove);
	}

	if(*depth != 0)
        return bestScore;
    else
        return bestMove;
}

int getComputerMove(int *board,int side) 
{

    int depth = 0;
    int bestMove = minMax(board,side,&depth);
    printf("Searched.... bestMove: %d\n",bestMove+1);
    return bestMove;
}

int getHumanMove(int *board) 
{

	printf("\nEnter your move !!\n 1  2  3\n\n 4  5  6\n\n 7  8  9\n");
	int move;
	while(1)
	{
		scanf("%d",&move);
		if(board[move-1] == 2 && move >=0 && move <=9)
			break;
		else
			printf("try again : ");
	}
	return move-1;
}

void game() 
{
	int gameOver = 0;
	int side = 0;
	int move;
	int board[N];
	
	for(int i=0; i<N; i++)
		board[i]= 2;
	printf("\nChoose X or O. O moves first !!\n\n");
	while(1) {
		char choice = getchar();
		if(choice == 'O') {
			HUMAN = 0;
			COMP = 1;
			break;
		}
		if(choice == 'X') {
			HUMAN = 1;
			COMP = 0;
			break;
		}
		else {
			printf("Choose correct symbols\n");
		}
	}

	printBoard(board);

	while(!gameOver) {

		if(side == HUMAN) {
			//Human Move
			move = getHumanMove(board);
			makeMove(board,move,side);
			printBoard(board);
		}
		else {
			//Computer Move
			move = getComputerMove(board,side);
			makeMove(board,move,side);
			printBoard(board);
		}


		//WIN
		if(is3inARow(board,side)) {
			printf("Game Over\n");
			gameOver = 1;
			if(side == COMP)
				printf("Computer Wins\n");
			else
				printf("Human Wins\n");
		}

		//DRAW
		if(isBoardFull(board)) {
			printf("Game Over\n");
			gameOver = 1;
			printf("It's a Draw\n");
		}

		side = !side;

	}
}		

