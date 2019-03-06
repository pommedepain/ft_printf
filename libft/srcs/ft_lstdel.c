/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: btollie <btollie@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/17 19:06:52 by benjamintle       #+#    #+#             */
/*   Updated: 2018/11/19 15:22:54 by btollie          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void*, size_t))
{
	t_list *next;

	if (!alst || !del)
		return ;
	next = (*alst)->next;
	ft_lstdelone(alst, del);
	if (next != NULL)
		ft_lstdel(&next, del);
	alst = NULL;
	ft_memdel((void *)next);
}
