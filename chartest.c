#include <stdio.h>

int main()
{
	unsigned char c;
	int i;
	c='A';
	for (i=0;i<300;i++) {
		printf("%d\n",c);
		printf("%c\n",c);
		c++;
	}
	return 0;
}
