/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: allauren <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/25 01:41:32 by allauren          #+#    #+#             */
/*   Updated: 2017/11/09 03:57:42 by allauren         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	unsigned int		i;
	unsigned int		begin[2];
	char				*str;

	i = 0;
	while (s && (s[i] == ' ' || s[i] == '\n' || s[i] == '\t'))
		i++;
	begin[0] = i;
	begin[1] = i;
	while (s && s[i])
	{
		if (s[i] != ' ' && s[i] != '\n' && s[i] != '\t')
			begin[1] = i + 1;
		i++;
	}
	if (!s || !(str = (char*)malloc(sizeof(char) * (begin[1] - begin[0] + 1))))
		return (NULL);
	i = 0;
	while (i < (begin[1] - begin[0]))
	{
		str[i] = s[begin[0] + i];
		i++;
	}
	str[i] = '\0';
	return (str);
}
