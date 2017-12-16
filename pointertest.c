#include <stdio.h>
#include <stdlib.h>

void	change(char **test);

int main()
{
	//char *test;
	char **p;


	//p = &test;
	change(p);
	printf("did i change? %s\n ", *p);
	return 0;
}

void 	change(char **test)
{
	*test = (char*)malloc(sizeof(char) * 13 + 1);
	test[0][0] = 'd';
	test[0][1] = 'a';
	test[0][2]= 'd';
	test[0][3] = 'd';
	test[0][4] = 'y';
	test[0][5] = 'i';
	test[0][6] = 'a';
	test[0][7] = 'n';
	test[0][8] = '\0';
	printf("first try %s \n", *test);
}
