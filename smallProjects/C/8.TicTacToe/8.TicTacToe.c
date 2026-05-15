#include <stdio.h>
#include <stdlib.h>

#define BOARD_SIZE 3

typedef struct {
    int player;
    int computer;
    int draw;
}Score;

int difficulty;
Score score = {.player = 0, .computer = 0, .draw = 0};

void input_difficulty();
void clear_screen();
void print_board(char board[BOARD_SIZE][BOARD_SIZE]);
int check_win(char board[BOARD_SIZE][BOARD_SIZE], char player);
int check_draw(char board[BOARD_SIZE][BOARD_SIZE]);


int main(){
    input_difficulty();
    char board[BOARD_SIZE][BOARD_SIZE] = {
        {' ', ' ', ' '},
        {' ', ' ', ' '},
        {' ', ' ', ' '}
    };
    print_board(board);
}

int check_win(char board[BOARD_SIZE][BOARD_SIZE], char player){
    for(int i = 0; i < BOARD_SIZE; i++){
        if(board[i][0] == player && board [i][1] == player && board [i][2] == player){
            return 1;
        }
    }

    for(int i = 0; i < BOARD_SIZE; i++){
        if(board[0][i] == player && board [1][i] == player && board [i][2] == player){
            return 1;
        }
    }

    if((board[1][1] == player && board [2][2] == player && board [0][0] == player) 
    || (board[1][1] == player && board [2][2] == player && board [0][0] == player)){
            return 1;
        }

    return 0;
};

int check_draw(char board[BOARD_SIZE][BOARD_SIZE]){
    for(int i = 0; i < BOARD_SIZE; i++){
        for(int j = 0; j < BOARD_SIZE; j++){
            if(board[i][j] == ' '){
                return 0;
            }
        }
    }
    return 1;
};

void print_board(char board[BOARD_SIZE][BOARD_SIZE]){
    clear_screen();
    printf("\nScore - Player X: %d, Compter: %d, Draws: %d\nTic Tac Toe", score.player, score.computer, score.draw);
    for(int i = 0; i < BOARD_SIZE; i++){
        printf("\n");
        for(int j = 0; j < BOARD_SIZE; j++){
            printf(" %c ", board[i][j]);
            if(j < 2) printf("|");
        }
            if(i < 2) printf("\n---+---+---");
    }
}

void input_difficulty(){
    while(1)
    {
        printf("\nSelect difficulty level:");
        printf("\n1. Human (Standard)");
        printf("\n2. God (Impossible to win)");
        printf("\nEnter your choice: ");
        scanf("%d", &difficulty);

        if(difficulty != 1 && difficulty != 2){
            printf("\nIncorrect choice entered (1/2)!!");
        }
        else{
            break;
        }
    } 
}

void clear_screen(){
 #ifdef _WIN32
    system("cls");    
#else
    system("clear");   
#endif
}