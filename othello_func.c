#include<stdio.h>
#include<string.h>
#include <stdbool.h> 
#include "othello_func.h"


//	################################################################ 
//	# init_board - This function initializes the board to default values #
//
//	# Arguments: 
//	# board - character, 2-D array
//
//	# Return value: # None 
//	################################################################

void init_board(char board[8][8])
{
	int i,j;
	for(i=0; i<8; i++){
        for (j=0; j<8; j++) {
            board[i][j] = '-';
        }
    }
	board[3][3] = 'o'; 
	board[3][4] = 'x';
    board[4][3] = 'x'; 
	board[4][4] = 'o';
}

//	################################################################ 
//	# print_board - This function print the elements of board #
//
//	# Arguments: 
//	# board - character, 2-D array
//
//	# Return value: # None 
//	################################################################

void print_board(char board[8][8])
{
	printf("\n");
	printf("    A  B  C  D  E  F  G  H");
	int i,j;
	for(i=0; i<8; i++){
		printf("\n%d   ",i+1);
		for(j=0; j<8; j++){
			printf("%c  ",board[i][j]);
		}
	}
}


//	################################################################ 
//	# checkFlip- This function checks if flip of a color is possible #
//
//	# Arguments: 
//	# board - character, 2-D array
//	# color - character, player
//	# line - integer, row
//	# col - integer, column
//	# deltaline - integer, row in specific direction
//	# deltacol - integer, colum in specific direction

//	# Return value: true or false
//	################################################################
bool checkFlip(char board[8][8],char color, int line, int col, int deltaline, int deltaCol)
{
        char oppcolor = 'o';
        if (color == 'o')
        {
            oppcolor = 'x';
        }

        if ((line < 0) || (line >= 8) || (col < 0) || (col >= 8))
        {
            return false;
        }

        if (board[line][col] == oppcolor)
        {
            while ((line >= 0) && (line < 8) && (col >= 0) && (col < 8))
            {
                line += deltaline;
                col += deltaCol;
                if (board[line][col] == '-')
                {
                    return false;
                }
                if (board[line][col] == color)
                {
                    return true;
                }
            }
        }
        return false;
}

//	###################################################################### 
//	# changeCoins - This function changes the coin in a specific row and column #
//
//	# Arguments: 
//	# board - character, 2-D array
//	# color - character, player
//	# line - integer, row
//	# col - integer, column
//	# deltaline - integer, row in specific direction
//	# deltacol - integer, colum in specific direction

//	# Return value: none
//	#####################################################################

void changeCoins(char board[8][8],char color, int line, int col, int deltaline, int deltaCol)
{
    char oppcolor = 'o';
    if (color == 'o')
    {
        oppcolor = 'x';
    }

    while (board[line][col] == oppcolor)
    {
        board[line][col] = color;
        line += deltaline;
        col += deltaCol;
    }
}

//	#####################################################################
//	# isValidMove - This function checks if the move performed is valid or not #
//
//	# Arguments: 
//	# board - character, 2-D array
//	# color - character, player
//	# line - integer, row
//	# col - integer, column

//	# Return value: true or false
//	####################################################################
bool isValidMove(char board[8][8],int line, int col,char color)
{
    if ((line < 0) || (line >= 8) || (col < 0) || (col >= 8))
    {
        return false;
    }

    if (board[line][col] != '-')
    {
        return false;
    }
    
    // Check Up
    if (checkFlip(board,color, line - 1, col, -1, 0))
    {
        return true;
    }
    // Check Down
    if (checkFlip(board,color, line + 1, col, 1, 0))
    {
        return true;
    }
    // Check Left
    if (checkFlip(board,color, line, col - 1, 0, -1))
    {
        return true;
    }
    // Check Right
    if (checkFlip(board,color, line, col + 1, 0, 1))
    {
        return true;
    }
    // Check Down-Right
    if (checkFlip(board,color, line + 1, col + 1, 1, 1))
    {
        return true;
    }
    // Check Down-Left
    if (checkFlip(board,color, line + 1, col - 1, 1, -1))
    {
        return true;
    }
    // Check Top-Right
    if (checkFlip(board,color, line - 1, col + 1, -1, 1))
    {
        return true;
    }
    // Check Top-Left
    if (checkFlip(board,color, line - 1, col - 1, -1, -1))
    {
        return true;
    }

    return false;
}


//	################################################################ 
//	# getColumn - This function convert char column to column number #
//
//	# Arguments: 
//	# col - integer, column
//
//	# Return value: integer, index
//	################################################################
int getColumn(char col){
	char columns[8] = {'A','B','C','D','E','F','G','H'};
	int i;
	for(i=0; i<8; i++){
		if(columns[i] == col){
			return i;
		}
	}
}


//	################################################################ 
//	# play - This function make move of the player #
//
//	# Arguments: 
//	# board - character, 2-D array
//	# color - character, player
//	# line - integer, row
//	# col - integer, column

