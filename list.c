/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:30:24 by cajulien          #+#    #+#             */
/*   Updated: 2019/02/01 18:39:48 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int			init_elem(t_data *data)
{
	data->narg = 0;
	data->nstr = NULL;
	if(!(data->flags = (t_flags *)malloc(sizeof(t_flags))))
		return (0); 
	data->flags->opt = NULL;
	data->flags->width = NULL;
	data->flags->prec = NULL;
	data->flags->length = NULL;
	data->next = NULL;
	return (1);
}

t_data				*create_elem(t_data *data)
{
    t_data			*new;
    
	if(!(new = (t_data *)malloc(sizeof(t_data))))
		return (NULL);
	if (!init_elem(new))
		return (NULL);
	data != NULL ? data->next = new : 0;
	return (new); 
}
