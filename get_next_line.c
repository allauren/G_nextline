/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:41:10 by allauren          #+#    #+#             */
/*   Updated: 2017/11/14 06:28:00 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft/libft.h"
#include <stdio.h>
#include "get_next_line.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

int		ft_memlccpy(void *dest, void *src, int c, size_t count,t_decla s)
{
	size_t			i;
	unsigned int	j;
	unsigned int	k;

	i = 0;
	j = 0;
	k = ft_strlen((char*)dest);
	while (((unsigned char*)dest)[j])
		j++;
	while (i < count)
	{
		if (((unsigned char*)src)[i] == ((unsigned char)c))
			return (2);
			((unsigned char*)dest)[j] = ((unsigned char*)src)[i];
		i++;
		j++;
		s.endline = 1;
	}
	return (s.endline);
}

int		ft_reste(char **line, t_decla s, t_list **rest)
{
	int				x;

	x = 0;
	if(*rest)
	{
		s.endline = ft_memlccpy(*line, (*rest)->content, '\n', ft_strlen((*rest)->content) + 1, s);
		if (ft_strchr((*rest)->content, '\n') && ft_strlen((*rest)->content))
			s.ptr = ft_strdup(ft_strchr((*rest)->content, '\n') + 1);
		ft_memdel((void**)&(*rest)->content);
		ft_memdel((void**)&(*rest));
	}
	if (s.ptr && ft_strlen(s.ptr))
	{
		ft_lstadd(&(*rest), ft_lstnew(s.ptr, ft_strlen(s.ptr) + 1));
	
	}
	return (s.endline);
}

int		ft_list_copie(t_list *begin, t_list *cpy, char **line, t_decla sptr)
{
	t_list			*prev;

	sptr.i = 0;
	prev = NULL;
	if(sptr.endline == 2)
	sptr.endline = 0;
	while (sptr.cnt)
	{
		cpy = begin;
		prev = NULL;
		while (cpy && cpy->next)
		{
			prev = cpy;
			cpy = cpy->next;
		}
		sptr.endline = ft_memlccpy(*line, cpy->content, '\n', ft_strlen(cpy->content) + 1, sptr);
		free(cpy->content);
		free(cpy);
		if (prev)
			prev->next = NULL;
		cpy = NULL;
		sptr.cnt = sptr.cnt - 1;
	}
	return(sptr.endline);
}

int			get_next_line(const int fd, char **line)
{
	t_decla			s;
	unsigned int	mal;
	t_list static	*rest = NULL;
	mal = 0;
	ft_bzero(&s, sizeof(t_decla));
	if(rest && (ft_memchr(rest->content, '\n', ft_strlen(rest->content))))
		mal = 1;
	while (!mal && (s.rt = read(fd, s.buf, BUFF_SIZE)) > 0)
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
	if (fd < 0 || s.rt == -1)
		return (-1);
	if(!(*line = (char*)ft_memalloc(100000)))
		return(-1);
	s.endline = ft_reste(line, s, &rest);
	if(s.endline != 2)
		s.endline = ft_list_copie(s.begin, s.begin, line, s);
	return (s.endline > 0);
}
/*
int		main(int argc, char *argv[])
{
	int		fd;
	int		i;
	int		n;

	n = 0;
	i = 0;
	(void)argc;
	if ((fd = open(argv[1], O_RDWR)) < 0)
		return (1);
	
	
	while( (i = get_next_line(fd, &argv[1])))
	{
	printf("\nsortie %d de gnl #%s# la valeur de sortie est %d \n\n", n, argv[1], i);
	n++;
	}
		return (0);
}*/
