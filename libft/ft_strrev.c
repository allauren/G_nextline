/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrev.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/09/01 09:48:48 by allauren          #+#    #+#             */
/*   Updated: 2017/11/11 16:58:35 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

char	*ft_strrev(char *str)
{
	int		compteur;
	int		compteur2;
	char	temp;

	compteur = 0;
	compteur2 = 0;
	while (str[compteur] != '\0')
	{
		compteur++;
	}
	compteur = compteur - 1;
	while (compteur >= compteur2)
	{
		temp = str[compteur2];
		str[compteur2] = str[compteur];
		str[compteur] = temp;
		compteur--;
		compteur2++;
	}
	return (str);
}
