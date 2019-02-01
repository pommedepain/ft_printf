/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 15:42:29 by cajulien          #+#    #+#             */
/*   Updated: 2019/02/01 15:56:09 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		is_spec(char c)
{
	char	*str;
	int		i;

	str = FLAGSET;
	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (c);
		i++;
	}
	return (0);
}
