/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwartell <cwartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:14:44 by cwartell          #+#    #+#             */
/*   Updated: 2017/12/06 22:08:40 by cwartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char	buffer;
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	if (fd < 0 || (read(fd, &buffer, 0) < 0))
		return (-1);
	// if (*line != NULL)
	// 	free(line[0]);
	tmp = (char*)malloc(sizeof(char) * 100000);
	while ((j = read(fd, &buffer, BUFF_SIZE)) > 0 && buffer != '\n')
	{
		i++;
		tmp[i - 1] = buffer;
	}
	*line = (char*)malloc(i * sizeof(char) + 1);
	ft_strcpy(*line, tmp);
	//free(tmp);
	if (j == -1)
		return (-1);
	if (j == 0 && i == 0)
		return (0);
	return (1);
}
