/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   conversion_util.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfauvell <cfauvell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 15:09:53 by cfauvell          #+#    #+#             */
/*   Updated: 2019/03/12 04:11:30 by cfauvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

char	*zero_fill(char *str, int i)
{
	char	*res;
	int		j;
	int		k;
	int		ibis;

	j = ft_strlen(str);
	k = 0;
	ibis = 0;
	if (i > (j - 1))
	{
		if (ft_chrchar(str[0], "-+ ") == 1)
		{
			ibis = 1;
			k = 1;
			j = ft_strlen(str);
			res = (char *)malloc(sizeof(char) * (i + 2));
			res[i + 1] = '\0';
			res[0] = str[0];
			while (i-- > (j - 1))
				res[k++] = '0';
		}
		else
		{
			res = (char *)malloc(sizeof(char) * (i + 1));
			res[i] = '\0';
			while (i-- > j)
				res[k++] = '0';
		}
		while (j-- > 0)
			res[k++] = str[ibis++];
		free(str);
		return (res);
	}
	return (str);
}

char	*zero_fill_l(char *str, int i)
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
			while (--i > j)
				res[k++] = '0';
		}
		else
		{
			res = (char *)malloc(sizeof(char) * (i + 1));
			res[i] = '\0';
			while (i-- > j)
				res[k++] = '0';
		}
		while (j-- > 0)
			res[k++] = str[ibis++];
		// dans l'etat free(str) peut entrainer des segfaults, je l'ai donc mis en 
		// commentaire
		//free(str);
		return (res);
	}
	return (str);
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
	while (i-- > j)
		res[k++] = ' ';
	while (j-- > 0)
		res[k++] = str[ibis++];
	return (res);
}

char	*space_fill_r(char *str, int i)
{
	char	*res;
	int		j;
	int		k;
	int		len;

	len = ft_strlen(str);
	k = 0;
	j = 0;
	res = (char *)malloc(sizeof(char) * (i + 1));
	res[i] = '\0';
	while (len-- > 0)
		res[j++] = str[k++];
	i -= j;
	while (i-- > 0)
		res[j++] = ' ';
	return (res);
}

char	*precision_string(char *str, int i)
{
	char	*res;
	int		j;
	int		k;

	k = 0;
	j = 0;
	if (!(res = (char *)malloc(sizeof(char) * i + 1)))
		return (NULL);
	res[i] = '\0';
	while (i-- > 0)
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
	if (ft_chrstring(str, "-") == 1)
		return (str);
	if (!(res = (char *)malloc(sizeof(char) * len + 2)))
		return (0);
	res[len + 1] = '\0';
	if (ft_chrstring(option, "+") == 1)
		res[0] = '+';
	if (ft_chrstring(option, " ") == 1 && ft_chrstring(option, "+") != 1)
		res[0] = ' ';
	while (str[i])
		res[j++] = str[i++];
	free(str);
	return (res);
}

char	*bytes_to_str(unsigned char b[8])
{
	int		i;
	char	*hex;
	char	*str;

	hex = HEX;
	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * 19)))
		return (NULL);
	while (i < 8)
	{
		str[2 * i + 1] = hex[((int)b[i] % 16)];
		b[i] /= 16;
		str[2 * i] = hex[((int)b[i] % 16)];
		i++;
	}
	str[16] = '\0';
	return (str);
}

char	*print_address(void *address)
{
	unsigned char	b[8];
	int				i;
	char			*to_print;
	char			*to_free;

	i = 0;
	while (i < 8)
	{
		b[i] = ((unsigned long)address >> (56 - 8 * i)) & B1;
		i++;
	}
	to_print = bytes_to_str(b);
	i = 0;
	while (to_print[i] == 48)
		i++;
	to_free = to_print;
	to_print = ft_strjoins("0x", &to_print[i]);
	free(to_free);
	return (to_print);
}

int		ft_numlen(unsigned long long int value, int base)
{
	int		i;

	i = 1;
	while (value >= (unsigned long long)base)
	{
		value /= base;
		i++;
	}
	return (i);
}

char	*ft_lltoa_base(long long value, int base)
{
	int						i;
	unsigned long long		nbr;
	int						size;
	char					*to_print;

	if (value < 0)
		nbr = value * -1;
	else
		nbr = value;
	size = ft_numlen(nbr, base);
	(base == 10 && value < 0) ? size++ : 0;
	if (!(to_print = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = size;
	while (i--)
	{
		to_print[i] = BASE[nbr % base];
		nbr /= base;
	}
	(base == 10 && value < 0) ? to_print[0] = '-' : 0;
	to_print[size] = '\0';
	return (to_print);
}

char	*ft_ulltoa_base(unsigned long long value, int base)
{
	int						i;
	int						size;
	char					*to_print;

	size = ft_numlen(value, base);
	if (!(to_print = (char *)malloc(sizeof(char) * (size + 1))))
		return (NULL);
	i = size;
	while (i--)
	{
		to_print[i] = BASE[value % base];
		value /= base;
	}
	to_print[size] = '\0';
	return (to_print);
}
