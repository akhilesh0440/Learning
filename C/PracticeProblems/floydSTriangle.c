// Floyd's Triangle is a right-anlgle triangula array of natural nubers.
// It is filled by natural numbers consecutively starting with 1 in the top left corner

#include<stdio.h>

int main(){
    int floyd, last = 0;

    printf("How many rows is needed in Floyd's triangle\n");
    scanf("%d", &floyd);

    for(int i = 0; i < floyd; i++){
        for(int j = 0; j <= i; j++){
            last++;
            printf("%d ", last);
        }
        printf("\n");
    }
    return 0;
}