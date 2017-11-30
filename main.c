#include "get_next_line.h"

int main ()
{
	int		fd;
	//int		return_val;
	char	*buff;
	int jte;

	//buff = (char**)malloc(5 * sizeof(char**) + 1);
	//*buff = (char*)malloc(25 * sizeof(char*) + 1);
	fd = open("walloftest.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("fd is %d", fd);
		return 1;
	}
	printf("size before malloc: %lu\n", strlen(buff));

	while ((jte = get_next_line(fd, &buff)) >= 0)
	{
		printf("3)LINE : %s\n     and size: %lu and return %d\n" ,buff, strlen(buff), jte);
		//free(buff);
		//printf("4)buff should be cleared : %s\n", buff);
		if (jte == 0)
			return 0;
	}
	return 0;
}
