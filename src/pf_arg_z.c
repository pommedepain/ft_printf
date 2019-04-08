/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psentilh <psentilh@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
<<<<<<< HEAD
/*   Created: 2019/04/05 17:19:58 by psentilh          #+#    #+#             */
/*   Updated: 2019/04/05 17:20:00 by psentilh         ###   ########.fr       */
=======
/*   Created: 2019/04/01 12:17:43 by cfauvell          #+#    #+#             */
/*   Updated: 2019/04/04 18:08:00 by cfauvell         ###   ########.fr       */
>>>>>>> 823be3ea2500ffc238a7eca15f5d0eb744346400
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_flag_other(t_flag flag)
{
	char	*tmp;

	if (!(tmp = (char *)malloc(sizeof(char) * 2)))
		return (NULL);
	tmp[0] = flag.flag;
	tmp[1] = '\0';
	flag.to_print = ft_strdups(tmp);
	flag.to_print = handle_field(flag);
	free(tmp);
	return (flag.to_print);
}
