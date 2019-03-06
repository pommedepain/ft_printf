/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollie <btollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/13 13:36:44 by btollie           #+#    #+#             */
/*   Updated: 2018/11/13 13:43:15 by btollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *strnew;

	if (!(strnew = (char *)malloc(sizeof(char) * size + 1)))
		return (NULL);
	while (size + 1)
	{
		strnew[size--] = 0;
	}
	return (strnew);
}
