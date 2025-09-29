#include <stdio.h>
#include <stdlib.h>

int main() {
	char **A;
	int **res;
	int N;
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
	
	for (int i=0;i<N;i++) {
		for (int j=0;j<N;j++) {
			res[i][j] = 0;
			for (int k=0;k<N;k++) {
				res[i][j]+=A[i][k]*A[k][j];
			}
		}
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
