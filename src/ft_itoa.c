/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 20:26:49 by cajulien          #+#    #+#             */
/*   Updated: 2019/03/14 20:07:35 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		ft_nlen(int n)
{
	int				len;
	unsigned int	nb;

	len = 1;
	if (n < 0)
		nb = n * -1;
	else
		nb = n;
	while (nb >= 10)
	{
		nb /= 10;
		len++;
	}
	return (len);
}

char			*ft_itoa(int n)
{
	char			*str;
	int				len;
	unsigned int	nb;

	len = ft_nlen(n);
	if (n < 0)
	{
		nb = n * -1;
		len++;
	}
	else
		nb = n;
	if (!(str = (char *)malloc(sizeof(char) * (len + 1))))
		return (NULL);
	str[len] = '\0';
	while (len)
	{
		str[--len] = nb % 10 + 48;
		nb /= 10;
	}
	if (n < 0)
		str[0] = '-';
	return (str);
}
