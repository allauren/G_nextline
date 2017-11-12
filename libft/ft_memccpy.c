/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/06 01:07:03 by allauren          #+#    #+#             */
/*   Updated: 2017/11/09 05:51:52 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t count)
{
	size_t	i;

	i = 0;
	while (i < count)
	{
		((unsigned char*)dest)[i] = ((unsigned char*)src)[i];
		if (((unsigned char*)src)[i] == ((unsigned char)c))
			return (&dest[i + 1]);
		i++;
	}
	return (NULL);
}
