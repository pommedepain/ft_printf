/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   struct.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 13:45:20 by cajulien          #+#    #+#             */
/*   Updated: 2019/03/06 14:23:23 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STRUCT_H
# define STRUCT_H
# include "libftprintf.h"
# include "stdlib.h"

typedef struct		s_flags
{
	char			*option;
	char			*width;
	char			*precision;
	char			*length;
	char			*spec;
}					t_flags;

typedef struct		s_arg
{
	char			*nstr;
	t_flags			flags;
	struct s_arg	*next;
}					t_arg;

#endif
