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
    /*int value;*/
    int turn = 1;
    sem_t * hong = sem_open("hong", O_CREAT, 0666, 1);
    sem_t * hei = sem_open("hei", O_CREAT, 0666, 0);
    /*sem_getvalue(mutex, &value);
    printf("%d\n",value);*/
    for(turn; turn < 11; turn++){
        sem_wait(hong); //If hong is 1, make it zero, and proceed, if it is 0, wait until it is 1. Hong is initialized as 1, therefore it always shall be first.
        sleep(1);
        printf("Red goes, turn %d\n", turn);
        sem_post(hei); //When red finish with their turn, allow the black to do the turn too.
    }
    //Close all semaphores ones we finish.
    sleep(1);
    //Red won!
    printf("Red wins!");
    sem_close(hong);
    sem_unlink("hong");
    sem_close(hei);
    sem_unlink("hei");
    exit(0);
}