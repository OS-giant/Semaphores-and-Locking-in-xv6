#include "types.h"
#include "stat.h"
#include "user.h"
#include "spinlock.h"
#include "semaphore.h"

struct condvar
{
    struct spinlock lock;
};

int main(int argc, char *argv[]){
    struct condvar condvar;

    int pid = fork();
    if (pid < 0) {
        printf(1, "could not fork a child.\n");
    }

    else if (pid == 0) {
        int pid1 = fork();
        if(pid1 == 0){
            int pid1 = fork();
            if(pid1 == 0){
                writer(1,&condvar);
            }
            else{
                reader(2,&condvar);
                wait();
            }
        }
        else{
            reader(1,&condvar);
            wait();
        }
    }

    else {
        int pid1 = fork();

        if(pid1 == 0) {
            writer(0,&condvar);
        }

        else {

            reader(0,&condvar);
            wait();
        }

        wait();
    }

    exit();
    // sem_init(&accessSemaphore, 0, 1); // Initialize access semaphore with value 1
    // sem_init(&counterSemaphore, 0, 1); // Initialize counter semaphore with value 1

    // // Create reader and writer threads
    // pthread_t readerThreads[3];
    // pthread_t writerThreads[2];

    // for (int i = 0; i < 3; ++i) {
    //     pthread_create(&readerThreads[i], NULL, (void *(*)(void *))reader, (void *)i);
    // }

    // for (int i = 0; i < 2; ++i) {
    //     pthread_create(&writerThreads[i], NULL, (void *(*)(void *))writer, (void *)i);
    // }

    // // Wait for threads to finish
    // for (int i = 0; i < 3; ++i) {
    //     pthread_join(readerThreads[i], NULL);
    // }

    // for (int i = 0; i < 2; ++i) {
    //     pthread_join(writerThreads[i], NULL);
    // }

    // // Destroy semaphores
    // sem_destroy(&accessSemaphore);
    // sem_destroy(&counterSemaphore);

    // return 0;
    return 0;
}