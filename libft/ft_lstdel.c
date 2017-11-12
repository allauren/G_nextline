/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 22:27:19 by allauren          #+#    #+#             */
/*   Updated: 2017/11/06 23:05:39 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list	*temp;

	if (alst && *alst)
	{
		while (*alst)
		{
			temp = *alst;
			(*del)((*alst)->content, (*alst)->content_size);
			*alst = (*alst)->next;
			free(temp);
		}
	}
	alst = NULL;
}
