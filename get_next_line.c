/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwartell <cwartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:14:44 by cwartell          #+#    #+#             */
/*   Updated: 2017/12/15 15:48:00 by cwartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
//
// int		get_next_line(const int fd, char **line)
// {
// 	char	buffer;
// 	char	*tmp;
// 	int		i;
// 	int		j;
//
// 	i = 0;
// 	if (fd < 0 || (read(fd, &buffer, 0) < 0))
// 		return (-1);
// 	// if (*line != NULL)
// 	// 	free(line[0]);
// 	tmp = (char*)malloc(sizeof(char) * 100000);
// 	while ((j = read(fd, &buffer, BUFF_SIZE)) > 0 && buffer != '\n')
// 	{
// 		i++;
// 		tmp[i - 1] = buffer;
// 	}
// 	*line = (char*)malloc(i * sizeof(char) + 1);
// 	ft_strcpy(*line, tmp);
// 	//free(tmp);
// 	if (j == -1)
// 		return (-1);
// 	if (j == 0 && i == 0)
// 		return (0);
// 	return (1);
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwartell <cwartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:14:44 by cwartell          #+#    #+#             */
/*   Updated: 2017/12/13 23:41:24 by cwartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	t_line *head;
	int		j;
	char	*tmp;
	int		newline;


	printf("passcheck first\n");
	tmp = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	if (fd < 0 || (read(fd, tmp, 0) < 0))
		return (-1);
	// 	free(head);
	if (head != NULL)
	{
		head = (t_line*)malloc(sizeof(*head));
		printf("i created a new structure!\n");
	}
	newline = 0;
	while ((j = read(fd, tmp, BUFF_SIZE)) > 0 && (!newline))
	{
		save2_struct(tmp, &head);
		if (check_line(tmp))
			newline = 1;
		memset(tmp, '\0', BUFF_SIZE);
		//printf("main:line in struct %s\n and 2nd struct %s\n", (*head)->currentline, (*head)->next->currentline);
		//tmp = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
		//printf("is tmp really gone? %s\n", tmp);
	}
	save2_line(head, *line);
	return(j == -1 ? -1 : j == 0 ? 0 : 1);
}

void	save2_struct(char *tmp, t_line **head)
{
	t_line *newlist;
	t_line *current;

	current = *head;
	if (current->currentline == NULL)
	{
		current->currentline = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
		strcpy(current->currentline, tmp);
		printf("2:line in struct %s and tmp %s\n", current->currentline, tmp);
		//newlist = (t_line*)malloc(sizeof(*head));
		//newlist->next = NULL;
		current->next = NULL;
		//head->next = (t_line*)malloc(sizeof(*head));
		//head->next = headnext;
		return ;
	}
	while(current->next != NULL)
	{
		current = current->next;
		printf("i jumped\n");
	}
	//headnext = (t_line*)malloc(sizeof(*head));
	newlist = (t_line*)malloc(sizeof(current));
	newlist->currentline = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	strcpy(newlist->currentline, tmp);
	newlist->next = NULL;
	current->next = newlist;
	//head->next = headnext;
	//headnext->currentline = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
	printf("3:line in struct %s and tmp %s\n", newlist->currentline, tmp);
	printf("test: are the structs aligned? 1:%s 2:%s\n", (*head)->currentline, (*head)->next->currentline);
}

int		check_line(char *tmp)
{
	int a;

	a = 0;
	while (tmp[a] != '\0')
	{
		if (tmp[a] == '\n')
			return 1;
		a++;
	}
	return 0;
}

void	save2_line(t_line *head, char *ret)
{
	int struct_count;
	int a;
	int b;
	//t_line *current;

	printf("still alive! %s --- %s\n", head->currentline, head->next->currentline);
	a = 0;
	//current = *head;
	struct_count = count_list(head);
	printf("whats killing me!!!");
	printf("struct_count is: %d\n", struct_count);
	ret = (char*)malloc(sizeof(char) * (BUFF_SIZE * struct_count));
	while (struct_count > 0)
	{
		printf("pass check real quick and the struct line %s\n", head->currentline);
		b = 0;
		while (b < BUFF_SIZE)
		{
			if (head->currentline[b] == '\n')
				return ;
			ret[a] = head->currentline[b];
			printf("4:return line in struct %s %d\n", ret, b);
			a++;
			b++;
		}
		head = head->next;
		struct_count--;
	}
}

int		count_list(t_line *head)
{
	int i;

	i = 1;
	if (head->next == NULL)
	{
		printf("i returned fail->0\n");
		return i;
	}
	while (head->next != NULL)
	{
		head = head->next;
		i++;
	}
	printf("i returned %d\n", i);
	return i;
}
