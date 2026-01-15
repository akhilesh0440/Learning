#include<stdio.h>
#include<stdlib.h>
#include<time.h>
#include<unistd.h>

void fill_time(char*, int);
void fill_date(char*);
int input_format();
void clearScreen();

int main(){
    char time[50], date[100];
    int format = input_format();
    
    while(1){
        fill_time(time, format);
        fill_date(date);
        clearScreen();
        printf("\nCurrent Time: %s", time);
        printf("\nDate: %s\n", date);
        sleep(1);
    }
    
}

void clearScreen(){
    #ifdef __WIN32
        system("cls");
    #else
        system("clear");
    #endif

}

void fill_date(char* buffer){
    time_t rawTime;
    struct tm *currentTime;

    time(&rawTime);
    currentTime = localtime(&rawTime);
    
    strftime(buffer, 50, "%A %B %D %Y", currentTime);
}

int input_format(){
    int format;
    printf("\nChoos the time format: ");
    printf("\n1. 24 Hour format");
    printf("\n2. 12 Hour format");
    printf("\nMake a choice(1/2): ");
    scanf("%d", &format);
    return format;
}

void fill_time(char *buffer, int format){
    time_t rawTime;
    struct tm *currentTime;

    time(&rawTime);
    currentTime = localtime(&rawTime);
    
    if(format == 1){
        strftime(buffer, 50, "%H:%M:%S", currentTime);
    }else if(format == 2){
        strftime(buffer, 50, "%I:%M:%S %p", currentTime);
    }
}