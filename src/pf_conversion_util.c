/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_conversion_util.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:09:53 by cfauvell          #+#    #+#             */
/*   Updated: 2019/04/03 15:11:31 by psentilh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*zero_fill(char *str, int i)
{
	char	*res;
	int		j;
	int		k;
	int		ibis;

	j = ft_strlen(str);
	k = 0;
	ibis = 0;
	if (i > (j - 1))
	{
		if (ft_chrchar(str[0], "-+ ") == 1)
		{
			ibis = 1;
			k = 1;
			j = ft_strlen(str);
			res = (char *)malloc(sizeof(char) * (i + 2));
			res[i + 1] = '\0';
			res[0] = str[0];
			while (i-- > (j - 1))
				res[k++] = '0';
		}
		else
		{
			res = (char *)malloc(sizeof(char) * (i + 1));
			res[i] = '\0';
			while (i-- > j)
				res[k++] = '0';
		}
		while (j-- > 0)
			res[k++] = str[ibis++];
		free(str);
		return (res);
	}
	return (str);
}

char	*zero_fill_l(char *str, int i)
{
	char	*res;
	int		j;
	int		k;
	int		ibis;

	j = ft_strlen(str);
	k = 0;
	ibis = 0;
	if (i > j)
	{
		if (ft_chrchar(str[0], "-+ ") == 1)
		{
			ibis = 1;
			k = 1;
			j = ft_strlen(str) - 1;
			res = (char *)malloc(sizeof(char) * (i + 2));
			res[i + 1] = '\0';
			res[0] = str[0];
			while (--i > j)
				res[k++] = '0';
		}
		else
		{
			res = (char *)malloc(sizeof(char) * (i + 1));
			res[i] = '\0';
			while (i-- > j)
				res[k++] = '0';
		}
		while (j-- > 0)
			res[k++] = str[ibis++];
		free(str);
		return (res);
	}
	return (str);
}

char	*space_fill_l(char *str, int i)
{
	char	*res;
	int		j;
	int		k;
	int		ibis;

	j = ft_strlen(str);
	k = 0;
	ibis = 0;
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	res[i] = '\0';
	while (i-- > j)
		res[k++] = ' ';
	while (j-- > 0)
		res[k++] = str[ibis++];
	free(str);
	return (res);
}

char	*space_fill_r(char *str, int i)
{
	char	*res;
	int		j;
	int		k;
	int		len;

	len = ft_strlen(str);
	k = 0;
	j = 0;
	if (!(res = (char *)malloc(sizeof(char) * (i + 1))))
		return (NULL);
	res[i] = '\0';
	while (len-- > 0)
		res[j++] = str[k++];
	i -= j;
	while (i-- > 0)
		res[j++] = ' ';
	free(str);
	return (res);
}

char	*precision_string(char *str, int i)
{
	char	*res;
	int		j;
	int		k;

	k = 0;
	j = 0;
	if (!(res = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	res[i] = '\0';
	while (i-- > 0)
		res[k++] = str[j++];
	return (res);
}
