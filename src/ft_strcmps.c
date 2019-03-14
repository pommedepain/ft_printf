/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmps.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 03:16:00 by cajulien          #+#    #+#             */
/*   Updated: 2019/03/14 20:08:55 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strcmps(const char *s1, const char *s2)
{
	size_t		i;

	i = 0;
	if (!s1 && !s2)
		return (0);
	if (!s1 && s2)
		return (0 - ((unsigned char *)s2)[i]);
	if (s1 && !s2)
		return (((unsigned char *)s1)[i] - 0);
	while (s1[i] == s2[i] && s1[i] && s2[i])
		i++;
	return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
}
