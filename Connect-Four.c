/*
    Connect-Four.c
    Created by ozan on 2nd of June 2023

    Classic Connect Four implementation with C for 2 players.
*/

#include <stdio.h>
#define rows 6
#define columns 8

void drawBoard(int board[rows][columns]){
    for(int i = 0; i < rows; i++){
        for(int j=0; j<columns; j++){
            if (board[i][j] == 0){
                printf("|  ");
            }
            else if(board[i][j] == 1){
                printf("|R ");
            }
            else if(board[i][j] == 2){
                printf("|B ");
            }
        }
        printf("|\n");
    }
    printf("----------------\n");
    for (int j = 0; j < columns - 1; j++) {
        printf(" %d ", j + 1);
    }
    printf("%d\n", columns);
}

int boardFullCheck(int board[rows][columns]){
    for(int i = 0; i < rows; i++){
        for (int j = 0; j<columns; j++){
            if(board[i][j] == 0){
                return 0;
            }
        }
    }
    return 1;
}

int gameEndCheck(int board[rows][columns], int playerTile){
    for (int i = 0; i < rows - 3; i++){
        for (int j = 0; j < columns; j++){
            if(board[i][j] == playerTile && board[i+1][j] == playerTile && board[i+2][j] == playerTile && board[i+3][j] == playerTile){
                return 1;
            }
        }
    }
    for (int i = 0; i < rows; i++){
        for (int j = 0; j < columns - 3; j++){
            if(board[i][j] == playerTile && board[i][j+1] == playerTile && board[i][j+2] == playerTile && board[i][j+3] == playerTile){
                return 1;
            }
        }
    }
    for (int i = 0; i < rows - 3; i++){
        for (int j = 0; j < columns - 3; j++){
            if(board[i][j] == playerTile && board[i+1][j+1] == playerTile && board[i+2][j+2] == playerTile && board[i+3][j+3] == playerTile){
                return 1;
            }
            else if(board[i][j+3] == playerTile && board[i+1][j+2] == playerTile && board[i+2][j+1] == playerTile && board[i+3][j] == playerTile){
                return 1;
            }
        }
    }
    return 0;
}
void playerChanger(int *playerTurn){
if(*playerTurn == 1){
*playerTurn = 2;
}
else{
*playerTurn = 1;
}
}

void connectFourTime(){
    int board[rows][columns];
    int player = 1;
    for(int i=0; i < rows; i++){
        for(int j=0; j < columns ; j++){
        board[i][j] = 0;
        }   
    }
    int validMove = 0;
    int chosen;
    while(gameEndCheck(board, player)!=1 && boardFullCheck(board)!=1){
        drawBoard(board);
        validMove = 0;
        printf("Player %d, choose a column: ", player);
        scanf("%d", &chosen);
        if(chosen >= 1 && chosen <= columns){
            chosen--;
            for(int i = rows - 1 ; i >= 0 ; i--){
                if(board[i][chosen] == 0){
                board[i][chosen] = player;
                validMove = 1;
                break;
                }
            }
        }
        if(!validMove){
        printf("pick something else!\n");
        }
        else {
            playerChanger(&player);
        }
    }

    drawBoard(board);
    if (gameEndCheck(board, player)) {
        printf("player %d wins\n", player);
    } 
    else if (boardFullCheck(board)) {
        printf("tied\n");
    }
}

int main(){
connectFourTime();
return 0;
}