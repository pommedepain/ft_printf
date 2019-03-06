/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   va_start.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 17:24:11 by pommedepin        #+#    #+#             */
/*   Updated: 2019/01/24 18:03:53 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char		*normstr(char *str)
{

}

int			ft_va_start(const char *str_start)
{
	va_list	ap;
	t_printf *param;

	va_start(ap, str_start);
	while (str_start)
	{
		param->normstr = va_arg(ap, char *);
		//param->normstr = normstr(va_arg(ap, char *));
		ft_putstr(param->normstr);
	}
	va_end(ap);
	return (0);
}

int		main(int ac, char **av)
{
	if (ac > 1)
	{

	}
}
