/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rev_params.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/06 07:54:44 by allauren          #+#    #+#             */
/*   Updated: 2017/11/09 05:51:54 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_rev_params(int argc, char **argv)
{
	int		i;
	int		j;

	i = 0;
	j = 0;
	if (argc != 1)
	{
		while (i < argc)
			i++;
		while (i > 1)
		{
			i--;
			while (argv[i][j] != '\0')
			{
				ft_putchar(argv[i][j]);
				j++;
			}
			ft_putchar('\n');
			j = 0;
		}
	}
}
