/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pommedepin <pommedepin@student.42.fr>      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/20 16:28:14 by cajulien          #+#    #+#             */
/*   Updated: 2019/03/23 12:25:50 by pommedepin       ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <string.h>
# include <stdlib.h>
# include <unistd.h>

# define BUFF_SIZE 42

typedef struct	s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}				t_list;

void			*ft_memset(void *s, int c, size_t n);
void			ft_bzero(void *s, size_t n);
void			*ft_memcpy(void *dest, const void *src, size_t	n);
void			*ft_memccpy(void *dest, const void *src, int c, size_t n);
void			*ft_memmove(void *dst, const void *src, size_t len);
void			*ft_memchr(const void *s, int c, size_t n);
int				ft_memcmp(const void *s1, const void *s2, size_t n);
size_t			ft_strlen(const char *s);
char			*ft_strdup(const char *s1);
char			*ft_strcpy(char *dst, const char *src);
char			*ft_strncpy(char *dst, const char *src, size_t len);
char			*ft_strcat(char *s1, const char *s2);
char			*ft_strncat(char *s1, const char *s2, size_t n);
size_t			ft_strlcat(char *dst, const char *src, size_t size);
char			*ft_strchr(const char *s, int c);
char			*ft_strrchr(const char *s, int c);
char			*ft_strstr(const char *haystack, const char *needle);
char			*ft_strnstr(const char *haystack, const char *needle,
size_t len);
int				ft_strcmp(const char *s1, const char *s2);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
int				ft_atoi(const char *str);
int				ft_isalpha(int c);
int				ft_isdigit(int c);
int				ft_isalnum(int c);
int				ft_isascii(int c);
int				ft_isprint(int c);
int				ft_toupper(int c);
int				ft_tolower(int c);
void			*ft_memalloc(size_t size);
void			ft_memdel(void **ap);
char			*ft_strnew(size_t size);
void			ft_strdel(char **as);
void			ft_strclr(char *s);
void			ft_striter(char *s, void (*f)(char *));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
char			*ft_strmap(char const *s, char (*f)(char));
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int				ft_strequ(char const *s1, char const *s2);
int				ft_strnequ(char const *s1, char const *s2, size_t n);
char			*ft_strsub(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s);
char			**ft_strsplit(char const *s, char c);
char			*ft_itoa(int n);
void			ft_putchar(char c);
void			ft_putstr(char const *s);
void			ft_putendl(char const *s);
void			ft_putnbr(int n);
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char const *s, int fd);
void			ft_putendl_fd(char const *s, int fd);
void			ft_putnbr_fd(int n, int fd);
t_list			*ft_lstnew(void const *content, size_t content_size);
void			ft_lstdelone(t_list **alst, void (*del)(void *, size_t));
void			ft_lstdel(t_list **alst, void (*del)(void *, size_t));
void			ft_lstadd(t_list **alst, t_list *new);
void			ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list			*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));





/*
** Projet ft_printf :
*/

# include <stdarg.h>
# include <stdio.h>
# include "wchar.h"

# define UINT_MAX 4294967296
# define FLAGS "cspdiouxX%fZ"
# define OPTIONS "#0-+ "
# define B1 0x0000000000FF
# define _X_ "0123456789ABCDEF"
# define _x_ "0123456789abcdef"

typedef	struct	s_flag
{
	char	*parsing;
	char	*to_print;
	char	flag;
	char	*option;
	int		precision;
	int		field;
	char	*modif;
}				t_flag;

/*
** ft_printf.c
*/

int				ft_printf(const char *format, ...);
			//__attribute__((format(printf, 1, 2)));
int				reading_format(const char *format, va_list list);
int				ft_strstringlen(const char *str, char *chr);
int				new_reading(const char *format, va_list list);
int				pf_manager(const char *format, va_list ap);
int				pf_str_manager(const char *str, int *pos);

/*
** parsing.c
*/

int				ft_parsing(const char *format, int *i, va_list list);
t_flag			fill_flag(t_flag flag, va_list list);
char 			*ft_fillparsing(const char *str, int i, char *chr);

/*
** parsing_util.c
*/

int				pf_catchprecision(char *str, int i, va_list list);
int				pf_catchfield(char *str, int i, va_list list);
char			*pf_catch_option(char *str, int i, char *res);
char			*pf_catchmodifier(char *str, int i, char *res);

/*
** conversion.c
*/

char			*ft_flag_c(va_list list, t_flag flag);
char			*ft_flag_s(va_list list, t_flag flag);
char			*ft_flag_d(va_list list, t_flag flag);
char			*ft_flag_u(va_list list, t_flag flag);
char			*ft_flag_o(va_list list, t_flag flag);
char			*ft_flag_x(va_list list, t_flag flag);
char			*ft_flag_X(va_list list, t_flag flag);
char			*ft_flag_p(va_list list, t_flag flag);
char			*ft_flag_per(t_flag flag);
char			*handle_field(t_flag flag);

/*
** conversion_util.c
*/

char			*zero_fill(char *str, int i);
char			*space_fill_l(char *str, int i);
char			*space_fill_r(char *str, int i);
char			*precision_string(char *str, int i);
char			*add_sign(char *str, char *option);
char			*print_address(void *address);
char			*bytes_to_str(unsigned char b[8]);
int				ft_numlen(unsigned long long int value, int base_size);
char			*ft_lltoa_base(long long value, int base_size, char *base);
char			*ft_ulltoa_base(unsigned long long value, int base_size, char *base);
char			*zero_fill_l(char *str, int i);
int				ft_char_only(char *str, char c, char d);
char			*add_hashtag(char *str, char *add);

/*
** util.c
*/

char 			*ft_ltoa_base_2(long value, int base);
char 			*ft_ltoa_base(long value, int base);
char			*ft_ltoa(long n);
char			*pf_strjoin(char const *s1, char const *s2);
//int			ft_size(int n);
void			pf_init_struct(t_flag *flag);
void			pf_fill_struct(t_flag *flag);
void			pf_free_struct(t_flag *flag);
int 			print_struct(t_flag flag);
int 			pf_fill_option(t_flag *flag, int *i);
int 			pf_fill_field(t_flag *flag, int *i, va_list list);


/*
** Amélioration de la libft de base :
*/


char			*ft_convert_base(char *nbr, char *base_from, char *base_to);
char			*ft_no_whitespaces(char *str);
int				ft_strcmps(const char *s1, const char *s2);
char			*ft_strjoins(char const *s1, char const *s2);
char			*ft_strchrs(const char *s, int c);
char			*ft_strdups(const char *s1);
size_t			ft_strlens(const char *s);
char			*ft_strjoinfs1(char *s1, char *s2);
char			*ft_strjoinfs2(char *s1, char *s2);
void			ft_print_words_tables(char **tab);
long			ft_digit_len(int n);
void			ft_letter_count(char **split, char *s, char c);
void			ft_tab_filling(char **split, char *s, char c);
void			ft_tabdel(char **as);
int				ft_word_count(char *s, char c);
int				get_next_line(const int fd, char **line);
char			*ft_strtrimc(char const *s, char c);
size_t			ft_strcountsplit(const char *s, char c);
size_t			ft_strclen(const char *s, char c);
char			**ft_tabcpy(char **dst, char **src);
char			*ft_strndup(const char *s1, size_t n);
size_t			ft_strnlen(const char *s, size_t maxlen);
int				ft_chrstring(const char *str, char *chr);
int				ft_chrchar(char c, char *chr);

#endif