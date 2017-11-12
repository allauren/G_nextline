/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/09 21:40:27 by allauren          #+#    #+#             */
/*   Updated: 2017/11/09 03:54:42 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t num)
{
	unsigned char *d;
	unsigned char *s;

	d = (unsigned char*)dst;
	s = (unsigned char*)src;
	if (!num)
		return (dst);
	if (dst <= src)
		return (ft_memcpy(dst, src, num));
	while (num--)
		d[num] = s[num];
	return (dst);
}
