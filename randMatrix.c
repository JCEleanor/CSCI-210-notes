#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(int argc, char** argv) {
	int N;
	if (argc!=2) {
		printf("Usage: ./randMatrix N\n");
		exit(1);
	}
	sscanf(argv[1],"%d",&N);
	printf("%d\n",N);
	srand(time(NULL));
	for (int i=0;i<N;i++) {
		for (int j=0;j<N-1;j++) {
			printf("%d ",rand()%100>85?1:0);
		}
		printf("%d\n",rand()%100>85?1:0);
	}
	return 0;
}
