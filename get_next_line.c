/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:41:10 by allauren          #+#    #+#             */
/*   Updated: 2017/11/16 04:45:12 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include "get_next_line.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

static int		ft_cpy(void *dest, void *src, size_t count, t_decla s)
{
	size_t			i;
	unsigned int	j;
	unsigned int	k;
	unsigned char	c;

	i = 0;
	j = 0;
	c = '\n';
	k = LEN((char*)dest);
	while (((unsigned char*)dest)[j])
		j++;
	while (i < count)
	{
		if (((unsigned char*)src)[i] == ((unsigned char)c))
			return (2);
		((unsigned char*)dest)[j] = ((unsigned char*)src)[i];
		i++;
		j++;
		s.end = 1;
	}
	return (s.end);
}

int			ft_reste(char **line, t_decla s, t_list **rest)
{
	if (*rest && ((*rest)->content))
	{
		s.end = ft_cpy(*line, (*rest)->content, LEN((*rest)->content) + 1, s);
		if (ft_strchr((*rest)->content, '\n') && LEN((*rest)->content))
			s.ptr = ft_strdup(ft_strchr((*rest)->content, '\n') + 1);
		ft_memdel((void**)&(*rest)->content);
		ft_memdel((void**)&(*rest));
	}
	if (s.ptr && LEN(s.ptr))
	{
		ft_lstadd(&(*rest), ft_lstnew(s.ptr, LEN(s.ptr) + 1));
	}
	else
		free(s.ptr);
	return (s.end);
}

int			ft_list_copie(t_list *begin, t_list *cpy, char **line, t_decla s)
{
	t_list			*prev;

	s.i = 0;
	prev = NULL;
	while (s.cnt)
	{
		cpy = begin;
		prev = NULL;
		while (cpy && cpy->next)
		{
			prev = cpy;
			cpy = cpy->next;
		}
		s.end = ft_cpy(*line, cpy->content, LEN(cpy->content) + 1, s);
		free(cpy->content);
		free(cpy);
		if (prev)
			prev->next = NULL;
		cpy = NULL;
		s.cnt--;
	}
	return (s.end);
}

int			get_next_line(const int fd, char **line)
{
	t_decla			s;
	t_list static	*rest = NULL;

	ft_bzero(&s, sizeof(t_decla));
	if (rest && (ft_memchr(rest->content, '\n', LEN(rest->content))))
		s.mal = 1;
	while (!s.mal && (s.rt = read(fd, s.buf, BUFF_SIZE)) > 0)
	{
		s.cnt++;
		s.buf[s.rt] = '\0';
		ft_lstadd(&s.begin, ft_lstnew(s.buf, s.rt + 1));
		if (ft_memchr(s.buf, '\n', s.rt))
		{
			s.ptr = ft_strdup(ft_strchr(s.buf, '\n') + 1);
			break ;
		}
	}
	if (fd < 0 || s.rt == -1 || !(*line = (char*)ft_memalloc((s.cnt + 1) * BUFF_SIZE + 2)))
		return (-1);
	s.end = ft_reste(line, s, &rest);
	if (s.end != 2)
		s.end = ft_list_copie(s.begin, s.begin, line, s);
	return (s.end > 0);
}
/*
int main(int argc, char *argv[])
{
	(void)argc;
	int fd = open(argv[1], O_RDONLY);
	get_next_line(fd, &argv[1]);
	printf("je passe la et je vaut %s\n", argv[1]);
	get_next_line(fd, &argv[1]);
	printf("je passe la et je vaut %s\n", argv[1]);
	get_next_line(fd, &argv[1]);
	printf("je passe la et je vaut %s\n", argv[1]);
	get_next_line(fd, &argv[1]);
	printf("je passe la et je vaut %s\n", argv[1]);
	return 0;
}*/
