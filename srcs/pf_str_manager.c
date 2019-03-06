/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_strmanager.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamintle <benjamintle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:38:34 by benjamin          #+#    #+#             */
/*   Updated: 2019/03/06 20:16:24 by benjamintle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_str_manager(char *str, int *pos)
{
	int i;
	char *to_print;

	i = 0;
	if (!str || *pos < 0 || !to_print)
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
	return(i);
}
