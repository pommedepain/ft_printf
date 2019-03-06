/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollie <btollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 14:23:47 by btollie           #+#    #+#             */
/*   Updated: 2018/11/16 14:27:48 by btollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	size_t	i;

	i = 0;
	new = NULL;
	if (s)
	{
		if (!(new = ft_strnew(ft_strlen(s))))
			return (NULL);
		while (s[i])
		{
			new[i] = (*f)(i, (char)s[i]);
			i++;
		}
	}
	return (new);
}
