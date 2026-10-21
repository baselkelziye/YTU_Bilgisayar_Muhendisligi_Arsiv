#include <termios.h>
#include <stdio.h>
#include <unistd.h>

int getch(void) {
    int buf = 0;
    struct termios old = {0};

    fflush(stdout);

    if (tcgetattr(0, &old) < 0)
        perror("tcsetattr()");

    old.c_lflag &= ~(ICANON | ECHO);
    old.c_cc[VMIN] = 1;
    old.c_cc[VTIME] = 0;

    if (tcsetattr(0, TCSANOW, &old) < 0)
        perror("tcsetattr ICANON");

    if (read(0, &buf, sizeof(buf)) < 0)
        perror("read()");

    old.c_lflag |= ICANON | ECHO;

    if (tcsetattr(0, TCSADRAIN, &old) < 0)
        perror("tcsetattr ~ICANON");

    return buf;
}

int main() {
    int ch;
    printf("Press a key: ");
    ch = getch();
    printf("\nYou pressed: %d\n", ch);

    return 0;
}
