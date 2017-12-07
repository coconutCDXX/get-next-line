#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "libft/libft.h"

# define BUFF_SIZE 1

int		get_next_line(int fd, char **line);

#endif
