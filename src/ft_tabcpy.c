/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 13:28:17 by pommedepin        #+#    #+#             */
/*   Updated: 2019/03/14 20:09:49 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_tabcpy(char **dst, char **src)
{
	int k;

	k = 0;
	while (src[k])
	{
		dst[k] = ft_strcpy(dst[k], src[k]);
		k++;
	}
	return (dst);
}
