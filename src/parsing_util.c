/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_util.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfauvell <cfauvell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 16:10:57 by cfauvell          #+#    #+#             */
/*   Updated: 2019/03/11 18:48:35 by cfauvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Search if one of multiple characteres (written in the string chr) are 
** contained in a string (str)
*/

int		ft_chrstring(const char *str, char *chr)
{
	int j;
	int i;

	i = 0;
	j = 0;
	if (str && chr)
	{
		while(str[i])
		{
			j = 0;
			while(chr[j])
			{
				if(chr[j] == str[i])
					return (1);
				j++;
			}
			i++;
		}
	}
	return (0);
}

/*
** Search if one of multiple characteres (written in the string chr) are 
** contained in a char (c)
*/

int		ft_chrchar(char c, char *chr)
{
	int i;

	i = 0;
	while (chr[i])
	{
		if (c == chr[i])
			return(1);
		i++;
	}
	return(0);
}

/*
** Convert a decimal digit string (into a bigger string) into a int (With another
** charactere before the digits and with the seucrity if there is no digit after
** this charactere)
*/

int		pf_catchprecision(char *str, int i, va_list list)
{
	int j;
	char *numbers;
	int len;
	int ibis;

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
	while(str[ibis++] >= '0' && str[ibis] <= '9')
		len++;
	numbers = malloc(sizeof(char) * len + 1);
	numbers[len] = '\0';
	while(str[i] >= '0' && str[i] <= '9')
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
	int j;
	char *numbers;
	int len;
	int ibis;

	j = 0;
	len = 1;
	ibis = i;
	if (str[i] == '*')
	{
		j = va_arg(list, int);
		return (j);
	}
	while(str[ibis++] >= '0' && str[ibis] <= '9')
		len++;
	numbers = malloc(sizeof(char) * len + 1);
	while(str[i] >= '0' && str[i] <= '9')
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
	while (ft_chrchar(str[ibis++], options) == 1)
		len++;
	if (!(res = (char *)malloc(sizeof(char)* len + 1)))
		return (NULL);
	res[len] = '\0';
	while (ft_chrchar(str[i], options) == 1)
		res[j++] = str[i++];
	return(res); 
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
	if (!(res = (char *)malloc(sizeof(char)* len + 1)))
		return (NULL);
	res[len] = '\0';
	while (ft_chrchar(str[i], "lLh") == 1)
		res[j++] = str[i++];
	return(res);
}
