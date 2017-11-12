/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/24 01:38:15 by allauren          #+#    #+#             */
/*   Updated: 2017/11/09 04:59:34 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	long	i;
	long	jack;
	int		neg;

	i = 0;
	jack = 0;
	neg = 1;
	while ((str[i] == '\n') || (str[i] == '\t') || (str[i] == '\v') ||
	(str[i] == ' ') || (str[i] == '\f') || (str[i] == '\r'))
		i++;
	if (str[i] == '-' || str[i] == '+')
		i++;
	if (str[i - 1] == '-')
		neg = -1;
	while (str[i] >= '0' && str[i] <= '9')
	{
		jack = jack * 10;
		jack = str[i] - '0' + jack;
		i++;
	}
	return ((int)(jack * neg));
}
