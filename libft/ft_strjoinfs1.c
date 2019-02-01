/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoinfs1.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 18:19:24 by cajulien          #+#    #+#             */
/*   Updated: 2018/12/01 20:05:48 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoinfs1(char *s1, char *s2)
{
	char	*join;

	join = NULL;
	if (!s1 && !s2)
		return (NULL);
	if (!s1)
		return (ft_strdups(s2));
	if (!s2)
		return (s1);
	if (!(join = ft_strnew(ft_strlens(s1) + ft_strlens(s2) + 1)))
		return (NULL);
	join = ft_strcpy(join, s1);
	join = ft_strcat(join, s2);
	ft_strdel(&s1);
	return (join);
}
