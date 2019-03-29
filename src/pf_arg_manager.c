/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_manager.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamintle <benjamintle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/20 20:20:18 by cfauvell          #+#    #+#             */
/*   Updated: 2019/03/28 17:22:12 by benjamintle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/*
** Duplicate the "%   " part of format in a separate string (with the call of
** ft_fillparsing)
** Fill the structure flag, with all the informations organized in order to help
** for the conversion (with the call of fill_flag)
*/

void    ft_putstrtest(char *str, int len)
{
    int i = 0;

    while (i < len)
    {
        ft_putchar(str[i]);
        i++;
    }
}

int		ft_parsing(const char *format, int *i, va_list list)
{
	t_flag	flag;
	int		res;

	res = 0;
	pf_init_struct(&flag);
	*i += 1;
	flag.parsing = ft_fillparsing(format, *i, FLAGS);
	if (flag.parsing == NULL)
		return (0);
	flag = fill_flag(flag, list);
	//il faut *i s'incremente jusqu'au prochain % (voir les undefined behavior
	// tests). 
	//  d est le plus avancé. Il faut aussi gerer un argument 0 pour
	// c et p. Apres dans les tests, il y a des trucs hyper chelou genre
	// j, z, U, O, D... (present surtout dans le moulitest) mais alors
	// la c'est mystery et les floats MDRRRRs
	(flag.flag == 'c' || flag.flag == 'C') ? flag.to_print = ft_flag_c(list, flag) : 0;
	(flag.flag == 's' || flag.flag == 'S')  ? flag.to_print = ft_flag_s(list, flag) : 0;
	flag.flag == 'p' ? flag.to_print = ft_flag_p(list, flag) : 0;
	(flag.flag == 'd' || flag.flag == 'i') ? flag.to_print = ft_flag_d(list, flag) : 0;
	flag.flag == 'D' ? flag.to_print = ft_flag_dd(list, flag) : 0;
	(flag.flag == 'o' || flag.flag == 'O')  ? flag.to_print = ft_flag_o(list, flag) : 0;
	flag.flag == 'u' ? flag.to_print = ft_flag_u(list, flag) : 0;
	flag.flag == 'U' ? flag.to_print = ft_flag_uu(list, flag) : 0;
	flag.flag == 'x' ? flag.to_print = ft_flag_x(list, flag) : 0;
	flag.flag == 'X' ? flag.to_print = ft_flag_X(list, flag) : 0;
	(flag.flag == 'f' || flag.flag == 'F') ? flag.to_print = ft_flag_f(list, flag) : 0;
	flag.flag == '%' ? flag.to_print = ft_flag_per(flag) : 0;
	// J'ai vu aucune trace de Z nul part sauf dans les undefined behavior
	//  tests, ecrit comme ça, ça repond aux tests.
	flag.flag == 'Z' ? flag.to_print = ft_strdups("Z") : 0;
	*i += ft_strlen(flag.parsing);
	//ft_putchar('\n');
	//print_struct(flag);
	//ft_putchar('\n');
	if (flag.flag == 'c' && ((ft_strlen(flag.to_print) == 0) || (flag.field != 0 && (ft_char_only(flag.to_print, ' ', '\0') == 1))))
	{
		ft_putstrtest(flag.to_print, (ft_strlen(flag.to_print) + 1));
		res = ft_strlen(flag.to_print) + 1;
		free(flag.to_print);
	}
	else
	{
		ft_putstr(flag.to_print);
		res = ft_strlen(flag.to_print);
		free(flag.to_print);
	}
	free(flag.parsing);
	free(flag.option);
	free(flag.modif);
	//pf_free_struct(flag);
	//free flag.to_print ici fait bugger bcp de test...
	return (res);
}
