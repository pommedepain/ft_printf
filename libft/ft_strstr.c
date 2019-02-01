/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 16:16:33 by cajulien          #+#    #+#             */
/*   Updated: 2018/11/07 18:57:01 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *haystack, const char *needle)
{
	size_t	needle_len;
	size_t	i;
	size_t	j;

	i = 0;
	needle_len = ft_strlen(needle);
	if (needle_len == 0)
		return ((char *)haystack);
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j])
		{
			j++;
			if (j == needle_len)
				return ((char *)haystack + i);
		}
		i++;
	}
	return (NULL);
}
