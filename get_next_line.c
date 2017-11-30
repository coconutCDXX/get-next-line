/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwartell <cwartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:14:44 by cwartell          #+#    #+#             */
/*   Updated: 2017/11/29 23:42:49 by cwartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
//#include "libft/libft.h"

int		get_next_line(const int fd, char **line)
{
	char buffer;
	char	*tmp;
	int i;
	int j;

	i = 0;
	//printf("here we go again\n");
	// if (**line != '\0')
	// 	free(*line);
	*line = (char*)malloc(1 * sizeof(char) + 1);
	tmp = (char*)malloc(sizeof(char) * BUFF_SIZE);
	while ((j = read(fd, &buffer, 1)) > 0 && buffer != '\n')
	{
		i++;
		*line = (char*)malloc(i * sizeof(char) + 1);
		tmp[i - 1] = buffer;
		strcpy(*line, tmp);
	}
	if (i == 0)
		return 0;
	if (j == -1)
		return -1;
	return (1);
}
