/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stuff.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 13:36:38 by cajulien          #+#    #+#             */
/*   Updated: 2019/02/01 15:38:20 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

void	free_data(t_data **data)
{
	t_data		*current;
	t_data		*tmp;

	if (!data || !*data)
			return ;
	current = *data;
	while (current)
	{
		tmp = current->next;
		free(current->nstr);
		free(current->arg);
		free(current->flags);
		free(current);
		current = tmp;
	}
}