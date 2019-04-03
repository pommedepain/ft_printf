/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_functions.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfauvell <cfauvell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/03 14:29:59 by cfauvell          #+#    #+#             */
/*   Updated: 2019/04/03 14:39:40 by cfauvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*init_pars(const char *str, int i)
{
	int		len;
	char	*dest;

	len = ft_strstringlen(&str[i], FLAGS);
	if (!(dest = (char *)malloc(sizeof(char) * len + 2)))
		return (NULL);
	return (dest);
}
