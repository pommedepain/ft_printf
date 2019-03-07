/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfauvell <cfauvell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:09:53 by cfauvell          #+#    #+#             */
/*   Updated: 2019/02/26 17:06:25 by cfauvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

char	*zero_fill(char *str, int i)
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
			while(i-- > j)
				res[k++] = '0';
		}
		else
		{
			res = (char *)malloc(sizeof(char) * (i + 1));
			res[i] = '\0';
			while(i-- > j)
				res[k++] = '0';
		}
		while(j-- > 0)
			res[k++] = str[ibis++];
		free(str);
		return (res);
	}
	return(str);
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

	res = (char *)malloc(sizeof(char) * (i + 1));
	res[i] = '\0';
	while(i-- > j)
		res[k++] = ' ';
	while(j-- > 0)
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

	len = strlen(str);
	k = 0;
	j = 0;
	res = (char *)malloc(sizeof(char) * (i + 1));
	res[i] = '\0';
	while(len-- > 0)
		res[j++] = str[k++];
	i -= j; 
	while(i-- > 0)
		res[j++] = ' ';
	return (res);
}

char	*precision_string(char *str, int i)
{
	char	*res;
	int		j;
	int 	k;

	k = 0;
	j = 0;
	if(!(res = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	res[i] = '\0';
	while(i-- > 0)
		res[k++] = str[j++];
	return (res);
}

char	*add_sign(char *str, char *option)
{
	char	*res;
	int		len;
	int		i;
	int		j;

	len = ft_strlen(str);
	i = 0;
	j = 1;
	if (!(res = (char *)malloc(sizeof(char) * len + 2)))
		return (0);
	res[len + 1] = '\0';
	if (ft_chrstring(option, "+") == 1)
		res[0] = '+';
	if (ft_chrstring(option, " ") == 1)
		res[0] = ' ';
	while(str[i])
		res[j++] = str[i++];
	free(str);
	return(res);
}
