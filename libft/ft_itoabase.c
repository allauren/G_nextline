/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoabase.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 03:21:03 by allauren          #+#    #+#             */
/*   Updated: 2017/11/09 06:28:41 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	ft_recursive(char *str, long jack, int base, long i)
{
	if (jack < 0)
	{
		*str = '-';
		ft_recursive((str + 1), -jack, base, i);
		return ;
	}
	if (i >= base)
	{
		if ((jack / i) < 10)
			*str = jack / i + '0';
		else
			*str = jack / i - 10 + 'A';
		ft_recursive((str + 1), (jack % i), base, (i / base));
		return ;
	}
	if ((jack / i) < 10)
		*str = jack + '0';
	else
		*str = jack - 10 + 'A';
}

char		*ft_itoabase(int jack, int base)
{
	long	i;
	int		neg;
	char	*str;
	int		count;

	i = 1;
	neg = 0;
	count = 0;
	if (jack <= 0)
		neg = 1;
	while (i <= jack || (i * -neg) >= jack)
	{
		i = i * base;
		count++;
	}
	if (base < 2 || !(str = (char*)malloc(sizeof(char) * (count + neg + 1))))
		return (NULL);
	str[count + neg] = '\0';
	if (jack == 0)
	{
		str[0] = '0';
		return (str);
	}
	ft_recursive(str, jack, base, (i / base));
	return (str);
}
