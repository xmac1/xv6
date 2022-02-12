#include "user/user.h"
#include "kernel/types.h"


int
main(int argc, char *argv[])
{   int id = 2;
    int channel[2];
    pipe(channel);
    for (int i = 2; i <= 32; i++) {
        if (i <= 2) {
            printf("prime: %d\n", i);
        } else {
            int pid = fork();
            if (pid > 0) {
                write(channel[1], &i, sizeof i);
            } else {
                int num;
                int n = read(channel[0], &num, sizeof num);
                
            }
        }
    }
}