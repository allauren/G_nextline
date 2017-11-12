/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/10 15:41:10 by allauren          #+#    #+#             */
/*   Updated: 2017/11/12 07:57:21 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
/*read, malloc et free*/
#include "libft/libft.h"
#include <stdio.h>
#include "get_next_line.h"
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <fcntl.h>

void	*ft_memlccpy(void *dest, void *src, int c, size_t count)
{
	size_t i;
	unsigned int	j, k;

	i = 0;
	j = 0;
	k = ft_strlen((char*)dest);
	while(((unsigned char*)dest)[j])
		j++;
	while (i < count)
	{
		if (((unsigned char*)src)[i] == ((unsigned char)c))
			return (&src[j + 1]);
		((unsigned char*)dest)[j] = ((unsigned char*)src)[i];
		i++;
		j++;
	}
	return (NULL);
}

void	ft_list_clear(t_list **begin_list)
{
	t_list*ptr;

	if (!begin_list)
		return ;
	while (*begin_list)
	{
		ptr = *begin_list;
		*begin_list = ptr->next;
		free(ptr);
	}
}

int		get_next_line(const int fd, char **line)
{
	int		ret;
	char	buf[BUF_SIZE + 1];
	unsigned int		count;
	t_list	*begin;
	static t_list	*rest = NULL;
	 char		*ptr;

	 if(fd < 0)
		 return (-1);
	t_list	*cpy;
	t_list	*prev;
	int		test;
	unsigned int		i;
	begin = NULL;
	count = 0;
	i = 0;
	ptr = NULL;
	ft_memset(buf, 0, BUF_SIZE + 1);	
	while((ret = read(fd, buf, BUF_SIZE)) > 0)
	{
		count++;
		buf[ret] = '\0';
		ft_lstadd(&begin,ft_lstnew(buf, ret + 1));
		if(ft_memchr(buf, '\n', ret))
		{
			ptr = ft_strdup(ft_strchr(buf, '\n') + 1); 
			break;
		}
	}
		if  (ret == -1)
			return (-1);
	//*line = ft_memalloc((count - 1) * BUF_SIZE + BUF_SIZE - ft_strlen(ptr) + 10);
	*line = ft_memalloc(100000);
	/*if (m != 0)
	{
	
	}*/
		if(rest)
		{
			ft_memlccpy(*line, rest->content, '\n', ft_strlen(rest->content) + 1);
			if(ft_strchr(rest->content, '\n') )
				ptr = ft_strdup(ft_strchr(rest->content, '\n') + 1); 
		free(rest->content);
		free(rest);
		rest = NULL;
		}
		if (ptr)
		ft_lstadd(&rest, ft_lstnew(ptr, ft_strlen(ptr) + 1));
	while(i < count)
	{
		cpy = begin;
		test = 0;
		prev = NULL;
		while(cpy && cpy->next)
		{
			prev = cpy;
			cpy = cpy->next;
		}
		ft_memlccpy(*line, cpy->content, '\n', ft_strlen(cpy->content) + 1);
		free(cpy->content);
		free(cpy);
		if (prev)
			prev->next = NULL;
		cpy = NULL;
		i++;
	}
	return (count > 0 || rest);
}

/*

int main(int argc,  char *argv[])
{
	(void)argc;
	int		fd;
	int		i;
	i = 0;
	if((fd = open(argv[1], O_RDWR)) < 0)
		return(1);
	while(get_next_line(fd, &argv[1]))
	printf("\nsortie 1 de gnl #%s#\n\n", argv[1]);
	return 0;
}*/
/*		while (cpy)
		{
			test++;
			ft_putstr(cpy->content);
			cpy = cpy->next;
		}
		ft_putchar('\n');
		ft_putnbr(test);*/
/*
   ivoidft_putstr(char *str)
   {
   int i;

   i = 0;
   while (str[i])
   {
   write(1, &str[i], 1);
   i++;
   }
   }

   intmain(int argc, char *argv[]		)
   {
   intfd;
   charbuf[BUF_SIZE + 1];
   intret;

   if (argc == 2)
   {
   if ((fd = open(argv[1], O_RDONLY)) < 0)
   return (0);
   while ((ret = read(fd, buf, BUF_SIZE)) > 0)
   {
   buf[ret] = '\0';
   ft_putstr(buf);
   }
   }
   else if (argc > 2)
   write(2, "Too many arguments.\n", 20);
   else
   write(2, "File name missing.\n", 19);
   return (0);
   }*/
