/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_manage_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfauvell <cfauvell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:14:00 by benjamintle       #+#    #+#             */
/*   Updated: 2019/04/03 14:43:59 by cfauvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	pf_init_struct(t_flag *flag)
{
	flag->parsing = NULL;
	flag->to_print = NULL;
	flag->flag = '\0';
	flag->option = NULL;
	flag->precision = 0;
	flag->field = 0;
	flag->modif = NULL;
}

char	*ft_fillparsing(const char *str, int i, char *chr)
{
	int		j;
	char	*dest;
	int		k;

	k = 0;
	if (ft_chrstring(&str[i], FLAGS) != 1)
		return (NULL);
	dest = init_pars(str, i);
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
	free(dest);
	return (NULL);
}

int		print_struct(t_flag flag)
{
	printf("char	*parsing; %s\n", flag.parsing);
	printf("char	*to_print; %s\n", flag.to_print);
	printf("char	flag; %c\n", flag.flag);
	printf("char	*option; %s\n", flag.option);
	printf("int	*precision; %d\n", flag.precision);
	printf("int	*field; %d\n", flag.field);
	printf("char	*modif; %s\n", flag.modif);
	return (1);
}

t_flag	fill_flag(t_flag flag, va_list list)
{
	int i;

	i = 0;
	while (flag.parsing[i])
	{
		if (ft_chrchar(flag.parsing[i], OPTIONS) == 1)
		{
			if (flag.option != NULL)
				flag.option = ft_strjoin(flag.option, pf_catch_option(flag.parsing, i, flag.option));
			else
				flag.option = pf_catch_option(flag.parsing, i, flag.option);
			while (ft_chrchar(flag.parsing[i + 1], OPTIONS) == 1)
				i++;
		}
		if ((flag.parsing[i] > '0' && flag.parsing[i] <= '9') || flag.parsing[i] == '*')
		{
			flag.field = pf_catch_field(flag.parsing, i, list);
			while ((flag.parsing[i + 1] >= '0' && flag.parsing[i + 1] <= '9') || flag.parsing[i + 1] == '*')
				i++;
		}
		if (flag.parsing[i] == '.')
		{
			flag.precision = pf_catch_precision(flag.parsing, i, list);
			i += 1;
			while ((flag.parsing[i + 1] >= '0' && flag.parsing[i + 1] <= '9') || flag.parsing[i + 1] == '*')
				i++;
		}
		if (ft_chrchar(flag.parsing[i], "lLhzj") == 1)
		{
			flag.modif = pf_catch_modifier(flag.parsing, i, flag.modif);
			while (ft_chrchar(flag.parsing[i + 1], "lLhzj") == 1)
				i++;
		}
		i++;
	}
	flag.flag = flag.parsing[i - 1];
	return (flag);
}

void	pf_free_struct(t_flag *flag)
{
	free(flag->parsing);
	free(flag->to_print);
	free(flag->option);
	free(flag->modif);
}
