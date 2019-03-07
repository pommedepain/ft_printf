/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_adress.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/07 13:58:22 by cajulien          #+#    #+#             */
/*   Updated: 2019/03/07 15:36:43 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "address.h"

char	*bytes_to_str(unsigned char b[8])
{
	int		i;
	char	*hex;
	char	*str;

	hex = HEX;
	i = 0;
	if (!(str = (char *)malloc(sizeof(char) * 19)))
		return NULL;
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
	unsigned char b[8];
	int		i;
	int		size;
	char	*to_print;
	char	*to_free;

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
