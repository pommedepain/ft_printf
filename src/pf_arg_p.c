/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_p.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfauvell <cfauvell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:50:14 by benjamintle       #+#    #+#             */
/*   Updated: 2019/03/29 16:01:12 by cfauvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*print_address(void *address)
{
	unsigned char	b[8];
	int				i;
	char			*to_print;
	char			*to_free;

	if ((unsigned long long)address == 0)
	{
		to_print = ft_strdups("0");
		return(to_print);
	}
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
	//free(to_free);
	return (ft_strdups(&to_print[i]));
}

char	*ft_flag_p(va_list list, t_flag flag)
{
	flag.to_print = print_address(va_arg(list, void *));
	if (flag.precision > 0)
		flag.to_print = zero_fill(flag.to_print, flag.precision);
	if (flag.precision == -1 && ft_strcmp(flag.to_print, "0") == 0)
		flag.to_print = ft_strdups("");
	flag.to_print = ft_strjoins("0x", flag.to_print);
	flag.to_print = handle_field(flag);
	return (flag.to_print);
}

