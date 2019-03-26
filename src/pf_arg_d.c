/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:50:19 by benjamintle       #+#    #+#             */
/*   Updated: 2019/03/14 20:41:04 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_flag_d(va_list list, t_flag flag)
{
	if (flag.modif)
	{
		if (ft_strcmp(flag.modif, "ll") == 0)
			flag.to_print = ft_lltoa_base(va_arg(list, long long), 10, _x_);
		if (ft_strcmp(flag.modif, "h") == 0)
			flag.to_print = ft_itoa(va_arg(list, int));
		if (ft_strcmp(flag.modif, "l") == 0)
			flag.to_print = ft_ltoa_base(va_arg(list, long), 10);
		if (ft_strcmp(flag.modif, "hh") == 0)
			flag.to_print = ft_itoa(va_arg(list, int));
	}
	else
		flag.to_print = ft_itoa(va_arg(list, int));
	if (ft_chrstring(flag.option, "+ ") == 1)
		flag.to_print = add_sign(flag.to_print, flag.option);
	if (flag.precision >= 0)
		flag.to_print = zero_fill(flag.to_print, flag.precision);
	flag.to_print = handle_field(flag);
	return (flag.to_print);
}

