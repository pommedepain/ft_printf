/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cfauvell <cfauvell@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/15 16:00:17 by cfauvell          #+#    #+#             */
/*   Updated: 2019/03/07 12:58:15 by cfauvell         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include "../libft/libft.h"
# include <stdarg.h>

# define UINT_MAX 4294967296
# define flags "cspdiouxXf"
# define options "#0-+ "

typedef	struct		s_flag
{
	char	*parsing;
	char	*to_print;
	char	flag;
	char	*option;
	int		precision;
	int		field;
	char	modif;
}					t_flag;

/*
typedef struct			s_flags{

	char	*arg;
	char	*to_print;
	char	*options;
	char    *width;
	char	*precision;
	char	lenght;
	char	spec;
}						t_flags;
*/

/*
** ft_printf.c
*/

int		ft_printf(const char *format, ...)
			__attribute__((format(printf, 1, 2)));
int		reading_format(const char *format, va_list list);
int		ft_strstringlen(const char *str, char *chr);
int		new_reading(const char *format, va_list list);
int		pf_manager(const char *format, va_list ap);
int		pf_str_manager(const char *str, int *pos);

/*
** parsing.c
*/

int		ft_parsing(const char *format, int *i, va_list list);
t_flag	fill_flag(t_flag flag);
char 	*ft_fillparsing(const char *str, int i, char *chr);

/*
** parsing_util.c
*/

int		ft_chrstring(const char *str, char *chr);
int		ft_chrchar(char c, char *chr);
int		pf_catchprecision(char *str, int i);
int		pf_catchfield(char *str, int i);
char	*pf_catch_option(char *str, int i, char *res);

/*
** conversion.c
*/

char	*ft_flag_c(va_list list, char *tmp);
char	*ft_flag_s(va_list list, char *tmp);
char	*ft_flag_d(va_list list, char *tmp);
char	*ft_flag_u(va_list list, char *tmp);
char	*ft_flag_o(va_list list, char *tmp);
char	*ft_flag_x(va_list list, char *tmp);
char	*ft_flag_X(va_list list, char *tmp);

/*
** conversion_util.c
*/

char	*zero_fill(char *str, int i);
char	*space_fill_l(char *str, int i);
char	*space_fill_r(char *str, int i);
char	*precision_string(char *str, int i);
char	*add_sign(char *str, char *option);

/*
** util.c
*/

char 	*ft_ltoa_base_2(long value, int base);
char 	*ft_ltoa_base(long value, int base);
char	*ft_ltoa(long n);
char	*pf_strjoin(char const *s1, char const *s2);
//int		ft_size(int n);

#endif
