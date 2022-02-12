#include "sys/types.h"
#include "user/user.h"

int
main(int argc, char *argv[]) 
{
    int p2c[2], c2p[2];
    pipe(p2c);
    pipe(c2p);
    int pid = fork();
    if (pid > 0) {
        char buf[512];
        char msg[] = "\n";
        int n;
        n = write(p2c[1], msg, sizeof msg);
        if (n <= 0) {
            printf("write failed, code: %d\n", n);
            exit(n);
        }
        memset(buf, 0, sizeof buf);
        n = read(c2p[0], buf, sizeof buf);
        printf("%d: received pong\n", getpid());
        exit(0);
    } else if (pid == 0) {
        char buf[16];
        char msg[] =  "\n";
        read(p2c[0], buf, sizeof buf);
        pid = getpid();
        printf("%d: received ping\n", pid);
        write(c2p[1], msg, sizeof msg);
        exit(0);
    }
    return 0;
}