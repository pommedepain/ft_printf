/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_f.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/23 19:01:42 by pommedepin        #+#    #+#             */
/*   Updated: 2019/04/03 15:55:46 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			*ft_flag_f(va_list list, t_flag flag)
{
	flag.to_print = ft_double(va_arg(list, double));
	if (flag.precision > 0)
		flag.to_print = ft_round(flag.to_print, flag.precision);
	else if (flag.precision == -1)
		flag.to_print = ft_round(flag.to_print, 0);
	else
		flag.to_print = ft_round(flag.to_print, 6);
	flag.to_print = handle_field(flag);
	return (flag.to_print);
}
