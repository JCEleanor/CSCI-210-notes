#include <stdio.h>
#include <unistd.h>

int main()
{
	int cid;
	int pipe_fds[2];

	char message[50] = {};

	pipe(pipe_fds);

	// pipe_fds[0]  read end of the pipe
	// pipe_fds[1]  write end of the pipe

	cid = fork();
	if (cid == 0)
	{
		write(pipe_fds[1], "Hello from child.", 7);
	}
	else
	{
		read(pipe_fds[0], message, 7);
		printf("Message from child is: %s\n", message);
	}

	// write(pipe_fds[1],"Hello.",7);
	// read(pipe_fds[0],message,7);
	// printf("Message is: %s\n",message);

	return 0;
}
