/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_str_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfauvell <cfauvell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 12:06:14 by btollie           #+#    #+#             */
/*   Updated: 2019/04/03 15:36:17 by cfauvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int			pf_str_manager(const char *str, int *pos)
{
	int		i;
	char	*to_print;

	i = 0;
	to_print = NULL;
	if (!str || *pos < 0)
		return (-1);
	while (str[*pos + i] && str[*pos + i] != '%')
		i++;
	to_print = ft_strnew((size_t)i);
	i = 0;
	while (str[*pos + i] && str[*pos + i] != '%')
	{
		to_print[i] = str[*pos + i];
		i++;
	}
	ft_putstr(to_print);
	free(to_print);
	*pos += i;
	return (i);
}
