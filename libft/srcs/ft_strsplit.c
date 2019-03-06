/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollie <btollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/14 15:37:40 by btollie           #+#    #+#             */
/*   Updated: 2018/11/16 15:00:09 by btollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_strsplit(char const *s, char c)
{
	size_t	i;
	size_t	j;
	char	**str_split;

	if (!s)
		return (NULL);
	j = 0;
	i = 0;
	if (!(str_split = (char **)malloc(sizeof(char *)
		* (ft_strcountsplit(s, c) + 1))))
		return (NULL);
	while (s[i])
	{
		if (s[i] == c)
			i++;
		else
		{
			if (!(str_split[j] = ft_strndup(s + i, ft_strclen(s + i, c))))
				return (NULL);
			i += ft_strclen(s + i, c);
			j++;
		}
	}
	str_split[j] = NULL;
	return (str_split);
}
