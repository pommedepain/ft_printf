/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_b.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:50:06 by benjamintle       #+#    #+#             */
/*   Updated: 2019/03/29 17:03:15 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_flag_b(va_list list, t_flag flag)
{
	if (flag.modif)
	{
		if (ft_strcmps(flag.modif, "ll") == 0)
			flag.to_print = ft_ulltoa_base(va_arg(list, unsigned long long), 2, "01");
		if (ft_strcmps(flag.modif, "j") == 0)
			flag.to_print = ft_ulltoa_base(va_arg(list, intmax_t), 2, "01");
		if (ft_strcmps(flag.modif, "z") == 0)
			flag.to_print = ft_ulltoa_base(va_arg(list, unsigned long long), 2, "01");
		if (ft_strcmps(flag.modif, "h") == 0)
			flag.to_print = ft_ulltoa_base(va_arg(list, unsigned int), 2, "01");
		if (ft_strcmps(flag.modif, "l") == 0)
			flag.to_print = ft_ulltoa_base(va_arg(list, unsigned long), 2, "01");
		if (ft_strcmps(flag.modif, "hh") == 0)
			flag.to_print = ft_ulltoa_base(va_arg(list, unsigned int), 2, "01");
	}
	else
		flag.to_print = ft_ulltoa_base(va_arg(list, unsigned int), 2, "01");
	if (flag.precision >= 0)
		flag.to_print = zero_fill(flag.to_print, flag.precision);
	else if (flag.precision == -1)
		flag.to_print = ft_strdups("");
	if (ft_chrstring(flag.option, "#") == 1)
	{
		flag.field -= 2;
		flag.to_print = handle_field(flag);
	}
	else
		flag.to_print = handle_field(flag);
	if (((ft_chrstring(flag.option, "#") == 1) && (ft_strcmps(flag.to_print, "0") != 0)) && ft_strcmps(flag.to_print, "") != 0)
		flag.to_print = ft_strdups(add_hashtag(flag.to_print, "0x"));
	return (flag.to_print);
}
