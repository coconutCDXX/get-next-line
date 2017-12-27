/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwartell <cwartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 20:36:48 by cwartell          #+#    #+#             */
/*   Updated: 2017/12/17 19:21:35 by cwartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// int		get_next_line(int fd, char **line);
//
// #endif

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwartell <cwartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/06 20:36:48 by cwartell          #+#    #+#             */
/*   Updated: 2017/12/17 18:20:15 by cwartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include "libft/libft.h"

# define BUFF_SIZE 32

typedef struct		s_line
{
	char			*currentline;
	struct s_line	*next;
}					t_line;

int		get_next_line(int fd, char **line);
void	save2_struct(char *tmp, t_line *head);
int		check_line(char *tmp);
void	save2_line(t_line *head, char **ret);
int		count_list(t_line *head);
void	pop(t_line **head);

#endif
