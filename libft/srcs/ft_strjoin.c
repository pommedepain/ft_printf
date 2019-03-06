/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollie <btollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 16:24:07 by btollie           #+#    #+#             */
/*   Updated: 2018/11/13 18:18:53 by btollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str_join;
	int		i;
	int		j;

	str_join = NULL;
	i = 0;
	j = 0;
	if (s1 && s2)
	{
		if (!(str_join = ft_strnew(ft_strlen(s1) + ft_strlen(s2))))
			return (NULL);
		while (s1[i])
		{
			str_join[i] = s1[i];
			i++;
		}
		while (s2[j])
		{
			str_join[i + j] = s2[j];
			j++;
		}
	}
	return (str_join);
}
