/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollie <btollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 14:14:00 by btollie           #+#    #+#             */
/*   Updated: 2018/11/12 14:28:11 by btollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char *ret;

	if (c == 0)
		return (ft_strchr(s, c));
	ret = NULL;
	while (*s)
	{
		if (*s == (char)c)
			ret = (char *)s;
		if (!*s)
			return (0);
		s++;
	}
	return (ret);
}
