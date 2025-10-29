#include <stdio.h>
#include <stdlib.h>

int main() {
	int rows;
	int i;
	int width;
	int ** a;

	scanf("%d",&rows);
	
	a = (int **)malloc(sizeof(int *)*rows);

	for (i=0;i<rows;i++) {
		scanf("%d",&width);
		a[i] = (int *)malloc(sizeof(int)*width);
	}

	a[3][5] = 15; // *((*(a+3))+5)

}
