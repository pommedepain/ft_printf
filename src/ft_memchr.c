/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 11:25:43 by cajulien          #+#    #+#             */
/*   Updated: 2019/03/14 20:08:03 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}
/*
**int	main(int ac, char **av)
**{
**	if (ac != 4)
**		return (0);
**	printf("%s\n", ft_memchr((void *)av[1], atoi(av[2]) +48, atoi(av[3])));
**	printf("%s\n", memchr((void *)av[1], atoi(av[2]) + 48, atoi(av[3])));
**	return (0);
**}
*/
