/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 10:19:09 by cajulien          #+#    #+#             */
/*   Updated: 2018/11/07 14:09:41 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	size_t			i;

	i = 0;
	if (src < dst)
	{
		while (len--)
		{
			((unsigned char *)dst)[len] = ((unsigned char *)src)[len];
		}
	}
	else
	{
		while (i < len)
		{
			((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
			i++;
		}
	}
	return (dst);
}

/*
**int		main(int ac, char **av)
**{
**	if (ac != 3)
**		return (0);
**	printf("%s\n", ft_memmove((void *)av[1], (void *)av[1] + 2, atoi(av[2])));
**	printf("%s\n", memmove((void *)av[1], (void *)av[1] + 2, atoi(av[2])));
**	return (0);
**}
*/
