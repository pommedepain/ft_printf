/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_c.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamintle <benjamintle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:45:24 by benjamintle       #+#    #+#             */
/*   Updated: 2019/03/12 14:58:42 by benjamintle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_flag_c(va_list list, t_flag flag)
{
	flag.to_print = ft_strnew(2);
	if (ft_strcmps(flag.modif, "l") != 0)
		flag.to_print[0] = va_arg(list, wint_t);
	else
		flag.to_print[0] = va_arg(list, int);
	flag.to_print[1] = '\0';
	flag.to_print = handle_field(flag);
	return (flag.to_print);
}
