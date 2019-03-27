/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_arg_per.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/12 14:50:04 by benjamintle       #+#    #+#             */
/*   Updated: 2019/03/26 14:59:00 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_flag_per(t_flag flag)
{
	flag.to_print = ft_strdups("%");
	flag.to_print = handle_field(flag);
	return (flag.to_print);
}
