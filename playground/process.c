#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    int status;
    pid_t cpid;

    cpid = fork();
    if (cpid == 0)
    {
        // execlp("ls", "ls", "-al", (char *)0);
        execl("ls", "ls", "-al", (char *)0);
    }
    else if (cpid < 0)
    {
        printf("Fork failed\n");
        exit(1);
    }
    else
    {
        // wait(&status);
        waitpid(cpid, &status, 0);
    }
}