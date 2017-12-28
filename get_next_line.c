/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwartell <cwartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:14:44 by cwartell          #+#    #+#             */
/*   Updated: 2017/12/27 19:14:23 by cwartell         ###   ########.fr       */
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

// #include "get_next_line.h"
//
// int		get_next_line(const int fd, char **line)
// {
// 	t_line *head;
// 	int		j;
// 	char	*tmp;
// 	int		newline;
//
//
// 	printf("passcheck first\n");
// 	tmp = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
// 	if (fd < 0 || (read(fd, tmp, 0) < 0))
// 		return (-1);
// 	// 	free(head);
// 	if (head != NULL)
// 	{
// 		head = (t_line*)malloc(sizeof(*head));
// 		printf("i created a new structure!\n");
// 	}
// 	newline = 0;
// 	while ((j = read(fd, tmp, BUFF_SIZE)) > 0 && (!newline))
// 	{
// 		save2_struct(tmp, &head);
// 		if (check_line(tmp))
// 			newline = 1;
// 		memset(tmp, '\0', BUFF_SIZE);
// 		//printf("main:line in struct %s\n and 2nd struct %s\n", (*head)->currentline, (*head)->next->currentline);
// 		//tmp = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
// 		//printf("is tmp really gone? %s\n", tmp);
// 	}
// 	save2_line(head, *line);
// 	return(j == -1 ? -1 : j == 0 ? 0 : 1);
// }
//
// void	save2_struct(char *tmp, t_line **head)
// {
// 	t_line *newlist;
// 	t_line *current;
//
// 	current = *head;
// 	if (current->currentline == NULL)
// 	{
// 		current->currentline = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
// 		strcpy(current->currentline, tmp);
// 		printf("2:line in struct %s and tmp %s\n", current->currentline, tmp);
// 		//newlist = (t_line*)malloc(sizeof(*head));
// 		//newlist->next = NULL;
// 		current->next = NULL;
// 		//head->next = (t_line*)malloc(sizeof(*head));
// 		//head->next = headnext;
// 		return ;
// 	}
// 	while(current->next != NULL)
// 	{
// 		current = current->next;
// 		printf("i jumped\n");
// 	}
// 	//headnext = (t_line*)malloc(sizeof(*head));
// 	newlist = (t_line*)malloc(sizeof(current));
// 	newlist->currentline = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
// 	strcpy(newlist->currentline, tmp);
// 	newlist->next = NULL;
// 	current->next = newlist;
// 	//head->next = headnext;
// 	//headnext->currentline = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
// 	printf("3:line in struct %s and tmp %s\n", newlist->currentline, tmp);
// 	printf("test: are the structs aligned? 1:%s 2:%s\n", (*head)->currentline, (*head)->next->currentline);
// }
//
// int		check_line(char *tmp)
// {
// 	int a;
//
// 	a = 0;
// 	while (tmp[a] != '\0')
// 	{
// 		if (tmp[a] == '\n')
// 			return 1;
// 		a++;
// 	}
// 	return 0;
// }
//
// void	save2_line(t_line *head, char *ret)
// {
// 	int struct_count;
// 	int a;
// 	int b;
// 	//t_line *current;
//
// 	printf("still alive! %s --- %s\n", head->currentline, head->next->currentline);
// 	a = 0;
// 	//current = *head;
// 	struct_count = count_list(head);
// 	printf("whats killing me!!!");
// 	printf("struct_count is: %d\n", struct_count);
// 	ret = (char*)malloc(sizeof(char) * (BUFF_SIZE * struct_count));
// 	while (struct_count > 0)
// 	{
// 		printf("pass check real quick and the struct line %s\n", head->currentline);
// 		b = 0;
// 		while (b < BUFF_SIZE)
// 		{
// 			if (head->currentline[b] == '\n')
// 				return ;
// 			ret[a] = head->currentline[b];
// 			printf("4:return line in struct %s %d\n", ret, b);
// 			a++;
// 			b++;
// 		}
// 		head = head->next;
// 		struct_count--;
// 	}
// }
//
// int		count_list(t_line *head)
// {
// 	int i;
//
// 	i = 1;
// 	if (head->next == NULL)
// 	{
// 		printf("i returned fail->0\n");
// 		return i;
// 	}
// 	while (head->next != NULL)
// 	{
// 		head = head->next;
// 		i++;
// 	}
// 	printf("i returned %d\n", i);
// 	return i;
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwartell <cwartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:14:44 by cwartell          #+#    #+#             */
/*   Updated: 2017/12/17 18:39:48 by cwartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
//
// int		get_next_line(const int fd, char **line)
// {
// 	static	t_line *head;
// 	int		j;
// 	char	*tmp;
// 	int		newline;
//
//
// 	printf("passcheck first\n");
// 	tmp = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
// 	if (fd < 0 || (read(fd, tmp, 0) < 0))
// 		return (-1);
// 	if (head == NULL)
// 	{
// 		head = (t_line*)malloc(sizeof(head));
// 		printf("i created a new structure!\n");
// 		head->currentline = NULL;
// 		head->next = NULL;
// 	}
// 	else
// 	{
// 		printf("the stored line is:%s", head->currentline);
// 	}
// 	//head = (t_line)malloc(sizeof(head));
// 	newline = 0;
// 	while ((j = read(fd, tmp, BUFF_SIZE)) > 0 && (!newline))
// 	{
// 		printf("i read a line!\n");
// 		save2_struct(tmp, head);
// 		if (check_line(tmp))
// 			newline = 1;
// 		memset(tmp, '\0', BUFF_SIZE);
// 		//printf("main:line in struct %s\n and 2nd struct %s\n", (*head)->currentline, (*head)->next->currentline);
// 		//tmp = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
// 		//printf("is tmp really gone? %s\n", tmp);
// 	}
// 	save2_line(head, line);
// 	return(j == -1 ? -1 : j == 0 ? 0 : 1);
// }
//
//
// void	save2_struct(char *tmp, t_line *head)
// {
// 	t_line *newlist;
// 	t_line *current;
//
// 	current = head;
// 	if (current->currentline == NULL)
// 	{
// 		current->currentline = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
// 		strcpy(current->currentline, tmp);
// 		printf("2:line in struct %s and tmp %s\n", current->currentline, tmp);
// 		//newlist = (t_line*)malloc(sizeof(*head));
// 		//newlist->next = NULL;
// 		current->next = NULL;
// 		//head->next = (t_line*)malloc(sizeof(*head));
// 		//head->next = headnext;
// 		return ;
// 	}
// 	while(current->next != NULL)
// 	{
// 		current = current->next;
// 		printf("i jumped\n");
// 	}
// 	//headnext = (t_line*)malloc(sizeof(*head));
// 	newlist = (t_line*)malloc(sizeof(current));
// 	newlist->currentline = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
// 	strcpy(newlist->currentline, tmp);
// 	newlist->next = NULL;
// 	current->next = newlist;
// 	//head->next = headnext;
// 	//headnext->currentline = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
// 	printf("3:line in struct %s and tmp %s\n", newlist->currentline, tmp);
// 	printf("test: are the structs aligned? 1:%s 2:%s\n", head->currentline, head->next->currentline);
// }
//
// int		check_line(char *tmp)
// {
// 	int a;
//
// 	a = 0;
// 	while (tmp[a] != '\0')
// 	{
// 		if (tmp[a] == '\n')
// 			return 1;
// 		a++;
// 	}
// 	return 0;
// }
//
// void	save2_line(t_line *head, char **ret)
// {
// 	int		struct_count;
// 	int		a;
// 	int		b;
// 	char	*reset;
// 	char	replace[BUFF_SIZE];
// 	//t_line *current;
//
// 	printf("Rdone printThis-> %s --- %s\n", head->currentline, head->next->currentline);
// 	a = 0;
// 	//current = *head;
// 	struct_count = count_list(head);
// 	//printf("whats killing me!!!\n");
// 	printf("struct_count is: %d\n", struct_count);
// 	*ret = (char*)malloc(sizeof(char) * (BUFF_SIZE * struct_count));
// 	while (struct_count > 0)
// 	{
// 		printf("pass check real quick and the struct line %s\n", head->currentline);
// 		b = 0;
// 		while (b < BUFF_SIZE)
// 		{
// 			if (head->currentline[b] == '\n')
// 			{
// 				reset = &(head->currentline[b + 1]);
// 				strcpy(replace, reset);
// 				free(head->currentline);
// 				head->currentline = replace;
// 				printf("replaced string:%s\n", head->currentline);
// 				return ;
// 			}
// 			ret[0][a] = head->currentline[b];
// 			printf("4:return line is:%s %d\n", *ret, b);
// 			a++;
// 			b++;
// 		}
// 		pop(&head);
// 		//head = head->next;
// 		struct_count--;
// 	}
// }
//
// void	pop(t_line **head)
// {
// 	t_line *tmp;
//
// 	tmp = (t_line*)malloc(sizeof(tmp));
// 	tmp = tmp->next;
// 	free(*head);
// 	*head = tmp;
// }
// int		count_list(t_line *head)
// {
// 	int i;
//
// 	i = 1;
// 	if (head->next == NULL)
// 	{
// 		printf("i returned fail->0\n");
// 		return i;
// 	}
// 	while (head->next != NULL)
// 	{
// 		head = head->next;
// 		i++;
// 	}
// 	printf("i returned %d\n", i);
// 	return i;
// }
/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwartell <cwartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:14:44 by cwartell          #+#    #+#             */
/*   Updated: 2017/12/17 21:52:24 by cwartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "get_next_line.h"
//
// int		get_next_line(const int fd, char **line)
// {
// 	char	*reed;
// 	int		j;
// 	char	*buffer;
// 	int		size;
// 	//int		saved;
//
// 	reed = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
// 	if (fd < 0 || (read(fd, reed, 0) < 0))
// 		return (-1);
// 	while ((j = read(fd, reed, BUFF_SIZE)) > 0)
// 	{
// 		if (buffer != NULL)
// 		{
// 			printf("buf B4 realloc :%s [read]%s\n", buffer, reed);
// 			size++;
// 			buffer = re_alloc(reed, buffer, size);
// 		}
// 		else
// 		{
// 			buffer = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
// 			strcpy(buffer, reed);
// 			printf("this never happens huh?\n\n\n");
// 		}
// 		printf("the buffer :%s\n", buffer);
// 		size++;
// 		if (strchr(reed, '\n') != NULL)
// 		{
// 			printf("i found a nl\n");
// 			break;
// 		}
// 	}
// 	buffer = save2_line(buffer, line, size);
// 	printf("buff---->[%s]\n", buffer);
// 	return (j == -1 ? -1 : j == 0 ? 0 : 1);
// }
//
// char	*re_alloc(char *read, char *update, int size)
// {
// 	char *tmp;
// 	//char *ret;
//
// 	tmp = (char*)malloc(sizeof(char) * strlen(update) + 1);
// 	strcpy(tmp, update);
// 	//free(update);
// 	//ret = (char*)malloc(sizeof(char) * (size * BUFF_SIZE) + 1);
// 	strcpy(update, tmp);
// 	strcat(update, read);
// 	printf("%d>did i realloc? buffer after nl:{%s}--{%s} [read][%s]\n", size, update, tmp, read);
// 	return (update);
// }
//
// char	*save2_line(char *buffer, char **line, int size)
// {
// 	int		a;
// 	char	*p;
// 	//size_t	len;
//
// 	a = 0;
// 	*line = (char*)malloc(sizeof(char) * (BUFF_SIZE * size) + 1);
// 	p = (char*)malloc(sizeof(char) * (BUFF_SIZE * size) + 1);
// 	while (buffer[a] && buffer[a] != '\n')
// 	{
// 		line[0][a] = buffer[a];
// 		a++;
// 	}
// 	p = strchr(buffer, '\n') + 1;
// 	p[BUFF_SIZE] = '\0';
//
// 	printf("did i find the newline? {%s}\n", p);
// 	return (p);
	// if (buffer[0][a] == '\n')
	// {
	// 	p = &(buffer[0][a + 1]);
	// 	free(buffer[0]);
	// 	buffer[0] = p;
	// 	printf("where is p? [%s]\n", p);
	// }
}
// int		check_nl(char *check)
// {
// 	int a;
//
// 	if (check == NULL)
// 		return 1;
// 	if (strchr(check, '\n') != NULL)
// 		return 0;
// 	else
// 		return 1;
// }

/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cwartell <cwartell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/27 19:14:44 by cwartell          #+#    #+#             */
/*   Updated: 2017/12/27 19:12:00 by cwartell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(const int fd, char **line)
{
	char		reed[BUFF_SIZE + 1];
	int			j;
	static char	*buffer;
	static char	*save;

	if (fd < 0 || (read(fd, reed, 0) < 0))
		return (-1);
	bzero(reed, BUFF_SIZE + 1);
	while ((j = read(fd, reed, BUFF_SIZE)) > 0)
	{
		if (buffer != NULL)
		{
			save = buffer;
			buffer = ft_strjoin(buffer, reed, fd, save);
		}
		else
		{
			buffer = (char*)malloc(sizeof(char) * BUFF_SIZE + 1);
			memmove(buffer, reed, BUFF_SIZE + 1);
			buffer[BUFF_SIZE] = '\0';
		}
		if (strchr(reed, '\n') != NULL)
			break ;
		save = buffer;
	}
	if ((j > 0 || buffer != NULL) && buffer[0] != '\0')
	{
		save = buffer;
		buffer = save2_line(buffer, line, j, save);
		return (1);
	}
	return (j != 0 ? -1 : 0);
}

char	*ft_strjoin(char const *s1, char const *s2, int fd, char *save)
{
	size_t	st;
	size_t	end;
	char	*p;

	if (!s1 || !s2)
		return (NULL);
	st = strlen(s1);
	end = strlen(s2);
	if (!(p = (char*)malloc(sizeof(*p) * (st + end + 1))))
		return (NULL);
	memmove(p, s1, st);
	memmove(p + st, s2, end);
	p[st + end + 1] = '\0';
	if (fd != 0)
	{
		free(save);
		save = p;
	}
	return (p);
}

char	*save2_line(char *buffer, char **line, int j, char *save)
{
	int		a;
	char	*new;

	a = 0;

	while (buffer[a] != '\n' && buffer[a] != '\0')
	a++;
	if ((buffer[a] == '\0' || j == 0) && buffer[a + 1] == '\0')
	{
		line[0] = (char*)malloc(sizeof(char) * a + 1);
		memmove(line[0], buffer, a);
		line[0][a] = '\0';
		bzero((void*)buffer, a + 1);
		return (NULL);
	}
	else
	{
		line[0] = (char*)malloc(sizeof(char) * a + 1);
		memmove(line[0], buffer, a);
		line[0][a] = '\0';
		new = (char*)malloc(sizeof(char) * (strlen(buffer) - a) + 1);
		memmove(new, buffer + a + 1, strlen(buffer) - a);
		bzero((void*)buffer, a + 1);
		free(save);
		return (new);
	}
}

void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*p;

	p = (char *)s;
	i = 0;
	while (i < n)
		*(p + i++) = 0;
}
