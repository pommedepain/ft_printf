/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdups.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 03:46:28 by cajulien          #+#    #+#             */
/*   Updated: 2018/11/18 16:12:02 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdups(const char *s1)
{
	size_t	len;
	size_t	i;
	char	*dst;

	i = 0;
	if (!s1)
		return (NULL);
	len = ft_strlens(s1);
	if (!(dst = (char *)malloc(sizeof(*dst) * (len + 1))))
		return (0);
	while (i < len)
	{
		dst[i] = s1[i];
		i++;
	}
	dst[len] = '\0';
	return (dst);
}
