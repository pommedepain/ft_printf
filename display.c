/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:28:18 by cajulien          #+#    #+#             */
/*   Updated: 2019/02/01 14:29:43 by cajulien         ###   ########.fr       */
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
		ft_putstr("string =");
		ft_putendl(tmp->nstr);
		ft_putstr("args = ");
		ft_putendl(tmp->arg);
		tmp = tmp->next;
	}
}