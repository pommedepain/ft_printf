/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfauvell <cfauvell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:20:18 by cfauvell          #+#    #+#             */
/*   Updated: 2019/03/12 02:37:38 by cfauvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

/*
** Duplicate the "%   " part of format in a separate string (with the call of
** ft_fillparsing)
** Fill the structure flag, with all classified information to help the
** conversion
** (with the call of fillflag)
*/

int		ft_parsing(const char *format, int *i, va_list list)
{
	t_flag	flag;
	int		res;

	res = 0;
	flag.parsing = NULL;
	flag.to_print = NULL;
	*i += 1;
	flag.parsing = ft_fillparsing(format, *i, flags);
	if (flag.parsing == NULL)
		return (0);
	flag = fill_flag(flag, list);
	if (flag.flag == 'c')
		flag.to_print = ft_flag_c(list, flag);
	if (flag.flag == 's')
		flag.to_print = ft_flag_s(list, flag);
	if (flag.flag == 'p')
		flag.to_print = ft_flag_p(list, flag);
	if (flag.flag == 'd' || flag.flag == 'i')
		flag.to_print = ft_flag_d(list, flag);
	if (flag.flag == 'o')
		flag.to_print = ft_flag_o(list, flag);
	if (flag.flag == 'u')
		flag.to_print = ft_flag_u(list, flag);
	if (flag.flag == 'X')
		flag.to_print = ft_flag_X(list, flag);
	if (flag.flag == 'x')
		flag.to_print = ft_flag_x(list, flag);
	if (flag.flag == '%')
		flag.to_print = ft_flag_per(flag);
	if (flag.flag == 'Z')
		flag.to_print = "Z";
	*i += ft_strlen(flag.parsing);
	free(flag.parsing);
	free(flag.option);
	free(flag.modif);
	ft_putstr(flag.to_print);
	res = ft_strlen(flag.to_print);
	return (res);
}

/*
** Duplicate the format string until a conversion specifier appears(Create a
** "flag string")
*/

char	*ft_fillparsing(const char *str, int i, char *chr)
{
	int		j;
	char	*dest;
	int		k;
	int		len;

	j = 0;
	k = 0;
	if (ft_chrstring(&str[i], flags) != 1)
		return (NULL);
	len = ft_strstringlen(&str[i], flags);
	if (!(dest = (char *)malloc(sizeof(char) * len + 2)))
		return (NULL);
	while (str[i])
	{
		j = 0;
		while (chr[j])
		{
			if (chr[j] == str[i])
			{
				dest[k] = str[i];
				dest[k + 1] = '\0';
				return (dest);
			}
			j++;
		}
		dest[k++] = str[i++];
	}
	return (NULL);
}

/*
** Check a flag string to see and classified all the parameter in the flag
** structure
*/

t_flag	fill_flag(t_flag flag, va_list list)
{
	int i;

	i = 0;
	flag.precision = 0;
	flag.field = 0;
	flag.option = NULL;
	flag.modif = NULL;
	while (flag.parsing[i])
	{
		if (ft_chrchar(flag.parsing[i], options) == 1)
		{
			flag.option = pf_catch_option(flag.parsing, i, flag.option);
			while (ft_chrchar(flag.parsing[i], options) == 1)
				i++;
		}
		if ((flag.parsing[i] >= '0' && flag.parsing[i] <= '9') || flag.parsing[i] == '*')
		{
			flag.field = pf_catchfield(flag.parsing, i, list);
			while ((flag.parsing[i] >= '0' && flag.parsing[i] <= '9') || flag.parsing[i] == '*')
				i++;
		}
		if (flag.parsing[i] == '.')
		{
			flag.precision = pf_catchprecision(flag.parsing, i, list);
			i += 1;
			while ((flag.parsing[i] >= '0' && flag.parsing[i] <= '9') || flag.parsing[i] == '*')
				i++;
		}
		if (ft_chrchar(flag.parsing[i], "lLh") == 1)
		{
			flag.modif = pf_catchmodifier(flag.parsing, i, flag.modif);
			while (ft_chrchar(flag.parsing[i], "lLh") == 1)
				i++;
		}
		i++;
	}
	flag.flag = flag.parsing[i - 1];
	return (flag);
}
