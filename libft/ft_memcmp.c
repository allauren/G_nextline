/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 21:22:51 by allauren          #+#    #+#             */
/*   Updated: 2017/11/09 17:49:15 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *ptr1, const void *ptr2, size_t num)
{
	unsigned int	i;

	i = 0;
	while (i < num)
	{
		if (((unsigned char*)ptr1)[i] != ((unsigned char*)ptr2)[i])
			return (((unsigned char*)ptr1)[i] - ((unsigned char*)ptr2)[i]);
		i++;
	}
	return (0);
}
