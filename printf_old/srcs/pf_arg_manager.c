/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamintle <benjamintle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/05 17:33:32 by benjamin          #+#    #+#             */
/*   Updated: 2019/03/06 20:18:30 by benjamintle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int			pf_arg_manager(char *str, int *pos)
{
	int			i;
	t_flags		flags;

	pf_initstruct(&flags);
	i = 0;
	if (str[*pos + i] == '-')
	{
		arg.align = 1;
		i++;
	}
	if (str[*pos + i] == '+')
	{
		arg.sign = 1;
		i++;
	}
	if (str[*pos + i] == '#')
	{
		arg.sharp = 1;
		i++;
	}
		if (str[*pos + i] == '0')
	{
		arg.zero = 1;
		i++;
	}
		if (str[*pos + i] == ' ')
	{
		arg.space = 1;
		i++;
	}
		if (ft_isdigit(str[*pos + i]))
	{
		arg.width = ft_atoi(&str[*pos + i]);
		while (ft_isdigit(str[*pos + i]))
			i++;
	}
		if (str[*pos + i] == '.')
	{
		i++;
		arg.precision = ft_atoi(&str[*pos + i]);
	}
	return(i);
}
