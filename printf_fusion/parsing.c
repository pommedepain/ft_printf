/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfauvell <cfauvell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:20:18 by cfauvell          #+#    #+#             */
/*   Updated: 2019/03/07 12:35:07 by cfauvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Duplicate the "%   " part of format in a separate string (with the call of 
** ft_fillparsing)
** Fill the structure flag, with all classified information to help the conversion
** (with the call of fillflag)
*/

int		ft_parsing(const char *format, int *i, va_list list)
{
	t_flag	flag;
	char	*tmp;
	int		res;

	res = 0;
	tmp = NULL;
	flag.parsing = NULL;
	flag.to_print = NULL;
	flag.parsing = ft_fillparsing(format, *i, flags);
	flag = fill_flag(flag);
	if (flag.flag == 'c')
		tmp = ft_flag_c(list, tmp);
	if (flag.flag == 'd' || flag.flag == 'i')
		tmp = ft_flag_d(list, tmp);
	if (flag.flag == 's')
		tmp = ft_flag_s(list, tmp);
	if (flag.flag == 'u')
		tmp = ft_flag_u(list, tmp);
	if (flag.flag == 'o')
		tmp = ft_flag_o(list, tmp);
	if (flag.flag == 'X')
		tmp = ft_flag_X(list, tmp);
	if (flag.flag == 'x')
		tmp = ft_flag_x(list, tmp);
	if (ft_chrstring(flag.option, "+ ") == 1  && ft_chrchar(flag.flag, "dif") == 1)
		tmp = add_sign(tmp, flag.option);
	if (flag.precision >= 0 && ft_chrstring(flag.parsing, "diouxX") == 1)
		tmp = zero_fill(tmp, flag.precision);
	if (flag.precision != 0 && ft_chrstring(flag.parsing, "s") == 1)
		tmp = precision_string(tmp, flag.precision);
	if (flag.field > (int)ft_strlen(tmp) && ft_chrstring(flag.option, "-") == 1)
		tmp = space_fill_r(tmp, flag.field);
	if (flag.field > (int)ft_strlen(tmp) && ft_chrstring(flag.option, "-") != 1)
		tmp = space_fill_l(tmp, flag.field);
	*i += ft_strlen(flag.parsing);
	free(flag.parsing);
	free(flag.option);
	ft_putstr(tmp);
	res = ft_strlen(tmp);
	
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
	len = ft_strstringlen(&str[i], flags);
	if (!(dest = (char *)malloc(sizeof(char) * len + 2)))
		return(NULL);
	while(str[i])
	{
		j = 0;
		while(chr[j])
		{
			if(chr[j] == str[i])
			{
				dest[k] = str[i];
				dest[k + 1] = '\0';
				return(dest);
			}
			j++;
		}
		dest[k++] = str[i++];
	}
	return(NULL);
}

/*
** Check a flag string to see and classified all the parameter in the flag 
** structure
*/

t_flag	fill_flag(t_flag flag)
{
	int i;

	i = 0;
	flag.precision = 0;
	flag.field = 0;
	flag.option = NULL;
	while (flag.parsing[i])
	{
		if (ft_chrchar(flag.parsing[i], options) == 1)
		{
			flag.option = pf_catch_option(flag.parsing, i, flag.option);
			while (ft_chrchar(flag.parsing[i], options) == 1)
				i++;
		}
		if (flag.parsing[i] >= '0' && flag.parsing[i] <= '9')
		{
			flag.field = pf_catchfield(flag.parsing, i);
			while (flag.parsing[i] >= '0' && flag.parsing[i] <= '9')
				i++;
		}	
		if (flag.parsing[i] == '.')
		{
			flag.precision = pf_catchprecision(flag.parsing, i);
			i += 1;
			while (flag.parsing[i] >= '0' && flag.parsing[i] <= '9')
				i++;
		}
		i++;
	}
	flag.flag = flag.parsing[i - 1];
	return (flag);
}
