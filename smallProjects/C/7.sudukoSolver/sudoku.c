#include <stdio.h>

int puzzle[9][9] = {
    {3, 0, 0, 0, 2, 0, 0, 7, 0}, 
    {9, 0, 0, 5, 0, 0, 0, 1, 4},
    {0, 1, 6, 3, 7, 0, 0, 0, 8},
    {2, 0, 0, 8, 0, 0, 0, 0, 1},
    {5, 0, 0, 0, 4, 1, 8, 0, 0}, 
    {0, 8, 9, 0, 0, 0, 0, 5, 0},
    {0, 0, 5, 0, 1, 0, 2, 8, 0}, 
    {0, 4, 0, 0, 0, 6, 0, 9, 3},
    {7, 3, 1, 0, 8, 2, 0, 0, 0}
};

void printPuzzle(int puzzle[9][9]);
int validMove(int puzzle[9][9], int row, int col, int value);
int solvePuzzle(int puzzle[9][9], int row, int col);

int main(){
    printf("\n\tWelcome to SUDOKU Solver !!!");
    printf("\nOriginal Puzzle:");
    printPuzzle(puzzle);

    if(solvePuzzle(puzzle, 0, 0)){
        printf("Puzzle is solved!!!");
        printPuzzle(puzzle);
    }
    else{
        printf("\n This puzzle is not Solvable.\n");
    }

}

int solvePuzzle(int puzzle[9][9], int row, int col){
    if(col == 9){
        if(row == 8){
            return 1; //Puzzle is solved
        }    
        row++;
        col = 0;
    }

    if(puzzle[row][col] > 0){
        return solvePuzzle(puzzle, row, col+1);
    }

    for(int i = 1; i <= 9; i++){
        if(validMove(puzzle, row, col, i)){
            puzzle[row][col] = i;
            if(solvePuzzle(puzzle, row, col+1)){
                return 1;
            }
            puzzle[row][col] = 0;
        }
    }
    return 0;
}


int validMove(int puzzle[9][9], int row, int col, int value){
    for(int i = 0; i < 9; i++){
        if(puzzle[row][i] == value){
            return 0;
        }
    }

    for(int i = 0; i < 9; i++){
        if(puzzle[i][col] == value){
            return 0;
        }
    }

    int r = row - row % 3;
    int c = col - col % 3;
    
    for(int i = 0; i < 3; i++){
        for(int j = 0; j < 3; j++){
            if(puzzle[r+i][c+i] == value){
                return 0;
            }
        }
    }
    return 1;
}


void printPuzzle(int puzzle[9][9]){
    printf("\n+-------+-------+-------+");

    for(int i=0; i < 9; i++){
        if(i%3 == 0 && i != 0) printf("\n|-------+-------+-------|");
        printf("\n");
        for(int j = 0; j < 9; j++){
            if(j%3 == 0) printf("| ");
            if(puzzle[i][j] != 0){
                printf("%d ", puzzle[i][j]);
            }
            else{
                printf("  ");
            }
        }
        printf("|");

    }
    printf("\n+-------+-------+-------+\n");

};
