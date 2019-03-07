/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_no_whitespaces.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 02:59:27 by cajulien          #+#    #+#             */
/*   Updated: 2018/11/11 02:59:30 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_no_whitespaces(char *str)
{
	int		i;
	int		j;

	i = 0;
	if (str == NULL)
		return (NULL);
	while (str[i])
	{
		while (!(str[i] == ' ' || str[i] == '\n' || str[i] == '\t') && str[i])
			i++;
		j = 0;
		while (str[i + j] != '\0')
		{
			str[i + j] = str[i + j + 1];
			j++;
		}
	}
	str[i] = '\0';
	return (str);
}
