#include <fcntl.h>
#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <string.h>


int		get_next_line(const int fd, char **line);

int main ()
{
	int		fd;
	char	*buff;

	//buff = (char**)malloc(5 * sizeof(char**) + 1);
	//*buff = (char*)malloc(25 * sizeof(char*) + 1);
	fd = open("walloftest.txt", O_RDONLY);
	if (fd < 0)
	{
		printf("fd is %d", fd);
		return 1;
	}
	printf("size before malloc: %lu\n", strlen(buff));

	while (get_next_line(fd, &buff) != -1)
	{
		printf("3)LINE : %s\n and size: %lu\n" ,buff, strlen(buff));
		//free(buff);
		printf("4)buff should be cleared : %s\n", buff);

	}
	return 0;
}


int		get_next_line(const int fd, char **line)
{
	static char buffer;
	char	*tmp;
	int i;

	i = 0;
	if (**line != '\0')
		free(*line);
	//line = (char**)malloc(sizeof(char*));
	*line = (char*)malloc(1 * sizeof(char) + 1);
	tmp = (char*)malloc(sizeof(char) * 1000000);
	while (read(fd, &buffer, 1) != 0 && buffer != '\n')
	{
		free(line[0]);
		i++;
		//printf("buffer is %c\n", buffer);
		*line = (char*)malloc(i * sizeof(char) + 1);
		tmp[i - 1] = buffer;
		strcpy(*line, tmp);
	}

	free(tmp);
	printf("1)LINE : %s\n", *line);

	printf("2)value of i : %d\n", i);
	return (*line != NULL ? 1 : -1);
}
