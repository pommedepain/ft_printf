/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   address.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 13:45:20 by cajulien          #+#    #+#             */
/*   Updated: 2019/03/07 15:20:01 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ADDRESS_H
# define ADDRESS_H
# include "libft/libft.h"
# include <stdio.h>
# define B1 0x0000000000FF
# define HEX "0123456789abcdef"

char	*print_address(void *address);
#endif
