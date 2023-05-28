#include "types.h"
#include "stat.h"
#include "user.h"
#include "spinlock.h"

struct condvar
{
    struct spinlock lock;
};

int main(int argc, char *argv[]){
    struct condvar condvar;
    struct condvar condvar;

    int index = 0;
    int pid = fork();
    if (pid < 0) {
        printf(1, "Error forking child.\n");
    }

    else if (pid == 0) {
        int pid1 = fork();
        if(pid1 == 0){
            int pid1 = fork();
            if(pid1 == 0){
                semaphore_init(index, 1, 0);
                writer(1,&condvar);
                index++;
            }
            else{
                semaphore_init(index, 5, 0);
                index++;
                reader(2,&condvar);
                wait();
            }
        }
        else{
            semaphore_init(index, 5, 0);
            index++;
            reader(1,&condvar);
            wait();
        }
    }

    else {
        int pid1 = fork();

        if(pid1 == 0) {
            semaphore_init(index, 1, 0);
            index++;
            writer(0,&condvar);
        }

        else {
            semaphore_init(index, 5, 0);
            index++;
            reader(0,&condvar);
            wait();
        }

        wait();
    }

    exit();
    return 0;
}