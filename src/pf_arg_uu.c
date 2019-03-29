/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_uu.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:50:10 by benjamintle       #+#    #+#             */
/*   Updated: 2019/03/29 15:49:20 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_flag_uu(va_list list, t_flag flag)
{
	if (flag.modif)
	{
		if (ft_strcmps(flag.modif, "h") == 0)
			flag.to_print = ft_ulltoa_base(va_arg(list, unsigned long), 10, _x_);
		if (ft_strcmps(flag.modif, "hh") == 0)
			flag.to_print = ft_ulltoa_base(va_arg(list, unsigned int), 10, _x_);
		if (ft_strcmps(flag.modif, "ll") == 0)
			flag.to_print = ft_ulltoa_base(va_arg(list, unsigned long long), 10, _x_);
		if (ft_strcmps(flag.modif, "z") == 0)
			flag.to_print = ft_ulltoa_base((unsigned short)va_arg(list, unsigned long), 10, _x_);
		if (ft_strcmps(flag.modif, "j") == 0)
			flag.to_print = ft_ulltoa_base(va_arg(list, intmax_t), 10, _x_);
	}
	else
		flag.to_print = ft_ulltoa_base(va_arg(list, unsigned long long), 10, _x_);
	if (flag.precision >= 0)
		flag.to_print = zero_fill(flag.to_print, flag.precision);
	flag.to_print = handle_field(flag);
	return (flag.to_print);
}

