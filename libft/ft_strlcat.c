/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 01:14:19 by allauren          #+#    #+#             */
/*   Updated: 2017/11/09 05:52:31 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	unsigned int i;
	unsigned int j;

	i = 0;
	j = 0;
	while (dst[i] && i < size)
		i++;
	if (size)
	{
		while (src[j] && i < size - 1)
		{
			dst[i] = src[j];
			j++;
			i++;
		}
	}
	if (j > 0)
	{
		dst[i] = '\0';
		return (i + ft_strlen(src) - j);
	}
	return (i + ft_strlen(src));
}
