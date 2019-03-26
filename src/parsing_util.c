/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamintle <benjamintle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:10:57 by cfauvell          #+#    #+#             */
/*   Updated: 2019/03/13 12:41:31 by benjamintle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"



/*
** Convert a decimal digit string (into a bigger string) into a int
** (With another
** charactere before the digits and with the seucrity if there is no digit after
** this charactere)
*/

int		pf_catchprecision(char *str, int i, va_list list)
{
	int		j;
	char	*numbers;
	int		len;
	int		ibis;

	j = 0;
	i += 1;
	len = 1;
	ibis = i;
	if ((str[i] <= '0' || str[i] >= '9') && str[i] != '*')
		return (-1);
	if (str[i] == '*')
	{
		j = va_arg(list, int);
		return (j);
	}
	while (str[ibis++] >= '0' && str[ibis] <= '9')
		len++;
	numbers = malloc(sizeof(char) * len + 1);
	numbers[len] = '\0';
	while (str[i] >= '0' && str[i] <= '9')
		numbers[j++] = str[i++];
	j = ft_atoi(numbers);
	free(numbers);
	return (j);
}

/*
** Convert a decimal digit string (into a bigger string) into a int
*/

int		pf_catchfield(char *str, int i, va_list list)
{
	int		j;
	char	*numbers;
	int		len;
	int		ibis;

	j = 0;
	len = 1;
	ibis = i;
	if (str[i] == '*')
	{
		j = va_arg(list, int);
		return (j);
	}
	while (str[ibis++] >= '0' && str[ibis] <= '9')
		len++;
	numbers = malloc(sizeof(char) * len + 1);
	while (str[i] >= '0' && str[i] <= '9')
		numbers[j++] = str[i++];
	numbers[j] = '\0';
	j = ft_atoi(numbers);
	free(numbers);
	return (j);
}

char	*pf_catch_option(char *str, int i, char *res)
{
	int j;
	int len;
	int ibis;

	j = 0;
	len = 0;
	ibis = i;
	while (ft_chrchar(str[ibis++], OPTIONS) == 1)
		len++;
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len] = '\0';
	while (ft_chrchar(str[i], OPTIONS) == 1)
		res[j++] = str[i++];
	return (res);
}

char	*pf_catchmodifier(char *str, int i, char *res)
{
	int j;
	int len;
	int ibis;

	j = 0;
	len = 0;
	ibis = i;
	while (ft_chrchar(str[ibis++], "lLh") == 1)
		len++;
	if (!(res = (char *)malloc(sizeof(char) * len + 1)))
		return (NULL);
	res[len] = '\0';
	while (ft_chrchar(str[i], "lLh") == 1)
		res[j++] = str[i++];
	return (res);
}
