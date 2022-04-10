#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){

    int loop = 0;
    srand(time(NULL));
    int win_count = 0;

    while(loop < 100000){

        int dice1 = rand() % 6 + 1;
        int dice2 = rand() % 6 + 1;
        int sum = dice1 + dice2;

        if(sum == 7 || sum == 11){
            win_count++;
        }

        else if(sum == 4 || sum == 5 || sum == 6 || sum == 8 || sum == 9 || sum == 10){
            int new_dice_sum = 0;

            while(new_dice_sum != 7 && new_dice_sum != sum){

                dice1 = rand() % 6 + 1;
                dice1 = rand() % 6 + 1;
                new_dice_sum = dice1 + dice2;

                if(new_dice_sum == sum){
                    win_count++;
                }
            }
        }
        loop++;
    }

    float win_rate = win_count / 100000.0;

    printf("Win rate is %.2f\n", win_rate);
    printf("Lose rate is %.2f\n", 1 - win_rate);
}
