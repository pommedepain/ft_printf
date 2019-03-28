/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_u.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:50:10 by benjamintle       #+#    #+#             */
/*   Updated: 2019/03/28 12:46:10 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_flag_u(va_list list, t_flag flag)
{
	/*unsigned long	res;
	int				arg;

	res = 0;
	arg = va_arg(list, int);
	if (arg < 0)
		res = UINT_MAX + arg;
	else
		res = arg;*/
	if (flag.modif)
	{
		if (ft_strcmp(flag.modif, "ll") == 0)
			flag.to_print = ft_ulltoa_base(va_arg(list, unsigned long long), 10, _x_);
		if (ft_strcmp(flag.modif, "h") == 0)
			flag.to_print = ft_itoa(va_arg(list, unsigned int));
		if (ft_strcmp(flag.modif, "l") == 0)
			flag.to_print = ft_ulltoa_base(va_arg(list, long long), 10, _x_);
		if (ft_strcmp(flag.modif, "hh") == 0)
			flag.to_print = ft_itoa(va_arg(list, unsigned int));
	}
	else
		flag.to_print = ft_ulltoa_base(va_arg(list, unsigned long long), 10, _x_);
	if (flag.precision >= 0)
		flag.to_print = zero_fill(flag.to_print, flag.precision);
	flag.to_print = handle_field(flag);
	return (flag.to_print);
}

