/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamintle <benjamintle@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/04 14:45:02 by btollie           #+#    #+#             */
/*   Updated: 2019/03/06 20:54:06 by benjamintle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef FT_PRINTF_H
#define FT_PRINTF_H

/*
** Includes
*/

#include "libft.h"
#include <stdarg.h>
#include <stdio.h>

/*
** 	| 0 | 1 | 2 | 3 | 4 | 5 | 6 | 7 | 8 | 9 | 10 | 11 | 12 |
** 	|pre|wid| # | 0 | - | + |   | hh| h | ll|  l |  j |  z |
*/


/*
** Structures
*/

#define BUFF_SIZE 5

typedef struct			s_flags{

	char	*arg;
	char	*to_print;
	char	*options;
	char    *width;
	char	*precision;
	char	lenght;
	char	spec;
}						t_flags;


int 		ft_printf(const char *restrict format, ... );
int			pf_manager(char *str, va_list ap);

int			pf_arg_manager(char *str, int *pos);
int			pf_str_manager(char *str, int *pos);

void		pf_initstruct(t_flags *init);
int 		pf_issize(char c);
int 		pf_isflag(char c);
int			pf_isconv(char c);


#endif
