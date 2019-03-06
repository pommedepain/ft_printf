/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollie <btollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:03:51 by btollie           #+#    #+#             */
/*   Updated: 2018/11/16 14:28:10 by btollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	size_t	i;
	char	*new;

	new = NULL;
	i = 0;
	if (s)
	{
		if (!(new = ft_strnew(ft_strlen(s))))
			return (NULL);
		while (s[i])
		{
			new[i] = (*f)((char)s[i]);
			i++;
		}
	}
	return (new);
}
