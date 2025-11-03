#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	char *str;
	char *nexttoken;
	str = (char *)malloc(sizeof(char) * 1000);
	strcpy(str, "/a/b/c/d/e/gg/hh/ii/hello");

	printf("Before Tokenization Str is : %s\n", str);

	nexttoken = strtok(str, "/");
	while (nexttoken != NULL)
	{
		printf("Token: %s\n", nexttoken);
		nexttoken = strtok(NULL, "/");
	}
	printf("Str is : %s\n", str);
	return 0;
}
