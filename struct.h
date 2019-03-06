/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 13:45:20 by cajulien          #+#    #+#             */
/*   Updated: 2019/03/06 16:41:42 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "libftprintf.h"
# include "stdlib.h"
# define SPECSET "cspdiouxXfegbrk"
# define OPTSET "-+0# "
# define WIDTHSET "0123456789*"
# define PRECSET ".0123456789*"
# define LENGTHSET "hlL"

typedef struct		s_flags
{
	char			*option;
	char			*width;
	char			*precision;
	char			*length;
	char			*spec;
	char			*color;
}					t_flags;

typedef struct		s_arg
{
	char			*nstr;
	t_flags			flags;
	char			*processed;
	struct s_arg	*next;
}					t_arg;

t_arg				*create_elem(t_arg *link);
void				free_link(t_arg	*link);
void				free_list(t_arg **list);
t_arg				**init(char *str);
#endif
