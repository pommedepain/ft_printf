/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/11 01:05:52 by cajulien          #+#    #+#             */
/*   Updated: 2018/11/11 01:08:09 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list	*probe;

	if (lst == NULL)
		return ;
	probe = lst;
	while (probe)
	{
		(*f)(probe);
		probe = probe->next;
	}
}
