#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <string.h>

#define MAX_LINE 256 /* 256 chars per line */

/* function declarations */
void print_welcome();
void print_help();
int change_dir(char*[]);
void setup(char[], char*[], int*);

pid_t pid;


int main(void)
{
    char inputBuffer[MAX_LINE]; /* buffer to hold the command entered */
    int background;             /* equals 1 if a command is followed by '&' */
    char *args[MAX_LINE/2+1];   /* command line (of 256) has max of 128 arguments */
    char current_dir[100]; 		/* current directory */

    /*Render a welcome page */
    print_welcome();

    while (1){
        background = 0;
        int child_status;

        /* Print shell prompt*/
        printf("%s@user: %s$ ", getenv("LOGNAME"), getcwd(current_dir, 100));
        fflush(0);

        /* handle input line */
        setup(inputBuffer, args, &background);  /* get next command */

        /* if input line empty re-prompt */
        if(inputBuffer[0] == '\n' || inputBuffer[0] == '\0') continue;


        /* check builtin commands first */
        if(strcmp(args[0], "cd" ) == 0){
            change_dir(args);
            continue;

        }else if(strcmp(args[0], "help" ) == 0){
            print_help();
            continue;

        }else if(strcmp(args[0], "exit" ) == 0){
            return 0;

        }else{
            if((pid = fork()) < 0){
                printf("E: Failed to create child process...\n");
                exit(1);
            }else if(pid == 0){ /* Child process */
                if((execvp(args[0], args)) < 0){
                    printf("E: Command :'%s' not found..\nPlease type 'help'.\n", args[0]);
                    exit(0);
                }
            }else{
                if(background == 0){ /* don't let child to run in background */
                    waitpid(pid, &child_status, 0);
                    // printf("Done: :[%i]\n", pid);
                }else{
                    /* -Child running in background- */
                }
            }
        }
    }
}


void setup(char inputBuffer[], char *args[], int *background)
{
    int length,     /* # of characters in the command line */
            i,      /* loop index for accessing inputBuffer array */
            start,  /* index where beginning of next command parameter is */
            ct;     /* index of where to place the next parameter into args[] */

    ct = 0;

    /* Clear input buffer */
    memset(inputBuffer,'\0',MAX_LINE);

    /* read what the user enters on the command line */
    length = read(STDIN_FILENO, inputBuffer, MAX_LINE);

    start = -1;
    if (length == 0)
        exit(0);  /* ^d was entered, end of user command stream */
    if (length < 0){
        perror("couldn't read the command");
        exit(-1);  /* terminate with error code*/
    }

    /*Empty line handled here to prevent 'segmentation error' while builtin command check*/
    if(inputBuffer[0] != '\n'){

        /* examine every character in the inputBuffer */
        for (i = 0; i < length; i++) {
            switch (inputBuffer[i]){
                case ' ':
                case '\t' :               /* argument separators */
                    if(start != -1){
                        args[ct] = &inputBuffer[start];    /* set up pointer */
                        ct++;
                    }
                    inputBuffer[i] = '\0'; /* add a null char; make a C string */
                    start = -1;
                    break;

                case '\n':                 /* should be the final char examined */
                    if (start != -1){
                        args[ct] = &inputBuffer[start];
                        ct++;
                    }
                    inputBuffer[i] = '\0';
                    args[ct] = NULL; /* no more arguments to this command */
                    break;

                case '&':
                    *background = 1;
                    inputBuffer[i] = '\0';
                    break;

                case '|':
                    /* Set pipe flag */
                    break;

                default :
                    if (start == -1)
                        start = i;
            }
        }
        args[ct] = NULL; /* just in case the input line was > 256 */
    }else{
        /* Handle empty line */
    }

}

/********************************************/
/***********BUILTIN COMMANDS*****************/

int change_dir(char* args[]){
    if (args[1] == NULL) {  /* Typing only 'cd' changes directory to home */
        chdir(getenv("HOME"));
        return 1;
    }else{
        if (chdir(args[1]) == -1) { /* Otherwise change directory to specified one */
            printf("%s: no such file or directory\n", args[1]);
            return -1;
        }
    }
    return 0;
}

void print_help(){
    printf("You can type any basic UNIX command with arguments and tap ENTER!\n");
    printf("Following builtin commands are also available:"
           "\n'cd' \n'exit' \n'help'\n");
}

void print_welcome(){
    system("clear");
    printf("\n\t====================================================\n\n");
    printf("\t           || A Basic Shell for UNIX ||    \n\n");
    printf("\t====================================================\n\n");
}

