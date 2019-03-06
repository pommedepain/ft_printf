/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_manager.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamintle <benjamintle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 16:22:21 by benjamin          #+#    #+#             */
/*   Updated: 2019/03/06 20:53:09 by benjamintle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int		pf_manager(char *str, va_list ap)
{
	int pos;
	int printed;

	pos = 0;
	printed = 0;
	while (str[pos])
	{
		if (str[pos] == '%')
			printed += pf_arg_manager(str, &pos);
		if (str[pos] != '%')
			printed += pf_str_manager(str, &pos);
	}
	return (printed);
}
