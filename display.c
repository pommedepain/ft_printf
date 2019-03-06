/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:28:18 by cajulien          #+#    #+#             */
/*   Updated: 2019/02/01 19:06:54 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	show_data(t_data **data)
{
	t_data		*tmp;

	if (!data || !*data)
		return ;
	tmp = *data;
	while (tmp)
	{
		ft_putnbr(tmp->narg);
		ft_putchar('\n');
		ft_putstr("string =");
		ft_putendl(tmp->nstr);
		ft_putstr("opt =");
		ft_putendl(tmp->flags->opt);
		ft_putstr("width =");
		ft_putendl(tmp->flags->width);
		ft_putstr("prec =");
		ft_putendl(tmp->flags->prec);
		ft_putstr("length =");
		ft_putendl(tmp->flags->length);
		ft_putstr("spec =");
		ft_putchar(tmp->flags->spec);
		ft_putchar('\n');
		tmp = tmp->next;
	}
}
