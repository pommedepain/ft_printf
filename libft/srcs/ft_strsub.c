/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollie <btollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:13:31 by btollie           #+#    #+#             */
/*   Updated: 2018/11/13 16:23:34 by btollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char	*str_sub;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	str_sub = NULL;
	if (!(str_sub = ft_strnew(len)))
		return (NULL);
	if (s)
	{
		while (i < start)
			i++;
		while (s[i] && j < len)
		{
			str_sub[j] = s[i];
			i++;
			j++;
		}
	}
	return (str_sub);
}
