/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamintle <benjamintle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 23:01:56 by cfauvell          #+#    #+#             */
/*   Updated: 2019/03/07 17:31:08 by benjamintle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*ft_flag_c(va_list list, char *tmp)
{
	int i;
	
	i = 0;
	tmp = ft_strnew(1);
	*tmp =(va_arg(list, int));
	i = ft_strlen(tmp);
	tmp[i] = '\0';
	return (tmp);
}

char	*ft_flag_d(va_list list, char *tmp)
{
	tmp = ft_itoa(va_arg(list, int));
	return (tmp);
}

char	*ft_flag_s(va_list list, char *tmp)
{
	tmp = va_arg(list, char *);
	return (tmp);
}

char	*ft_flag_u(va_list list, char *tmp)
{
	unsigned long	res;
	int				arg;

	res = 0;
	arg = va_arg(list, int);
	if (arg < 0)
		res = UINT_MAX + arg;
	else
		res = arg;
	tmp = ft_ltoa(res);
	return(tmp);
}

char	*ft_flag_o(va_list list, char *tmp)
{
	unsigned long	res;
	int				arg;
	res = 0;
	arg = va_arg(list, int);
	if (arg < 0)
		res = UINT_MAX + arg;
	else
		res = arg;
	tmp = ft_ltoa_base(res, 8);
	return (tmp);
}

char	*ft_flag_X(va_list list, char *tmp)
{
	unsigned long	res;
	int				arg;
	res = 0;
	arg = va_arg(list, int);
	if (arg < 0)
		res = UINT_MAX + arg;
	else
		res = arg;
	tmp = ft_ltoa_base(res, 16);
	return (tmp);
}

char	*ft_flag_x(va_list list, char *tmp)
{
	unsigned long	res;
	int				arg;
	res = 0;
	arg = va_arg(list, int);
	if (arg < 0)
		res = UINT_MAX + arg;
	else
		res = arg;
	tmp = ft_ltoa_base_2(res, 16);
	return (tmp);
}

char	*ft_flag_p(va_list list, char *tmp)
{
	tmp = print_address(va_arg(list, void *));
	return (tmp);
}
