/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollie <btollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 23:01:56 by cfauvell          #+#    #+#             */
/*   Updated: 2019/03/29 18:02:48 by btollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*handle_field(t_flag flag)
{
	if (flag.field > (int)ft_strlen(flag.to_print) && ft_chrstring(flag.option, "-") == 1)
		flag.to_print = space_fill_r(flag.to_print, flag.field);
	if (flag.field > (int)ft_strlen(flag.to_print) && ft_chrstring(flag.option, "-") != 1
		&& ft_chrstring(flag.option, "0") == 1 && flag.precision == 0)
		flag.to_print = zero_fill_l(flag.to_print, flag.field);
	if (flag.field > (int)ft_strlen(flag.to_print) && ft_chrstring(flag.option, "-") != 1
		&& ft_chrstring(flag.option, "0") != 1)
		flag.to_print = space_fill_l(flag.to_print, flag.field);
	if (flag.field > (int)ft_strlen(flag.to_print) && ft_chrstring(flag.option, "-") != 1
		&& ft_chrstring(flag.option, "0") == 1 && flag.precision != 0)
		flag.to_print = space_fill_l(flag.to_print, flag.field);
	return (flag.to_print);
}
