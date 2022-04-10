#include <stdio.h>
#include <stdlib.h>

int main()
{
    // A Tennis Match Program

    // Initial number of the rounds won for player1 and player2.
    int player1 = 0; 
    int player2 = 0;

    int input = 0; // User input for winner.
    int gap = 3; // 3 for default (below 40 points) --> if player1 - player2 = gap or player2 - player1 = gap, game ends.

    while (1) { // 1 is a true value, it will continune until break command.

        if ((player1 <= 3 && player2 < 3) || (player2 <= 3 && player1 < 3)) {

            if (player1 == 3 && player2 != 3) {  // 0 => 0, 1 => 15, 2 => 30, 3=> 40
                printf("40-%d\n", player2 * 15);
            } else if (player2 == 3 && player1 != 3) {
                printf("%d-40\n", player1 * 15); 
            } else {
                printf("%d-%d\n", player1 * 15, player2 * 15); // Multiplying with 15, 1*15 = 15 points, 2*15 = 30 points etc.
            }

        } else if (player1 >= 3 && player2 >= 3) {

            if (player1 - player2 == 1) {  
                printf("ADVANTAGE: PLAYER 1\n");
            } else if (player2 - player1 == 1) {
                printf("ADVANTAGE: PLAYER 2\n");
            } else if (player1 == player2) {
                printf("DEUCE\n");
            }
        }

        // Taking input from the user for point.
        printf("Point: ");
        scanf("%d", &input); 

        // Increasing points by 1 depending on the input.
        if (input == 1) {
            player1 += 1;
        } else if (input == 2) {  
            player2 += 1;
        }

        // Set gap to be 2. Because above 40 points, winner of the match must win 2 matches in a row.//                                 
        if (player1 > 3 || player2 > 3) {  
            gap = 2;                     
        }

        if (player1 - player2 >= gap && player1 > 3) {
            printf("GAME: PLAYER 1\n");
            break;
        } else if (player2 - player1 >= gap && player2 > 3) {
            printf("GAME: PLAYER 2\n");
            break;
        }
    }
    return 0;
}
