/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 02:41:22 by allauren          #+#    #+#             */
/*   Updated: 2017/11/08 14:21:02 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char			*cp;
	unsigned int	i;

	i = 0;
	if (!s || !(cp = (char*)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	while (i < len)
	{
		cp[i] = s[start + i];
		i++;
	}
	cp[len] = '\0';
	return (cp);
}
