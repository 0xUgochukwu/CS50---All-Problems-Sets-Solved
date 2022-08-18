#include <stdio.h>
#include <string.h>

int main()
{
	printf("Your name:\n");

	// return (0);

	char *name = NULL;

	scanf("%s", name);
    int count = strlen(name);



	printf("%i\n", count);

}