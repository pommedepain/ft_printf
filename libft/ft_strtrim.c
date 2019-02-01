/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/10 16:39:54 by cajulien          #+#    #+#             */
/*   Updated: 2018/11/10 21:57:37 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		st;
	int		len;

	if (s == NULL)
		return (NULL);
	st = 0;
	while (s[st] && (s[st] == '\n' || s[st] == '\t' || s[st] == ' '))
		st++;
	if (ft_strlen(s) == 0 || st == (int)ft_strlen(s))
		return (ft_strnew(0));
	len = ft_strlen(s) - 1;
	while (s[len] && (s[len] == '\n' || s[len] == '\t' || s[len] == ' '))
		len--;
	return (ft_strsub(s, st, len - st + 1));
}
