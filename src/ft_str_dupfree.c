/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_dupfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:07:17 by cajulien          #+#    #+#             */
/*   Updated: 2018/11/18 18:13:22 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_str_dupfree(char *str)
{
	char	*new;

	new = NULL;
	new = ft_strdups(str);
	free(str);
	str = NULL;
	return (new);
}
