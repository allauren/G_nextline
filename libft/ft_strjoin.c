/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 00:50:13 by allauren          #+#    #+#             */
/*   Updated: 2017/11/09 03:57:31 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	unsigned int	size;
	unsigned int	i;
	unsigned int	j;
	char			*str;

	i = 0;
	j = 0;
	size = 0;
	if (s1 && s2)
		size = ft_strlen(s1) + ft_strlen(s2);
	if (!s1 || !s2 || !(str = (char*)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	while (s1[i])
	{
		str[i] = s1[i];
		i++;
	}
	while (s2[j])
	{
		str[i] = s2[j];
		i++;
		j++;
	}
	str[i] = '\0';
	return (str);
}
