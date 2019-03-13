/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_manage_struct.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamintle <benjamintle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 18:14:00 by benjamintle       #+#    #+#             */
/*   Updated: 2019/03/13 12:43:28 by benjamintle      ###   ########.fr       */
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
	return;
}


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
	if (!(dest = (char *)malloc(sizeof(char) * len + 1)))
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

int print_struct(t_flag flag)
{
	printf("char	*parsing; %s\n", flag.parsing);
	printf("char	*to_print; %s\n", flag.to_print);
printf("char	flag; %c\n", flag.flag);
	printf("char	*option; %s\n", flag.option);
printf("int	*precision; %d\n", flag.precision);
printf("int	*field; %d\n", flag.field);
	printf("char	*modif; %s\n", flag.modif);
	return(1);
}

t_flag	fill_flag(t_flag flag, va_list list)
{
	int i;

	i = 0;
	while (flag.parsing[i])
	{
		if (ft_chrchar(flag.parsing[i], OPTIONS) == 1)
		{
			flag.option = pf_catch_option(flag.parsing, i, flag.option);
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
	//print_struct(flag);
	return (flag);
}


void 	pf_free_struct(t_flag *flag)
{
	free(flag->parsing);
	free(flag->to_print);
	free(flag->option);
	free(flag->modif);
	return;
}
