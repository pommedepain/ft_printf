/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_numlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 01:42:03 by cajulien          #+#    #+#             */
/*   Updated: 2019/03/14 20:08:21 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_numlen(unsigned long long int value, int base_size)
{
	int		i;

	i = 1;
	while (value >= (unsigned long long)base_size)
	{
		value /= base_size;
		i++;
	}
	return (i);
}
