/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/24 15:36:29 by pommedepin        #+#    #+#             */
/*   Updated: 2019/02/01 18:40:06 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include "libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h> // permet l'accès à va_list, va_arg, va_end & va_start

# define SPECSET "cspdiouxXfegbrk"
# define OPTSET "-+0# "
# define WIDTHSET "0123456789*"
# define PRECSET ".0123456789*"
# define LENGTHSET "hlL"

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
	int						narg;
	char					*nstr;
	t_flags					*flags;
	struct s_data			*next;
}							t_data;


void    					parse(char *str, t_data **data);
t_data      				*create_elem(t_data *data);
void						show_data(t_data **data);
void						free_data(t_data **data);
char						is_spec(char c, char *charset);
#endif
