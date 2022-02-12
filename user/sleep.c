#include "kernel/types.h"
#include "user/user.h"

int main(int argc, char *argv[])
{
    if (argc != 2) {
        fprintf(2, "Usage: sleep <integer>\n");
        exit(1);
    }

    char* arg = argv[1];
    int sec = atoi(arg);
    int ret = sleep(sec);
    exit(ret);
}