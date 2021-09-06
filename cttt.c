#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void * Logic(char plr[], int board[]){
    int input;

    if(plr == "p1"){
        printf("\nPlayer 1, your turn!\n");
        scanf("%d", &input);

        // Player 1
        for(int i = 0; i < 9; i++){ // Input their number in designated location
            if(i == input && board[i] == 0){
                board[i] = 1;
            }
        }
        for(int i = 0; i < 9; i++){ // Print board
            printf("| %d |", board[i]); 
            if(i == 2){
                printf("\n");
            }
            else if(i == 5){
                printf("\n");
            }
        }
    }

    else if(plr == "p2"){
        printf("\nPlayer 2, your turn!\n");
        scanf("%d", &input);

        // Player 2
        for(int i = 0; i < 9; i++){ // Input their number in designated location
            if(i == input && board[i] == 0){
                board[i] = 2;
            }
        }
        for(int i = 0; i < 9; i++){ // Print board
            printf("| %d |", board[i]); 
            if(i == 2){
                printf("\n");
            }
            else if(i == 5){
                printf("\n");
            }
        }
    }
}

int GameOver(int board[]){
    for(int i = 0; i < 9; i++){ // Print board
        
        // Win condition for player 1
        if(board[0] == 1 && board[1] == 1 && board[2] == 1 || board[3] == 1 && board[4] == 1 && board[5] == 1 || board[6] == 1 && board[7] == 1 && board[8] == 1){ // X
            printf("\n\nPlayer 1 is WINRAR!!");
            return 1;
        }
        else if(board[0] == 1 && board[3] == 1 && board[6] == 1 || board[1] == 1 && board[4] == 1 && board[7] == 1 || board[2] == 1 && board[5] == 1 && board[8] == 1){ // Y
            printf("\n\nPlayer 1 is WINRAR!!");
            return 1;
        }
        else if(board[0] == 1 && board[4] == 1 && board[8] == 1 || board[2] == 1 && board[4] == 1 && board[6] == 1){ // XY
            printf("\n\nPlayer 1 is WINRAR!!");
            return 1;
        }

        // Win condition for player 2
        else if(board[0] == 2 && board[1] == 2 && board[2] == 2 || board[3] == 2 && board[4] == 2 && board[5] == 2 || board[6] == 2 && board[7] == 2 && board[8] == 2){ // X
            printf("\n\nPlayer 2 is WINRAR!!");
            return 1;
        }
        else if(board[0] == 2 && board[3] == 2 && board[6] == 2 || board[1] == 2 && board[4] == 2 && board[7] == 2 || board[2] == 2 && board[5] == 2 && board[8] == 2){ // Y
            printf("\n\nPlayer 2 is WINRAR!!");
            return 1;
        }
        else if(board[0] == 2 && board[4] == 2 && board[8] == 2 || board[2] == 2 && board[4] == 2 && board[6] == 2){ // XY
            printf("\n\nPlayer 2 is WINRAR!!");
            return 1;
        }
        else{
            return 0;
        }
    }
} 

void Game(){
    bool player1 = true;
    bool player2 = false;
    bool gameOver = false;

    int board[9] = {
        0, 0, 0, 
        0, 0, 0, 
        0, 0, 0
    };
    
    // Turn into setup
    while(!gameOver){
        if(player1){
            Logic("p1", board);
            player1 = false;
            player2 = true;
        }
        else if(player2){
            Logic("p2", board);
            player2 = false;
            player1 = true;
        }
        if(GameOver(board) == 1){
            gameOver = true;
        }
    }
    printf("\n############################################################## End ##############################################################");
}


int main(){
    Game();
    return 0;
}