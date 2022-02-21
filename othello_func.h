
//	################################################################ 
//	# init_board - This function initializes the board to default values #
//
//	# Arguments: 
//	# board - character, 2-D array
//
//	# Return value: # None 
//	################################################################

void init_board(char board[8][8]);

//	################################################################ 
//	# print_board - This function print the elements of board #
//
//	# Arguments: 
//	# board - character, 2-D array
//
//	# Return value: # None 
//	################################################################

void print_board(char board[8][8]);

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
bool checkFlip(char board[8][8],char color, int line, int col, int deltaline, int deltaCol);

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

void changeCoins(char board[8][8],char color, int line, int col, int deltaline, int deltaCol);

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
bool isValidMove(char board[8][8],int line, int col,char color);


//	################################################################ 
//	# getColumn - This function convert char column to column number #
//
//	# Arguments: 
//	# col - integer, column
//
//	# Return value: integer, index
//	################################################################
int getColumn(char col);


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
void play(char board[8][8], int line, char colm, char color);


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
int count_flips_dir(char board[8][8],char color, int line, int col, int deltaline, int deltaCol);

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
int flanked(char board[8][8], int line, int colm,char color);



//	################################################################ 
//	# isGameOver - This function checks if game is over or not #
//
//	# Arguments: 
//	# board - character, 2-D array

//	# Return value: true or false
//	################################################################
bool isGameOver(char board[8][8]);


//	################################################################ 
//	#  getWinner - This function gives the winner of game #
//
//	# Arguments: 
//	# board - character, 2-D array

//	# Return value: 'o' or 'x' 
//	################################################################
char getWinner(char board[8][8]);

