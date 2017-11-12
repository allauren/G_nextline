/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_find_next_prime.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/03 13:43:29 by allauren          #+#    #+#             */
/*   Updated: 2017/11/09 08:12:26 by allauren         ###   ########.fr       */
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

static int	ft_is_prime(int nb)
{
	if (nb > 2)
		return (ft_recur(nb, 2));
	if (nb == 2)
		return (1);
	return (0);
}

int			ft_find_next_prime(int nb)
{
	if (ft_is_prime(nb) == 1)
		return (nb);
	else
		return (ft_find_next_prime(nb + 1));
	return (0);
}
