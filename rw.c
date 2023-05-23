#include "types.h"
#include "stat.h"
#include "user.h"

int main(int argc, char *argv[]){

    for (int i = 0 ; i < 5 ; i++){
        int a = fork();

        if (a < 0){
            while(wait() != -1){
            }
        }

        else if(a == 0) {
            if(i%2==0)
                make_write(getpid());
            exec();
            while(1) {}
        }
    }

    ps();
    exit();
}