/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_dupfree.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/18 18:07:17 by cajulien          #+#    #+#             */
/*   Updated: 2019/03/14 20:08:47 by pommedepin       ###   ########.fr       */
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
