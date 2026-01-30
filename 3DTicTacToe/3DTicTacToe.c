#include <stdio.h>
#include <ctype.h>
#include <stdbool.h>
/*
GESLANI, KEILA FRANCHOISE LEIGH O.
	3D TIC-TAC-TOE with Flip

Submitted to: Mr. Ryan Dimaunahan
*/


/*
 Description: This prints a 3x3 grid.
 Parameters: 
 param grid: The 3x3 grid.
 
 Return value: This function does not return anything (void).
*/
void print3x3Grid(char grid[3][3]) {
    int i, j;
	for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            printf(" %c ", grid[i][j]);
            if (j < 2) printf("|");
        }
        printf("\n");
        if (i < 2) printf("---+---+---\n");
    }
}
/*
 Description: This checks if the given symbol is a valid move for the grid.
 Parameters: 
 param (symbol): The symbol to be checked for validity within the grid.
 param (grid): The 3x3 grid
 
 Return value: Returns 1 if the symbol is a valid move within the 'grid', otherwise it returns 0.
*/
int isValidMove(char symbol, char (*grid)[3]) {
	int i, j;
    // Check if the symbol is a valid move for the given grid (front, middle, or back)
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            if (grid[i][j] == symbol)
                return 1;
        }
    }

    return 0;
}
/*
 Description: This function checks if a player has won the game.
 Parameters: 
 param grid: It represents the current state of the game grid.
 param player: The character representing the player to check for a win (Player 'X' or Player 'O').
 
 Return value: Returns 1 if Player X or Player O has won the game, otherwise it will returns 0.
*/
int checkWin(char grid[3][3], char player) {
    int i, j;

    // for vertical lines
    for (i = 0; i < 3; i++) {
        if (grid[0][i] == player && grid[1][i] == player && grid[2][i] == player)
            return 1;
    }

    // for horizontal lines
    for (i = 0; i < 3; i++) {
        if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player)
            return 1;
    }

    // for diagonal lines
    if ((grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) ||
        (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player))
        return 1;

    return 0;
}
/*
 Description: This function checks if the game has resulted in a draw, meaning all cells 
 					in the three 3x3 grids (front, middle, and back) are occupied.
 Parameters: 
 param (front): the front face of the game.
 param (middle): the middle face of the game.
 param (back): the back face of the game.
 
 Return value: Returns true if all cells in the three grids are occupied, indicating a draw. Otherwise, returns false.
*/
bool checkDraw(char front[3][3], char middle[3][3], char back[3][3]) {
    int row, col;

    // Check if all cells are occupied
    for (row = 0; row < 3; row++) {
        for (col = 0; col < 3; col++) {
            if (front[row][col] != 'X' && front[row][col] != 'O') {
                return false; // There is an empty cell, so it's not a draw
            }
            if (middle[row][col] != 'X' && middle[row][col] != 'O') {
                return false; // There is an empty cell, so it's not a draw
            }
            if (back[row][col] != 'X' && back[row][col] != 'O') {
                return false; // There is an empty cell, so it's not a draw
            }
        }
    }

    // All cells are occupied, it's a draw
    return true;
}
/*
 Description: This represents a 3D Tic-Tac-Toe game where players take turns placing their 
 	markers on a 3x3 grid on each of three faces (front, middle, and back). The game will continue until a 
 			player wins, the game is drawn, or the players decide to end it. This function handles the game 
			 						flow and player interactions.
 Parameters: 
 param (front): the front face of the game.
 param (middle): the middle face of the game.
 param (back): the back face of the game.
 param (initialPlayer): The player ('X' or 'O').
 
 Return value: This function does not return anything (void).
*/
void dTicTacToe(char front[3][3], char middle[3][3], char back[3][3], char initialPlayer){
	char player = initialPlayer;
    char symbol;
    int flipPowerupsPlayerX = 0; // Number of flip powerups for player X
    int flipPowerupsPlayerO = 0; // Number of flip powerups for player O

    while (1) {
		printf("----------------------- PLAYER %c TURN -----------------------\n", player == 'X' ? 'X' : 'O');
        printf("Front Face:\n");
        print3x3Grid(front);

        printf("\nMiddle Face:\n");
        print3x3Grid(middle);

        printf("\nBack Face:\n");
        print3x3Grid(back);
        
        printf("\nYou have %d flip(s)!\n", (player == 'X') ? flipPowerupsPlayerX : flipPowerupsPlayerO);
        if ((player == 'X' && flipPowerupsPlayerX > 0) || (player == 'O' && flipPowerupsPlayerO > 0)) {
            char response;
            printf("Would you like to use a flip? (Y or N): ");
            scanf(" %c", &response);
            if (response == 'Y' || response == 'y') {
                        printf("Player %c used a flip powerup!\n", player);
                        (player == 'X') ? flipPowerupsPlayerX-- : flipPowerupsPlayerO--;
                        player = (player == 'X') ? 'O' : 'X'; // Switch to the next player
                    }
        		}
        printf("\nSelect a space to place your marker: ");
        scanf(" %c", &symbol);

        // Check if the chosen cell is valid and available
        int valid_move = 0;
        char* face;
        char (*grid)[3];

        // check if the symbol is a valid move for any of the faces
        if (isValidMove(symbol, front)) {
            face = "Front Face";
            grid = front;
            valid_move = 1;
        } else if (isValidMove(symbol, middle)) {
            face = "Middle Face";
            grid = middle;
            valid_move = 1;
        } else if (isValidMove(symbol, back)) {
            face = "Back Face";
            grid = back;
            valid_move = 1;
        } 
        

        if (!valid_move) {
            printf("Invalid move. Please choose a valid cell.\n");
        } else {

            int row, col, i, j;
            int found = 0;

            for (row = 0; row < 3 && !found; row++) {
                for (col = 0; col < 3 && !found; col++) {
                    if (grid[row][col] == symbol) {
                        if (grid[row][col] == 'X' || grid[row][col] == 'O') {
                            printf("Cell already occupied. Choose another cell.\n");
                        } else {
                            grid[row][col] = (player == 'X') ? 'X' : 'O';
                            found = 1;
                        }
                	}
        		}
        	}
				// special location for collecting flip powerups
                if (symbol == 'b' || symbol == 'd' || symbol == 'f' || symbol == 'h' ||
                    symbol == 's' || symbol == 'u' || symbol == 'w' || symbol == 'y') {
                    int* flipPowerups = (player == 'X') ? &flipPowerupsPlayerX : &flipPowerupsPlayerO;
                    printf("\nPlayer %c collected a flip powerup!\n", player == 'X' ? 'X' : 'O');
                    (*flipPowerups)++; // for adding the number of flip power-ups for the respective player (+1)
                    }
		            
            // This will check if the current player has won the game
            if (checkWin(grid, player)) {
                printf("Player %c won the game!\n", player == 'X' ? 'X' : 'O');
                return; // End the game
            }
            //This will check if the game is draw
            if (checkDraw(front, middle, back)) {
            	printf("The game is a draw!\n");
            	return; // End the game
        	}
        	// Switch to the other player for the next turn
			player = (player == 'X') ? 'O' : 'X';
    		}
		}
	}
