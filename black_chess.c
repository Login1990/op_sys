#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <semaphore.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <unistd.h>
#include <string.h>

//Abdirizaq Ali 000506148
//Lev Samin 000409096

int main(int argc, char*argv[]){
    int turn = 1;
    sem_t * hong = sem_open("hong", O_CREAT, 0666, 1); 
    sem_t * hei = sem_open("hei", O_CREAT, 0666, 0);
    for(turn; turn < 11; turn++){ 
        sem_wait(hei); //If hei is 1, make it zero, and proceed, if it is 0, wait until it is 1. Hei is initialized as 0, therefore it always shall be second.
        sleep(1);
        printf("Black goes, turn %d\n", turn);
        sem_post(hong); //Once black finishes their turn, sem_post to make hong 1 so that red can make their turn
    }
    //Close all semaphores ones we finish.
    //
    sem_close(hong);
    sem_unlink("hong");
    sem_close(hei);
    sem_unlink("hei");
    exit(0);   
}