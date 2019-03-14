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
	int i;

	i = 0;
	i = (va_arg(list, int));
	flag.to_print = ft_strnew(2);
	flag.to_print[0] = i;
	flag.to_print[1] = '\0';
	flag.to_print = handle_field(flag);
	return (flag.to_print);
}
