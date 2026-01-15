// WAP to multiply the two matrices

#include<stdio.h>

int main()
{
    int matrix1[3][3] = {
        {1, 2, 3},
        {1, 2, 1},
        {3, 1, 2}
    };
    
    int matrix2[3][3] = {
        {1, 2, 3},
        {1, 2, 1},
        {3, 1, 2}
    };
    
    int resultMatrix[3][3];
    
    printf("Matrix 1:\n");
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("%d ", matrix1[i][j]);
        }
        printf("\n");
    }

    printf("Matrix 2:\n");
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("%d ", matrix2[i][j]);
        }
        printf("\n");
    }

    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            int sum = 0;
            for(int k=0; k<3; k++){
                sum += matrix1[i][k] * matrix2[k][j];
            }
            resultMatrix[i][j] = sum;
        }
    }

    printf("\nResult matrix is:\n");
    for(int i=0; i<3; i++)
    {
        for(int j=0; j<3; j++)
        {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }
    return 0;
}