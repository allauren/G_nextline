/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 00:38:39 by allauren          #+#    #+#             */
/*   Updated: 2017/11/09 03:40:19 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strncmp(const char *s1, const char *s2, size_t num)
{
	unsigned int	i;

	i = 0;
	if (!num)
		return (0);
	while (s1[i] && s2[i] && s1[i] == s2[i] && i < (num - 1))
		i++;
	return (((unsigned char)s1[i]) - ((unsigned char)s2[i]));
}
