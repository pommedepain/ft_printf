/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 19:01:42 by pommedepin        #+#    #+#             */
/*   Updated: 2019/03/23 19:14:34 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_flag_f(va_list list, t_flag flag)
{
	flag.to_print = ft_double(va_arg(list, double));
	if (flag.precision > 0)
		flag.to_print = ft_round(flag.to_print, flag.precision);
	else
		flag.to_print = ft_round(flag.to_print, 6);
	flag.to_print = handle_field(flag);
	return (flag.to_print);
}
