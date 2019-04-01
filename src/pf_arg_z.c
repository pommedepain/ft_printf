/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_z.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfauvell <cfauvell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/01 12:17:43 by cfauvell          #+#    #+#             */
/*   Updated: 2019/04/01 12:29:26 by cfauvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_flag_z(t_flag flag)
{
	flag.to_print = ft_strdups("Z");
	flag.to_print = handle_field(flag);
	return (flag.to_print);
}