//	# Return value: none
//	################################################################
void play(char board[8][8], int line, char colm, char color){
	
	int col = getColumn(colm);
	board[line][col] = color;
    // Check Up
    if (checkFlip(board,color, line - 1, col, -1, 0))
    {
        changeCoins(board,color, line - 1, col, -1, 0);
    }
    // Check Down
    if (checkFlip(board,color, line + 1, col, 1, 0))
    {
        changeCoins(board,color, line + 1, col, 1, 0);
    }
    // Check Left
    if (checkFlip(board,color, line, col - 1, 0, -1))
    {
        changeCoins(board,color, line, col - 1, 0, -1);
    }
    // Check Right
    if (checkFlip(board,color, line, col + 1, 0, 1))
    {
        changeCoins(board,color, line, col + 1, 0, 1);
    }
    // Check Down-Right
    if (checkFlip(board,color, line + 1, col + 1, 1, 1))
    {
        changeCoins(board,color, line + 1, col + 1, 1, 1);
    }
    // Check Down-Left
    if (checkFlip(board,color, line + 1, col - 1, 1, -1))
    {
        changeCoins(board,color, line + 1, col - 1, 1, -1);
    }
    // Check Top-Right
    if (checkFlip(board,color, line - 1, col + 1, -1, 1))
    {
        changeCoins(board,color, line - 1, col + 1, -1, 1);
    }
    // Check Top-Left
    if (checkFlip(board,color, line - 1, col - 1, -1, -1))
    {
        changeCoins(board,color, line - 1, col - 1, -1, -1);
    }

}


//	################################################################ 
//	# count_flips_dir - This function counts the no of flips in a direction #
//
//	# Arguments: 
//	# board - character, 2-D array
//	# color - character, player
//	# line - integer, row
//	# col - integer, column
//	# deltaline - integer, row in specific direction
//	# deltacol - integer, colum in specific direction

//	# Return value: interger, counter
//	################################################################
int count_flips_dir(char board[8][8],char color, int line, int col, int deltaline, int deltaCol)
{
	int counter = 0;
    char oppcolor = 'o';
    if (color == 'o')
    {
        oppcolor = 'x';
    }

    while (board[line][col] == oppcolor)
    {
       counter++;
    }
    
    return counter;
}

//	################################################################ 
//	# flanked - This function gives the total coins fliped by move #
//
//	# Arguments: 
//	# board - character, 2-D array
//	# color - character, player
//	# line - integer, row
//	# col - integer, column

//	# Return value: integer, counter
//	################################################################
int flanked(char board[8][8], int line, int colm,char color){
	int col = getColumn(colm);
	int counter = 0;
    // Check Up
    if (checkFlip(board,color, line - 1, col, -1, 0))
    {
        counter += count_flips_dir(board,color, line - 1, col, -1, 0);
    }
    // Check Down
    if (checkFlip(board,color, line + 1, col, 1, 0))
    {
        counter += count_flips_dir(board,color, line + 1, col, 1, 0);
    }
    // Check Left
    if (checkFlip(board,color, line, col - 1, 0, -1))
    {
        counter += count_flips_dir(board,color, line, col - 1, 0, -1);
    }
    // Check Right
    if (checkFlip(board,color, line, col + 1, 0, 1))
    {
        counter += count_flips_dir(board,color, line, col + 1, 0, 1);
    }
    // Check Down-Right
    if (checkFlip(board,color, line + 1, col + 1, 1, 1))
    {
        counter += count_flips_dir(board,color, line + 1, col + 1, 1, 1);
    }
    // Check Down-Left
    if (checkFlip(board,color, line + 1, col - 1, 1, -1))
    {
        counter += count_flips_dir(board,color, line + 1, col - 1, 1, -1);
    }
    // Check Top-Right
    if (checkFlip(board,color, line - 1, col + 1, -1, 1))
    {
        counter += count_flips_dir(board,color, line - 1, col + 1, -1, 1);
    }
    // Check Top-Left
    if (checkFlip(board,color, line - 1, col - 1, -1, -1))
    {
        counter += count_flips_dir(board,color, line - 1, col - 1, -1, -1);
    }
    
    return counter;
}



//	################################################################ 
//	# isGameOver - This function checks if game is over or not #
//
//	# Arguments: 
//	# board - character, 2-D array

//	# Return value: true or false
//	################################################################
bool isGameOver(char board[8][8])
{
	int i,j;
	for(i=0; i<8; i++){
        for (j=0; j<8; j++) {
            if(board[i][j] = '-'){
            	return false;
			}
        }
    }
    return true;
}


//	################################################################ 
//	#  getWinner - This function gives the winner of game #
//
//	# Arguments: 
//	# board - character, 2-D array

//	# Return value: 'o' or 'x' 
//	################################################################
char getWinner(char board[8][8])
{
	int i,j,o = 0,x = 0;
	for(i=0; i<8; i++){
        for (j=0; j<8; j++) {
            if(board[i][j] = 'o'){
            	o++;
			}
			else if(board[i][j] = 'x'){
				x++;
			}
        }
    }
    
    if(o > x){
    	return 'o';
	}
	
	return 'x';
}












