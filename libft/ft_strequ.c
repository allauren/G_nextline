/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/11 02:27:01 by allauren          #+#    #+#             */
/*   Updated: 2017/11/09 06:15:25 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	unsigned int i;

	i = 0;
	if (!s1 || !s2 || ft_strlen(s1) != ft_strlen(s2))
		return (0);
	while (s1[i])
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	return (1);
}
