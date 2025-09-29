#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <pthread.h>

int N;
char **A;
int **res;

void *mult(void *start) {
	int r = *((int *)start);
	fprintf(stderr,"I am now starting multiplying from row: %d\n",r);
	int s = r+100; // each thread multiplying 100 rows
	for (int i=r;i<s;i++) {
		for (int j=0;j<N;j++) {
			res[i][j] = 0;
			for (int k=0;k<N;k++) {
				res[i][j]+=A[i][k]*A[k][j];
			}
		}
	}
	pthread_exit((void *)0);
}

int main() {
	scanf("%d",&N);
	A = (char **)malloc(sizeof(char*)*N);
	res = (int **)malloc(sizeof(int*)*N);
	for (int i=0;i<N;i++) {
		A[i] = (char *)malloc(sizeof(char)*N);
		res[i] = (int *)malloc(sizeof(int)*N);
	}
	for (int i=0;i<N;i++) {
		for (int j=0;j<N;j++) {
			int tmp;
			scanf("%d",&tmp);
			A[i][j]=tmp;
		}
	}
	
	int numThreads = N/100;
	pthread_t tid[numThreads];
	int startArray[numThreads];
	for (int i=0;i<numThreads;i++)
		startArray[i]=i*100;

	for (int i=0;i<numThreads;i++) {
		pthread_create(tid+i,NULL,mult,(void *)(&(startArray[i])));
	}
	for (int i=0;i<numThreads;i++) {
		pthread_join(tid[i],NULL);
	}

	printf("%d\n",N);
	for (int i=0;i<N;i++) {
		for (int j=0;j<N;j++) {
			printf("%d ",res[i][j]);
		}
		printf("\n");
	}
	return 0;
}
