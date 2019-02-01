/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:36:29 by pommedepin        #+#    #+#             */
/*   Updated: 2019/02/01 13:46:06 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h> // permet l'accès à va_list, va_arg, va_end & va_start

# define FLAGSET "cspdiouxXfegbrk"

typedef	struct				s_flags
{
	char					*opt;
	char					*width;
	char					*prec;
	char					*length;
	char					spec;
}							t_flags;

typedef struct 				s_data
{
	char					*nstr;
	char					*arg;
	t_flags					*flags;
	struct s_data			*next;
}							t_data;

typedef struct				s_printf
{
	char					*normstr;
	char					*spestr;
}							t_printf;

void    					parse(char *str, t_data **data);
t_data      				*create_elem(t_data *data);
void						show_data(t_data **data);
void						free_data(t_data **data);
#endif
