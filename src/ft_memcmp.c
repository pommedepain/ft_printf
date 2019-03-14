/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:38:48 by cajulien          #+#    #+#             */
/*   Updated: 2019/03/14 20:08:05 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s1)[i] != ((unsigned char *)s2)[i])
			return (((unsigned char *)s1)[i] - ((unsigned char *)s2)[i]);
		i++;
	}
	return (0);
}

/*
**int		main(int ac, char **av)
**{
**	if (ac != 4)
**		return (0);
**	printf("%d\n", memcmp((void *)av[1], (void *)av[2], atoi(av[3])));
**	printf("%d\n", ft_memcmp((void *)av[1], (void *)av[2], atoi(av[3])));
**	return (0);
**}
*/
