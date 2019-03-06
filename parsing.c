/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 13:41:31 by cajulien          #+#    #+#             */
/*   Updated: 2019/03/06 14:35:44 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_arg		**init(char *str)
{
	t_arg	**list;
	t_arg	*first;

	if (str == NULL)
		return (NULL);
	if (!first = create_elem(NULL))
		return (NULL);
	list = &first;
	if(!ft_parse(str; first))
	{
		free_list(list);
		return(NULL);
	}	
	return (list);
}
