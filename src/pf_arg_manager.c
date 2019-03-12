/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamintle <benjamintle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:20:18 by cfauvell          #+#    #+#             */
/*   Updated: 2019/03/12 16:15:47 by benjamintle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Duplicate the "%   " part of format in a separate string (with the call of
** ft_fillparsing)
** Fill the structure flag, with all the informations organized in order to help
** for the conversion (with the call of fill_flag)
*/

int		ft_parsing(const char *format, int *i, va_list list)
{
	t_flag	flag;
	int		res;

	res = 0;
	flag.parsing = NULL;
	flag.to_print = NULL;
	*i += 1;
	flag.parsing = ft_fillparsing(format, *i, FLAGS);
	if (flag.parsing == NULL)
		return (0);
	//il faut *i s'incremente jusqu'au prochain % (voir les undefined behavior
	// tests). 
	flag = fill_flag(flag, list);
	// Il reste a gerer: l'option #, les modifieurs: il manque 
	// l'integration de ll pour les conversions non signée.
	//  d est le plus avancé. Il faut aussi gerer un argument 0 pour
	// c et p. Apres dans les tests, il y a des trucs hyper chelou genre
	// j, z, U, O, D... (present surtout dans le moulitest) mais alors
	// la c'est mystery et les floats MDRRRRs
	flag.flag == 'c' ? flag.to_print = ft_flag_c(list, flag) : 0;
	flag.flag == 's' ? flag.to_print = ft_flag_s(list, flag) : 0;
	flag.flag == 'p' ? flag.to_print = ft_flag_p(list, flag) : 0;
	(flag.flag == 'd' || flag.flag == 'i') ?
	flag.to_print = ft_flag_d(list, flag) : 0;
	flag.flag == 'o' ? flag.to_print = ft_flag_o(list, flag) : 0;
	flag.flag == 'u' ? flag.to_print = ft_flag_u(list, flag) : 0;
	flag.flag == 'x' ? flag.to_print = ft_flag_x(list, flag) : 0;
	flag.flag == 'X' ? flag.to_print = ft_flag_X(list, flag) : 0;
	flag.flag == '%' ? flag.to_print = ft_flag_per(flag) : 0;
/*		flag.to_print = ft_flag_s(list, flag);
	if (flag.flag == 'p')
		flag.to_print = ft_flag_p(list, flag);
	if (flag.flag == 'd' || flag.flag == 'i')
		flag.to_print = ft_flag_d(list, flag);
	if (flag.flag == 'o')
		flag.to_print = ft_flag_o(list, flag);
	if (flag.flag == 'u')
		flag.to_print = ft_flag_u(list, flag);
	if (flag.flag == 'x')
		flag.to_print = ft_flag_x(list, flag);
	if (flag.flag == 'X')
		flag.to_print = ft_flag_X(list, flag);
	if (flag.flag == '%')
		flag.to_print = ft_flag_per(flag);
	// J'ai vu aucune trace de Z nul part sauf dans les undefined behavior
	//  tests, ecrit comme ça, ça repond aux tests.
	if (flag.flag == 'Z')
		flag.to_print = "Z";
		*/
	*i += ft_strlen(flag.parsing);
	free(flag.parsing);
	free(flag.option);
	free(flag.modif);
	ft_putstr(flag.to_print);
	res = ft_strlen(flag.to_print);
	//free flag.to_print ici fait bugger bcp de test...
	return (res);
}

/*
** Duplicate the format string until a conversion specifier appears
** (Create a "flag string")
*/

char	*ft_fillparsing(const char *str, int i, char *chr)
{
	int		j;
	char	*dest;
	int		k;
	int		len;

	j = 0;
	k = 0;
	if (ft_chrstring(&str[i], FLAGS) != 1)
		return (NULL);
	len = ft_strstringlen(&str[i], FLAGS);
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
** Check a flag string to see and organize all of the parameters
** in the flag structure
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
		if (ft_chrchar(flag.parsing[i], OPTIONS) == 1)
		{
			flag.option = pf_catch_option(flag.parsing, i, flag.option);
			while (ft_chrchar(flag.parsing[i], OPTIONS) == 1)
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
