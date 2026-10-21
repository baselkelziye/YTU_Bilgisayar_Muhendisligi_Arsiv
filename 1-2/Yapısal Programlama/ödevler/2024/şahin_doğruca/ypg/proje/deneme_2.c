#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>


int main() {
    char cwd[PATH_MAX];
    if(getcwd(cwd, sizeof(cwd)) != NULL) {
        printf("%s", cwd);
    } else {
        perror("getcwd() error");
        return 1;
    }
    return 0;
}