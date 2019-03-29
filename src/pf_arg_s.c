/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_s.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:50:16 by benjamintle       #+#    #+#             */
/*   Updated: 2019/03/29 17:06:28 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_flag_s(va_list list, t_flag flag)
{
	flag.to_print = ft_strdups(va_arg(list, char *));
	if (flag.precision != 0)
		flag.to_print = precision_string(flag.to_print, flag.precision);
	if (flag.to_print == NULL)
		flag.to_print = ft_strdups("(null)");
	flag.to_print = handle_field(flag);
	return (flag.to_print);
}
