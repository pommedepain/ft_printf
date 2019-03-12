/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:17:52 by cfauvell          #+#    #+#             */
/*   Updated: 2019/03/12 10:33:42 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Main Function: initialise va_list, call reading_format and return
** result as the number of character print during the call
*/

int		ft_printf(const char *format, ...)
{
	va_list list;
	int		result;

	va_start(list, format);
	result = pf_manager(format, list);
	va_end(list);
	return (result);
}

int		pf_manager(const char *format, va_list ap)
{
	int pos;
	int printed;

	pos = 0;
	printed = 0;
	while (format[pos])
	{
		if (format[pos] == '%')
			printed += ft_parsing(format, &pos, ap);
		if (format[pos] != '%')
			printed += pf_str_manager(format, &pos);
	}
	return (printed);
}

int		ft_strstringlen(const char *str, char *chr)
{
	int j;
	int i;

	i = 0;
	j = 0;
	if (str && chr)
	{
		while (str[i])
		{
			j = 0;
			while (chr[j])
			{
				if (chr[j] == str[i])
					return (i);
				j++;
			}
			i++;
		}
	}
	return (0);
}
