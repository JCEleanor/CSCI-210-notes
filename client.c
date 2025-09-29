
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>

struct request {
	char name[50]; // name of client FIFO
	int intervalLen;
};
struct response {
	int intervalStart;
};


int main(int argc, char **argv) {
	int server;
	int client;
	int len;
	if (argc!=2) {
		printf("Usage: ./client <clientname>\n");
		exit(1);
	}
	server = open("serverFIFO",O_WRONLY);

	printf("Make a request (enter -1 to end):");
	scanf("%d",&len);

	while (len!=-1) {
		struct request req;
		struct response r;
		strcpy(req.name,argv[1]);
		req.intervalLen = len;
		write(server,&req,sizeof(struct request));
		client = open(argv[1],O_RDONLY);
		read(client,&r,sizeof(struct response));
		printf("I got the integers: ");
		for (int i=r.intervalStart;i<r.intervalStart+len;i++) {
			printf("%d, ",i);
		}
		printf("\n");
		printf("Make a request (enter -1 to end):");
		scanf("%d",&len);
		close(client);
	}
	close(server);
	return 0;
}
