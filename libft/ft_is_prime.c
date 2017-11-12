/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_prime.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 11:21:14 by allauren          #+#    #+#             */
/*   Updated: 2017/11/09 08:11:52 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

static int	ft_recur(int nb, int compteur)
{
	if ((nb % compteur) == 0)
		return (0);
	if (nb == compteur || compteur >= nb / compteur)
		return (1);
	return (ft_recur(nb, compteur + 1));
}

int			ft_is_prime(int nb)
{
	if (nb > 2 && nb % 2 != 0)
		return (ft_recur(nb, 2));
	if (nb == 2)
		return (1);
	return (0);
}
