// WAP to that reads a 5x5 array of integers and then prints the row sum and the column sum:

#include<stdio.h>

int main()
{
    int array[5][5] = {
        {8, 3, 9, 0, 10},
        {3, 5, 17, 1, 1},
        {2, 8, 6, 23, 1},
        {15, 7, 3, 2, 9},
        {6, 14, 2, 6, 0}
    };
    
    // int array[5][5];
    int columnTotal[5] = {0}, rowTotal[5] = {0};

    for(int i=0; i<5; i++)
    {
        printf("Row %d: ", i+1);
        for(int j=0; j<5; j++){
            printf("%d ", array[i][j]);
            // scanf("%d", &array[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<5; i++)
    {
        for(int j=0; j<5; j++){
            rowTotal[i] += array[i][j];
            columnTotal[i] += array[j][i];
        }
    }
    printf("\n");

    printf("Row total: ");
    for(int i=0; i<5; i++)
    {
        printf("%d ", rowTotal[i]);
    }
    printf("\n");

    printf("Column total: ");
    for(int i=0; i<5; i++)
    {
        printf("%d ", columnTotal[i]);
    }
    return 0;

}