/*
 Description: This represents the main entry point of the 3D Tic-Tac-Toe game. It initializes the game 
 	grids (front, middle, and back), starts the game loop, and handles the flow of the game, including player 
 				interactions and offering the option to play again after the game ends.
 
 Parameters: no parameters.

 Return value: The function returns an integer value (int). In this case, it always returns 0 to indicate successful program execution.
*/
int main(){
	char front[3][3] = {
        {'a', 'b', 'c'},
        {'d', 'e', 'f'},
        {'g', 'h', 'i'}
    };

    char middle[3][3] = {
        {'j', 'k', 'l'},
        {'m', '@', 'n'},
        {'o', 'p', 'q'}
    };

    char back[3][3] = {
        {'r', 's', 't'},
        {'u', 'v', 'w'},
        {'x', 'y', 'z'}
    };
    char player = 'X';
    char again;
    
    do {
        dTicTacToe(front, middle, back, player);

        // shows the winning board
        printf("\n\n===============================================================\n");
        printf("Winning Board:\n");
		printf("Front Face:\n\n");
        print3x3Grid(front);
        printf("Middle Face:\n\n");
        print3x3Grid(middle);
        printf("Back Face:\n\n");
        print3x3Grid(back);
        
        printf("\nPlayer %c won the game!\n", player == 'X' ? 'X' : 'O');
        printf("\n\n===============================================================\n");
         // This will ask if the players want to play again
        bool playerXAgree = false;
        bool playerOAgree = false;

        while (!playerXAgree || !playerOAgree) {
            printf("Player X, do you want to play again? (Y or N): ");
            char responseX;
            scanf(" %c", &responseX);
            playerXAgree = (responseX == 'Y'|| responseX == 'y');

            printf("Player O, do you want to play again? (Y or N): ");
            char responseO;
            scanf(" %c", &responseO);
            playerOAgree = (responseO == 'Y'|| responseO == 'y');

            if (playerXAgree && playerOAgree) {
                // Switch the starting player for the new game
                player = (player == 'X') ? 'O' : 'X';
            } else {
                printf("Both players must agree to play again.\n");
                playerXAgree = false;
                playerOAgree = false;
                printf("Thank you for playing!\n");
				return 0;
            }
        }

    } while (true);
	
	return 0;
}
