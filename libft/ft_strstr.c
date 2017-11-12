/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 00:14:38 by allauren          #+#    #+#             */
/*   Updated: 2017/11/09 05:13:22 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *str1, const char *str2)
{
	int i;
	int j;

	j = 0;
	i = 0;
	if (!str2[i])
		return ((char*)str1);
	while (str1[i])
	{
		if (!str2 || str1[i] == str2[j])
		{
			while (str2[j] && str1[i + j] == str2[j])
				j++;
			if (str2[j])
				j = 0;
			else
				return ((char*)&str1[i]);
		}
		i++;
	}
	return (NULL);
}
