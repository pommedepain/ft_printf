/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamintle <benjamintle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:44:45 by btollie           #+#    #+#             */
/*   Updated: 2019/02/18 12:50:47 by benjamintle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int ft_printf(const char *restrict format, ... )
{
	va_list ap;
	char *str;
	int i;

	va_start(ap, format);
	i = 0;
	if (!(str = ft_strndup(format, ft_strlen(format))))
		return(-1);
	i = pf_manager(str, ap);
	free(str);
	va_end(ap);
	printf("\nLa fonction renvoit %d\n", i);
	return(i);
}
