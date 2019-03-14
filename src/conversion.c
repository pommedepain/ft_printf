/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 23:01:56 by cfauvell          #+#    #+#             */
/*   Updated: 2019/03/14 16:23:33 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_flag_c(va_list list, t_flag flag)
{
	int i;

	i = 0;
	i = (va_arg(list, int));
	flag.to_print = ft_strnew(2);
	flag.to_print[0] = i;
	flag.to_print[1] = '\0';
	flag.to_print = handle_field(flag);
	return (flag.to_print);
}

char	*ft_flag_s(va_list list, t_flag flag)
{
	flag.to_print = va_arg(list, char *);
	if (flag.to_print == NULL)
		flag.to_print = "(null)";
	if (flag.precision != 0)
		flag.to_print = precision_string(flag.to_print, flag.precision);
	flag.to_print = handle_field(flag);
	return (flag.to_print);
}

char	*ft_flag_p(va_list list, t_flag flag)
{
	flag.to_print = print_address(va_arg(list, void *));
	flag.to_print = handle_field(flag);
	return (flag.to_print);
}

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

char	*ft_flag_o(va_list list, t_flag flag)
{
	unsigned long	res;
	int				arg;

	res = 0;
	arg = va_arg(list, int);
	if (arg < 0)
		res = UINT_MAX + arg;
	else
		res = arg;
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
		flag.to_print = ft_ulltoa_base(res, 8, _x_);
	if (flag.option)
		if (ft_strcmp(flag.option, "#") == 0)
			flag.to_print = add_hashtag(flag.to_print, "0");
	if (flag.precision >= 0)
		flag.to_print = zero_fill(flag.to_print, flag.precision);
	flag.to_print = handle_field(flag);
	return (flag.to_print);
}

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
		flag.to_print = ft_ulltoa_base(va_arg(list, unsigned int), 10, _x_);
	if (flag.precision >= 0)
		flag.to_print = zero_fill(flag.to_print, flag.precision);
	flag.to_print = handle_field(flag);
	return (flag.to_print);
}

char	*ft_flag_x(va_list list, t_flag flag)
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
			flag.to_print = ft_ulltoa_base(va_arg(list, unsigned long long), 16, _x_);
		if (ft_strcmp(flag.modif, "h") == 0)
			flag.to_print = ft_ulltoa_base(va_arg(list, unsigned int), 16, _x_);
		if (ft_strcmp(flag.modif, "l") == 0)
			flag.to_print = ft_ltoa_base_2(va_arg(list, unsigned long), 16);
		if (ft_strcmp(flag.modif, "hh") == 0)
			flag.to_print = ft_ulltoa_base(va_arg(list, unsigned int), 16, _x_);
	}
	else
		flag.to_print = ft_ulltoa_base(va_arg(list, unsigned int), 16, _x_);
	if (flag.precision >= 0)
		flag.to_print = zero_fill(flag.to_print, flag.precision);
	flag.to_print = handle_field(flag);
	if (flag.option && (ft_chrstring(flag.option, "#") == 1))
		flag.to_print = add_hashtag(flag.to_print, "0x");
	return (flag.to_print);
}

char	*ft_flag_X(va_list list, t_flag flag)
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
			flag.to_print = ft_ulltoa_base(va_arg(list, unsigned long long), 16, _X_);
		if (ft_strcmp(flag.modif, "h") == 0)
			flag.to_print = ft_ulltoa_base(va_arg(list, unsigned int), 16, _X_);
		if (ft_strcmp(flag.modif, "l") == 0)
			flag.to_print = ft_ltoa_base(va_arg(list, unsigned long), 16);
		if (ft_strcmp(flag.modif, "hh") == 0)
			flag.to_print = ft_ulltoa_base(va_arg(list, unsigned int), 16, _X_);
	}
	else
		flag.to_print = ft_ltoa_base(va_arg(list, unsigned int), 16);
	if (flag.precision >= 0)
		flag.to_print = zero_fill(flag.to_print, flag.precision);
	flag.to_print = handle_field(flag);
	if (flag.option && (ft_chrstring(flag.option, "#") == 1))
		flag.to_print = add_hashtag(flag.to_print, "0X");
	return (flag.to_print);
}

char	*ft_flag_per(t_flag flag)
{
	flag.to_print = "%";
	flag.to_print = handle_field(flag);
	return (flag.to_print);
}

char	*handle_field(t_flag flag)
{
	if (flag.field > (int)ft_strlen(flag.to_print) && ft_chrstring(flag.option, "-") == 1)
	{
		if ((ft_chrstring(flag.option, "#") == 1) && ((flag.flag == 'x') || flag.flag == 'X'))
			flag.to_print = space_fill_r(flag.to_print, (flag.field - 2));
		else
			flag.to_print = space_fill_r(flag.to_print, flag.field);
	}
	if (flag.field > (int)ft_strlen(flag.to_print) && ft_chrstring(flag.option, "-") != 1
		&& ft_chrstring(flag.option, "0") == 1 && flag.precision == 0)
	{
		if ((ft_chrstring(flag.option, "#") == 1) && ((flag.flag == 'x') || flag.flag == 'X'))
			flag.to_print = zero_fill_l(flag.to_print, (flag.field - 2));
		else
			flag.to_print = zero_fill_l(flag.to_print, flag.field);
	}
	if (flag.field > (int)ft_strlen(flag.to_print) && ft_chrstring(flag.option, "-") != 1 && ft_chrstring(flag.option, "0") != 1)
	{
		if ((ft_chrstring(flag.option, "#") == 1) && ((flag.flag == 'x') || flag.flag == 'X'))
			flag.to_print = space_fill_l(flag.to_print, (flag.field - 2));
		else
			flag.to_print = space_fill_l(flag.to_print, flag.field);
	}
	if (flag.field > (int)ft_strlen(flag.to_print) && ft_chrstring(flag.option, "-") != 1 && ft_chrstring(flag.option, "0") == 1
		&& flag.precision != 0)
	{
		if ((ft_chrstring(flag.option, "#") == 1) && ((flag.flag == 'x') || flag.flag == 'X'))
			flag.to_print = space_fill_l(flag.to_print, (flag.field - 2));
		else
			flag.to_print = space_fill_l(flag.to_print, flag.field);
	}
	return (flag.to_print);
}
