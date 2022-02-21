#include "othello_func.c"

int main(){
	char board[8][8];
	  
	//initialize board.
	init_board(board);
	
	int row, option, index = 0, i;
	
	//starting color is ' x '.
	char col, color = 'x';
	
	//Main screen
	printf("*******************************************************************\n");
	printf("******************** Welcome to Othello ***************************\n");
	
	printf("\n\nEnter 1. Single Player\n");
	printf("Enter 2. Multi Player\n");
	scanf("%d",&option);
	
	
	//if option 1 then single player game against computer.
	if(option == 1)
	{
		system("cls");
		int Row[100];
		char Col[100],value[2];
		FILE *file;
		i=0;
		//Main screen
		printf("*******************************************************************\n");
		printf("******************** Welcome to Othello ***************************\n");
		
		printf("\n\nEnter 1. with text file\n");
		printf("Enter 2. without text file\n");
		scanf("%d",&option);
		
		system("cls");
		//option 1 to give computer moves from text file.
		if(option == 1){
			//reading moves from file and storing in arrays.
			if (file = fopen("plays.txt", "r"))
			{
				while (fscanf(file, "%s", &value) != EOF)
			    {
			    	char *ptr = value;
			    	Row[i] = ptr[0] - '0';
			    	Col[i] = ptr[1];
			      	i++;
			    }
			    fclose(file);
			
			    Row[i] = 0;
			    Col[i] = '\0';
			}
			
			//print the initial board.
			print_board(board);
			do
		    {
		    	printf("\n");
		    	//telling which player turn it is.
		    	if(color == 'x')
				{
		    		//checking if moves avaliable for computer.
		    		if(Row[index] != 0 && Col[index] != '\0')
					{
		    			row = Row[index];
		    			col = Col[index];
		    			printf("computer move (x): %d %c",row,col);
		    			index++;
					}
		    		else
					{
		    			printf("computer is out of moves.");
						color = 'o';
					}
				}
				else
				{
					printf("Player turn (o):");
					scanf("%d %c",&row,&col);
				}
				//checking if move is valid.
		        if (isValidMove(board,row-1, getColumn(col),color))
		        {
		        	//play function to perform move.
					play(board,row-1, col,color);
					
		        	//changing the player turn.
		        	if(color == 'x'){
		        		color = 'o';
					}else{
						color = 'x';
					}
		        }
		        else
		        {
		            printf("\nInvalid Move. Try Again.\n");
		        }
		        print_board(board);
		    }while (!isGameOver(board));
		    
		    //getting the winner
		    if(getWinner(board) == 'o'){
		    	printf("\nPlayer wins.");
			}
			else{
				printf("\nComputer wins");
			}
		}
		else if(option == 2){
			//print the initial board.
			int RowNum[8] = {0,1,2,3,4,5,6,7};
			int ColChar[8] = {'A','B','C','D','E','F','G','H'};
			print_board(board);
			do
		    {
		    	printf("\n");
		    	//telling which player turn it is.
		    	if(color == 'x')
				{
					row = RowNum[rand() % 7];
		    		col = ColChar[rand() % 7];
		    		//assigning move for computer.
		    		while(!isValidMove(board,row-1, getColumn(col),color))
					{
		    			row = RowNum[rand() % 7];
		    			col = ColChar[rand() % 7];		
					}
					printf("computer move (x): %d %c",row,col);
				}
				else
				{
					printf("Player turn (o):");
					scanf("%d %c",&row,&col);
				}
				//checking if move is valid.
		        if (isValidMove(board,row-1, getColumn(col),color))
		        {
		        	//play function to perform move.
					play(board,row-1, col,color);
					
		        	//changing the player turn.
		        	if(color == 'x'){
		        		color = 'o';
					}else{
						color = 'x';
					}
		        }
		        else
		        {
		            printf("\nInvalid Move. Try Again.\n");
		        }
		        print_board(board);
		    }while (!isGameOver(board));
		    
		    //getting the winner
		    if(getWinner(board) == 'o'){
		    	printf("\nPlayer wins.");
			}
			else{
				printf("\nComputer wins");
			}
		}
		
		
		
		
	}
	//option 2 for multi player.
	else if(option == 2)
	{
		system("cls");
		//print the initial board.
		print_board(board);
		do
	    {
	    	printf("\n");
	    	//telling which player turn it is.
	    	if(color == 'x'){
	    		printf("Player-%d turn (x): ",1);
			}else{
				printf("Player-%d turn (o):",2);
			}
	        printf("Enter the Column : ");
			scanf("%d %c",&row,&col);
			//checking if move is valid.
	        if (isValidMove(board,row-1, getColumn(col),color))
	        {
	        	//play function to perform move.
				play(board,row-1, col,color);
				
	        	//changing the player turn.
	        	if(color == 'x'){
	        		color = 'o';
				}else{
					color = 'x';
				}
	        }
	        else
	        {
	            printf("Invalid Move. Try Again.\n");
	        }
	        print_board(board);
	    }while (!isGameOver(board));
	    
	    //getting the winner 
	    if(getWinner(board) == 'o'){
	    	printf("\nPlayer-2 wins.");
		}
		else{
			printf("\nPlayer-1 wins");
		}
	}
	else
	{
		printf("\nWrong option Entered.\nExiting the game.....");	
	}
	
	
	
}
