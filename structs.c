/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 14:16:36 by cajulien          #+#    #+#             */
/*   Updated: 2019/03/06 14:25:31 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

void	free_link(t_arg	*link)
{
	free(link->nstr);
	free(link->flags.option);
	free(link->flags.width);
	free(link->flags.precision);
	free(link->flags.length);
	free(link->flags.spec);
	free(link);
}

void	free_list(t_arg **list)
{
	t_arg	*current;
	t_arg	*next;

	if (!list || !*list)
		return ;
	current = *list;
	while (current)
	{
		next = current->next; 
		free_link(current);
		current = next;
	}
}
