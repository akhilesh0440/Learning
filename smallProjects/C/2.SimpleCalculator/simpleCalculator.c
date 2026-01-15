#include<stdio.h>
#include<math.h>

void printMenu();
double division(double, double);
double modulus(int, int);

int main(){
    int choice;
    double first, second, result;

    while(1){
        printMenu();
        scanf("%d", &choice);

        if(choice == 7) break;

        if(choice < 1 || choice > 7){
            fprintf(stderr, "Invalid Menu choice selection\n");
            continue;
        }

        printf("Enter the numbers: ");
        scanf("%lf%lf", &first, &second);

        switch (choice)
        {
        case 1:
            result = first + second;
            break;        
        case 2:
            result = first - second;
            break;        
        case 3:
            result = first * second;
            break;
        case 4:
            result = division(first, second);
            break;
        case 5:
            result = modulus(first, second);
            break;
        case 6:
            result = pow(first, second);
            break;
        }
        if(result != NAN){
            printf("\nResult of the operation is %lf", result);
        }
    };
}

double division(double a, double b){
    if(b == 0){
        fprintf(stderr, "Invalid Argument for Division");
        return NAN;
    }else{
        return a/b;
    }
}

double modulus(int a, int b){
    if(b == 0){
        fprintf(stderr, "Invalid Argument for Division");
        return NAN;
    }else{
        return a % b;
    }
}

void printMenu(){
    printf("\n\n\n-----------------------------\n");
    printf("Welcome to simple Calculator\n");
    printf("\nChoose one of the following options:");
    printf("\n1. Add");
    printf("\n2. Subtract");
    printf("\n3. Multiply");
    printf("\n4. Divide");
    printf("\n5. Modulus");
    printf("\n6. Power");
    printf("\n7. Exit");
    printf("\nNow, Enter the choice: ");
}