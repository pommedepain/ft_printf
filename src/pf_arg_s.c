/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollie <btollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:50:16 by benjamintle       #+#    #+#             */
/*   Updated: 2019/04/03 15:07:44 by btollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_flag_s(va_list list, t_flag flag)
{
	flag.to_print = ft_strdups(va_arg(list, char *));
	if (flag.to_print == NULL && (flag.option == NULL || flag.precision <= 0))
		flag.to_print = ft_strdups("(null)");
	else if (flag.to_print == NULL
			&& (flag.option != NULL || flag.precision > 0))
		flag.to_print = ft_strdups("\0");
	if (flag.precision > 0)
		flag.to_print = precision_string(flag.to_print, flag.precision);
	if (flag.precision == -1)
		flag.to_print = ft_strdups("");
	flag.to_print = handle_field(flag);
	return (flag.to_print);
}
