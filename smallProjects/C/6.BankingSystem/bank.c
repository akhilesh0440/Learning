#include<stdio.h>
#include<string.h>

void create_account();
void depositMoney();
void withdrawMoney();
void checkBalance();

typedef struct {
    char name[50];
    int accNo;
    float balance;
}Account;

const char* ACCOUNT_NAME = "account.dat";

int main(){
    while(1){
        int choice;
        printf("\n\n*** Bank Management System ***");
        printf("\n1. Create Account");
        printf("\n2. Deposit Money");
        printf("\n3. Withdraw Money");
        printf("\n4. Check balance");
        printf("\n5. Exit");
        printf("\nEnter your choice: ");
        scanf("%d", &choice);

        switch(choice){
            case 1:
                create_account();
                break;
            case 2:
                depositMoney();
                break;
            case 3:
                withdrawMoney();
                break;
            case 4:
                checkBalance();
                break;
            case 5:
                printf("\nClosing the Bank, Thanks for your visit\n");
                return 0;
                break;
            default:
                printf("\nInvalide choice");
                
        }
    }
}

void create_account(){

    FILE *file = fopen(ACCOUNT_NAME, "ab+");
    if(file == NULL){
        printf("\nUnable to open the file.");
        return;
    }

    char c;
    do{
        c = getchar();
    }while(c != '\n' && c != EOF);
    Account acc;
    printf("\nEnter your name: ");
    fgets(acc.name, sizeof(acc.name), stdin);
    int ind = strcspn(acc.name, "\n");
    acc.name[ind] = '\0';
    printf("Enter your account number: ");
    scanf("%d", &acc.accNo);
    acc.balance = 0;

    fwrite(&acc, sizeof(acc), 1, file);
    fclose(file);
    printf("Account created successfully!");
}

void withdrawMoney(){
        FILE *file = fopen(ACCOUNT_NAME, "rb+");
    if(file == NULL){
        printf("\nUnable to open the file.");
        return;
    }
    int accNo;
    float money;
    Account accRead;
    printf("\nEnter your account number: ");
    scanf("%d", &accNo);
    printf("Enter the withdraw amount: ");
    scanf("%f", &money);

    while(fread(&accRead, sizeof(accRead), 1, file)){
        if(accRead.accNo == accNo){
            if(accRead.balance >= money){
                accRead.balance -= money;
                fseek(file, -sizeof(Account), SEEK_CUR);
                fwrite(&accRead, sizeof(Account), 1, file);
                fclose(file);
                printf("\nSuccessfully withdrawn Rs.%.2f. Total balance  %d is Rs.%.2f/-", money, accRead.accNo, accRead.balance);
                return;
            }
            else{
                printf("\nMoney could not be withdrawn .\nLow balance!!!\nCurrent balance of the Account number %d is RS.%.2f", accRead.accNo, accRead.balance);
                return;
            }
        }
    printf("\nRequest failed!!!\nAs the Account no %d was not found in records", accNo);
    fclose(file);
    }
}

void depositMoney(){
    FILE *file = fopen(ACCOUNT_NAME, "rb+");
    if(file == NULL){
        printf("\nUnable to open the file.");
        return;
    }
    int accNo;
    float money;
    Account accRead;
    printf("\nEnter your account number: ");
    scanf("%d", &accNo);
    printf("Enter the deposit amount: ");
    scanf("%f", &money);
    
    while(fread(&accRead, sizeof(accRead), 1, file)){
        if(accRead.accNo == accNo){
            accRead.balance += money;
            fseek(file, -sizeof(Account), SEEK_CUR);
            fwrite(&accRead, sizeof(Account), 1, file);
            fclose(file);
            printf("\nSuccessfully deposited Rs.%.2f. Total balance  %d is Rs.%.2f/-", money, accRead.accNo, accRead.balance);
            return;
        }
    }
    printf("\nMoney cound not be deposited as the Account no %d was not found in records", accNo);
    fclose(file);

}

void checkBalance(){
    FILE *file = fopen(ACCOUNT_NAME, "ab+");
    if(file == NULL){
        printf("\nUnable to open the file.");
        return;
    }

    int accNo;
    Account accRead;
    printf("\nEnter your account number: ");
    scanf("%d", &accNo);

    while(fread(&accRead, sizeof(accRead), 1, file)){
        if(accRead.accNo == accNo){
            printf("Your current balance is RS.%.2f", accRead.balance);
            fclose(file);
            return;
        }
    }
    fclose(file);
    printf("\nAccount No: %d was not found", accNo);
}