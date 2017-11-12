/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/11/06 22:48:20 by allauren          #+#    #+#             */
/*   Updated: 2017/11/10 02:06:25 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*flw;
	t_list	*tmp;
	t_list	*begin;

	tmp = f(lst);
	if (!lst || !f)
		return (NULL);
	if (!(flw = ft_lstnew(tmp->content, tmp->content_size)))
		return (NULL);
	begin = flw;
	lst = lst->next;
	while (lst)
	{
		tmp = f(lst);
		if (!(flw->next = ft_lstnew(tmp->content, tmp->content_size)))
			return (NULL);
		flw = flw->next;
		lst = lst->next;
	}
	return (begin);
}
