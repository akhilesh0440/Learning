#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <time.h>

const int BAR_LENGTH = 50;
const int MAX_TASK = 10;

typedef struct {
    int id; 
    int progress;
    int step;
}Task;

void print_bar(Task);
void clearScreen();

int main(){
    Task tasks[MAX_TASK];
    srand(time(NULL));

    for(int i = 0; i < MAX_TASK; i++){
        tasks[i].id = i+1;
        tasks[i].progress = 0;
        tasks[i].step = rand() % 5 + 1;
    }
    int task_incomplete = 1;
    while (task_incomplete){
        task_incomplete = 0;
        clearScreen();
        for(int i = 0; i < MAX_TASK; i++){
            tasks[i].progress += tasks[i].step;
            if(tasks[i].progress > 100){
                tasks[i].progress = 100;
            }else if(tasks[i].progress < 100){
                task_incomplete = 1;
            }
            print_bar(tasks[i]);
        }
        sleep(1);
    }
    printf("\nAll tasks completed!\n");
    return 0;
}

void clearScreen(){
    #ifdef __WIN32
        system("cls");
    #else
        system("clear");
    #endif

}

void print_bar(Task task){
    printf("\nTask %d: [", task.id);

    for(int i = 0; i < BAR_LENGTH; i++){
        int bars_to_show = (task.progress * BAR_LENGTH) / 100;
        if(i < bars_to_show){
            printf("=");
        }else{
            printf(" ");
        }
    }
    printf("] %d%%", task.progress);
};
