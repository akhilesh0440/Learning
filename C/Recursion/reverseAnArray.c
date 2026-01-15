#include<stdio.h>

void swap(int *a, int *b){
    int *temp = a;
    *a = *b;
    *b = *temp;

}
void f(int *a, int *b){
    if(a>=b) return;
    swap(a, b);
    f(a+1, b-1);
}

int main(){
    int n;
    int *arr;
    printf("Enter the size of array.\n");
    scanf("%d", &n);

    printf("Enter the elements of array.\n");
    for(int i=0; i<n; i++){
        scanf("%d", arr+i);
    }

    f(&arr[0], &arr[n-1]);
    printf("Elements of the array of reverse\n");
    for(int i=0; i<n; i++){
        printf("%d ", arr[i]);
    }
    return 0;

}