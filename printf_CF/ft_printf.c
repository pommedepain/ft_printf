/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfauvell <cfauvell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/16 14:17:52 by cfauvell          #+#    #+#             */
/*   Updated: 2019/02/26 17:19:29 by cfauvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/*
** Main Function: initialise va_list, call reading_format and return
** result as the number of character print during the call
*/

int		ft_printf(const char *format, ...)
{
	va_list list;
	int		result;

	va_start(list, format);
	result = new_reading(format, list);
	va_end(list);
	return (result);
}

/*
** Create the output string of the function, print it on the standard output and
** return the number of charactere printed. Depend on ft_parsing for all the
** flag operations.
*/


/*int		reading_format(const char *format, va_list list)
{
	int		i;
	int		j;
	char	*final;
	char	*tmp;
	int		k;
	int		len;

	i = 0;
	j = 0;
	k = 0;
	len = ft_strclen(format, '%');
	if (!(final = (char *)malloc(sizeof(char) * len + 1)))
		return (-1);
	while (format[i])
	{
		if (format[i] == '%')
		{
			k = 0;
			tmp = ft_parsing(format, list, i, tmp);
			final = ft_strjoin(final, tmp);
			i += ft_strlen(ft_fillparsing(format, i, flags));
			j += ft_strlen(tmp +  1);
			//free(tmp);
		}
		final[j++] = format[i++];
	}
	final[j] = '\0';
	ft_putstr(final);
	i = ft_strlen(final);
	free(final);
	return (i);
}*/

/*
** Je dois parser p, f, %
*/

int		new_reading(const char *format, va_list list)
{
	int		i;
	int		j;
	int		res;
	char	*tmpf;
	int		len;
	char	*final;
	char	*tmp;
	char 	*tmp2;

	i = 0;
	final = NULL;
	res = 0;
	tmp = NULL;
	tmp2 = tmp;
	while (format[i])
	{
		j = 0;
		len = ft_strstringlen(&format[i], "%");
		if (!(tmpf = (char *)malloc(sizeof(char) * len + 1)))
			return (-1);
		tmpf[len] = '\0';
		while (format[i] != '%' && format[i])
			tmpf[j++] = format[i++];
		if (i < 13)
			final = ft_strdup(tmpf);
		else
			final = pf_strjoin(final, tmpf);
		free(tmpf);
		if (format[i] == '%')
		{
			tmp = ft_parsing(format, list, i, tmp);
			final = pf_strjoin(final, tmp);
			free(tmp);
			while (ft_chrchar(format[i - 1], flags) != 1 && format[i])
				i++;
		}
	}
	ft_putstr(final);
	res = ft_strlen(final);
	free(final);
	return (res);
}

/*
** Fonction utile de Cam = ft_strjoinfs1 (join meme si une des string est vide, et free la premiere string
** passée en parametre)
*/


int		ft_strstringlen(const char *str, char *chr)
{
	int j;
	int i;

	i = 0;
	j = 0;
	if (str && chr)
	{
		while (str[i])
		{
			j = 0;
			while (chr[j])
			{
				if (chr[j] == str[i])
					return (i);
				j++;
			}
			i++;
		}
	}
	return (0);
}
