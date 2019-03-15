/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_o.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:50:12 by benjamintle       #+#    #+#             */
/*   Updated: 2019/03/15 11:35:39 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_flag_o(va_list list, t_flag flag)
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
			flag.to_print = ft_ulltoa_base(va_arg(list, unsigned long long), 8, _x_);
		if (ft_strcmp(flag.modif, "h") == 0)
			flag.to_print = ft_ulltoa_base(va_arg(list, unsigned int), 8, _x_);
		if (ft_strcmp(flag.modif, "l") == 0)
			flag.to_print = ft_ulltoa_base(va_arg(list, unsigned long), 8, _x_);
		if (ft_strcmp(flag.modif, "hh") == 0)
			flag.to_print = ft_ulltoa_base(va_arg(list, unsigned int), 8, _x_);
	}
	else
		flag.to_print = ft_ulltoa_base(va_arg(list, unsigned int), 8, _x_);
	if (flag.precision < 0)
		flag.to_print = "";
	else if (flag.precision >= 0)
		flag.to_print = zero_fill(flag.to_print, flag.precision);
	printf("ap precision = -->%s<--\n", flag.to_print);
	flag.to_print = handle_field(flag);
	printf("av option = -->%s<--\n", flag.to_print);
	if ((ft_chrstring(flag.option, "#") == 1))
	{
		if (flag.precision == -1)
			flag.to_print = "0";
		else if (ft_strcmp(flag.to_print, "0") == 0)
			flag.to_print = flag.to_print;
		else
			flag.to_print = add_hashtag(flag.to_print, "0");
	}
	//if ((ft_strcmp(flag.option, "#") == 0) && ft_chrstring(flag.option, "-") == 1)
	//	flag.to_print = add_hashtag(flag.to_print, "0");
	printf("final = -->%s<--\n", flag.to_print);
	return (flag.to_print);
}
