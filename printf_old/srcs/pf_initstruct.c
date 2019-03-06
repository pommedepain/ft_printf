/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_initstruct.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamintle <benjamintle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/07 14:23:39 by benjamintle       #+#    #+#             */
/*   Updated: 2019/03/06 20:18:44 by benjamintle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	pf_initstruct(t_flags *init)
{
	init->str = NULL;
	init->align = 0;
	init->sign = 0;
	init->sharp = 0;
	init->zero = 0;
	init->space = 0;
	init->width = 0;
	init->precision = 0;
	init->size = 0;
	init->type = 0;
}
