/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfauvell <cfauvell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 23:01:56 by cfauvell          #+#    #+#             */
/*   Updated: 2019/03/11 18:09:42 by cfauvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_flag_c(va_list list, t_flag flag)
{
	int i;
	
	i = 0;
	flag.to_print = ft_strnew(1);
	*flag.to_print =(va_arg(list, int));
	i = ft_strlen(flag.to_print);
	flag.to_print[i] = '\0';
	if (flag.field > (int)ft_strlen(flag.to_print) && ft_chrstring(flag.option, "-") == 1)
		flag.to_print = space_fill_r(flag.to_print, flag.field);
	if (flag.field > (int)ft_strlen(flag.to_print) && ft_chrstring(flag.option, "-") != 1)
		flag.to_print = space_fill_l(flag.to_print, flag.field);
	return (flag.to_print);
}

char	*ft_flag_s(va_list list, t_flag flag)
{
	flag.to_print = va_arg(list, char *);
	if (flag.precision != 0)
		flag.to_print = precision_string(flag.to_print, flag.precision);
	if (flag.field > (int)ft_strlen(flag.to_print) && ft_chrstring(flag.option, "-") == 1)
		flag.to_print = space_fill_r(flag.to_print, flag.field);
	if (flag.field > (int)ft_strlen(flag.to_print) && ft_chrstring(flag.option, "-") != 1)
		flag.to_print = space_fill_l(flag.to_print, flag.field);
	return (flag.to_print);
}

char	*ft_flag_p(va_list list, t_flag flag)
{
	flag.to_print = print_address(va_arg(list, void *));
	if (flag.field > (int)ft_strlen(flag.to_print) && ft_chrstring(flag.option, "-") == 1)
		flag.to_print = space_fill_r(flag.to_print, flag.field);
	if (flag.field > (int)ft_strlen(flag.to_print) && ft_chrstring(flag.option, "-") != 1)
		flag.to_print = space_fill_l(flag.to_print, flag.field);
	return (flag.to_print);
}

char	*ft_flag_d(va_list list, t_flag flag)
{
	flag.to_print = ft_itoa(va_arg(list, int));
	if (ft_chrstring(flag.option, "+ ") == 1)
		flag.to_print = add_sign(flag.to_print, flag.option);
	if (flag.precision >= 0)
		flag.to_print = zero_fill(flag.to_print, flag.precision);
	if (flag.field > (int)ft_strlen(flag.to_print) && ft_chrstring(flag.option, "-") == 1)
		flag.to_print = space_fill_r(flag.to_print, flag.field);
	if (flag.field > (int)ft_strlen(flag.to_print) && ft_chrstring(flag.option, "-") != 1)
		flag.to_print = space_fill_l(flag.to_print, flag.field);
	return (flag.to_print);
}

char	*ft_flag_o(va_list list, t_flag flag)
{
	unsigned long res;
	int arg;
	res = 0;
	arg = va_arg(list, int);
	if (arg < 0)
		res = UINT_MAX + arg;
	else
		res = arg;
	flag.to_print = ft_ltoa_base(res, 8);
	if (flag.precision >= 0)
		flag.to_print = zero_fill(flag.to_print, flag.precision);
	if (flag.field > (int)ft_strlen(flag.to_print) && ft_chrstring(flag.option, "-") == 1)
		flag.to_print = space_fill_r(flag.to_print, flag.field);
	if (flag.field > (int)ft_strlen(flag.to_print) && ft_chrstring(flag.option, "-") != 1)
		flag.to_print = space_fill_l(flag.to_print, flag.field);
	return (flag.to_print);
}

char	*ft_flag_u(va_list list, t_flag flag)
{
	unsigned long res;
	int arg;

	res = 0;
	arg = va_arg(list, int);
	if (arg < 0)
		res = UINT_MAX + arg;
	else
		res = arg;
	flag.to_print = ft_ltoa(res);
	if (flag.precision >= 0)
		flag.to_print = zero_fill(flag.to_print, flag.precision);
	if (flag.field > (int)ft_strlen(flag.to_print) && ft_chrstring(flag.option, "-") == 1)
		flag.to_print = space_fill_r(flag.to_print, flag.field);
	if (flag.field > (int)ft_strlen(flag.to_print) && ft_chrstring(flag.option, "-") != 1)
		flag.to_print = space_fill_l(flag.to_print, flag.field);
	return(flag.to_print);
}

char	*ft_flag_x(va_list list, t_flag flag)
{
	unsigned long res;
	int arg;
	res = 0;
	arg = va_arg(list, int);
	if (arg < 0)
		res = UINT_MAX + arg;
	else
		res = arg;
	flag.to_print = ft_ltoa_base_2(res, 16);
	if (flag.precision >= 0)
		flag.to_print = zero_fill(flag.to_print, flag.precision);
	if (flag.field > (int)ft_strlen(flag.to_print) && ft_chrstring(flag.option, "-") == 1)
		flag.to_print = space_fill_r(flag.to_print, flag.field);
	if (flag.field > (int)ft_strlen(flag.to_print) && ft_chrstring(flag.option, "-") != 1)
		flag.to_print = space_fill_l(flag.to_print, flag.field);
	return (flag.to_print);
}

char	*ft_flag_X(va_list list, t_flag flag)
{
	unsigned long res;
	int arg;
	res = 0;
	arg = va_arg(list, int);
	if (arg < 0)
		res = UINT_MAX + arg;
	else
		res = arg;
	flag.to_print = ft_ltoa_base(res, 16);
	if (flag.precision >= 0)
		flag.to_print = zero_fill(flag.to_print, flag.precision);
	if (flag.field > (int)ft_strlen(flag.to_print) && ft_chrstring(flag.option, "-") == 1)
		flag.to_print = space_fill_r(flag.to_print, flag.field);
	if (flag.field > (int)ft_strlen(flag.to_print) && ft_chrstring(flag.option, "-") != 1)
		flag.to_print = space_fill_l(flag.to_print, flag.field);
	return (flag.to_print);
}

char	*ft_flag_per(t_flag flag)
{
	flag.to_print = "%";
	if (flag.field > (int)ft_strlen(flag.to_print) && ft_chrstring(flag.option, "-") != 1)
		flag.to_print = space_fill_l(flag.to_print, flag.field);
	if (flag.field > (int)ft_strlen(flag.to_print) && ft_chrstring(flag.option, "-") == 1)
		flag.to_print = space_fill_r(flag.to_print, flag.field);
	return (flag.to_print);
}
