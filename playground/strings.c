#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void change(char *str)
{
	str[2] = 'a';
}

int main()
{
	char s[10] = "Trip";
	change(s);
	printf("%s\n", s);
	return 0;

	char mystr1[] = "Hello World!"; // char mystr[] = {'H','e','l'.......'!','\0'}

	char mystr2[5] = "abcde"; // not enough space for null terminator

	char *mystr3;
	char *mystr4;
	int i;

	mystr3 = malloc(sizeof(char) * 100); // allocate memory for 100 characters

	// this line does not copy string correctly
	// mystr3 = mystr1; // another character pointer pointing to the same memory location

	// copy mystr1 to mystr3 character by character
	i = 0;
	while (mystr1[i] != '\0')
	{
		mystr3[i] = mystr1[i];
		i++;
	}

	mystr3[i] = '\0'; // add null terminator

	printf("mystr1 = %s\n", mystr1);
	printf("mystr1 = %s\n", mystr1 + 6); // pointer arithmetic
	printf("mystr2 = %s\n", mystr2);

	return 0;
}
