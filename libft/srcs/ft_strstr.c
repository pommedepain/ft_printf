/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollie <btollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/12 15:10:18 by btollie           #+#    #+#             */
/*   Updated: 2018/11/12 15:50:54 by btollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	char *ret;
	char *to_find;

	if (*needle == 0)
		return ((char *)haystack);
	ret = NULL;
	to_find = (char *)needle;
	while (*haystack)
	{
		if (*haystack == *to_find)
		{
			if (ft_memcmp(haystack, needle, ft_strlen(needle)) == 0)
				return ((char *)haystack);
		}
		haystack++;
	}
	return (NULL);
}
