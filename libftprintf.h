/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:36:29 by pommedepin        #+#    #+#             */
/*   Updated: 2019/01/24 17:22:20 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h> // permet l'accès à va_list, va_arg, va_end & va_start

typedef struct				s_printf
{
	char					*normstr;
	char					*spestr;
}							t_printf;

#endif
