#include <stdio.h>

int main() {
	int n;
	int i,x;
	char bits[33];
	printf("Enter an integer:");
	scanf("%d",&n);

	x = 1;

	for (i=31;i>=0;i--) {
		if ((x & n) == 0) bits[i] = '0';
		else bits[i] = '1';
		x = x << 1;
	}
	bits[32] = 0;

	printf("The bits of %d is %s\n",n,bits);
	
}
