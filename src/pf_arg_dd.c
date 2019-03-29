/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_dd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamintle <benjamintle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:50:19 by benjamintle       #+#    #+#             */
/*   Updated: 2019/03/28 17:27:46 by benjamintle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_flag_dd(va_list list, t_flag flag)
{
	if (ft_strcmp(flag.modif, "z") == 0)
	{
		flag.to_print = ft_lltoa_base(va_arg(list, ssize_t), 10, _x_);
		return(flag.to_print);
	}
	else
	{
		flag.to_print = ft_ulltoa_base(va_arg(list, long long), 10, _x_);
		return (flag.to_print);
	}
	if (ft_chrstring(flag.option, "+ ") == 1)
		flag.to_print = add_sign(flag.to_print, flag.option);
	if ((flag.precision >= 0 || flag.precision == -1) && ft_strequ(flag.modif, "j"))
	{
		if (flag.precision <= 0 && ft_strequ(flag.to_print, "0"))
		{
			free(flag.to_print);
			flag.to_print = ft_strdups("\0");
		}
		else if (flag.precision >= 0)
			flag.to_print = zero_fill(flag.to_print, flag.precision);
	}
	flag.to_print = handle_field(flag);
	return (flag.to_print);
}

