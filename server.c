
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <signal.h>

// NOTE: a better way is to put them in a shared header file
struct request
{
	char name[50]; // name of client FIFO
	int intervalLen;
};
struct response
{
	int intervalStart;
};

int main()
{
	int server;
	int client;
	int dummyfd;
	int curr = 0;
	struct request req;
	signal(SIGPIPE, SIG_IGN);
	server = open("serverFIFO", O_RDONLY);
	dummyfd = open("serverFIFO", O_WRONLY);

	while (1)
	{
		if (read(server, &req, sizeof(struct request)) != sizeof(struct request))
		{
			continue;
		}
		struct response r;
		printf("Received a request from client %s for %d integers\n", req.name, req.intervalLen);
		client = open(req.name, O_WRONLY);
		r.intervalStart = curr;
		curr += req.intervalLen;
		printf("Curr is now: %d\n", curr);
		write(client, &r, sizeof(struct response));
		close(client);
	}
	close(server);
	return 0;
}
