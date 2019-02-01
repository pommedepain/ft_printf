/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:02:58 by cajulien          #+#    #+#             */
/*   Updated: 2019/02/01 14:25:44 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static int		is_spec(char c)
{
	char	*str;
	int		i;

	str = FLAGSET;
	i = 0;
	while (str[i])
	{
		if (c == str[i])
			return (1);
		i++;
	}
	return (0);
}

static int		next_str(char *str)
{
	int		i;

	i = 0;
	while (str[i] && str[i] != '%')
		i++;
	return (i);
}

static int		next_arg(char *str)
{
	int		i;

	i = 0;
	while (str[i] && !is_spec(str[i]))
		i++;
	return (i);
}

static t_flags	*process_arg(char *arg)
{
	(void)arg;
	return (NULL);
}

void			parse(char *str, t_data **data)
{
		int		i;
		int		ret;
		t_data	*current;
		char	*tmp;

		if (!data || !*data)
			return ;
		current = *data;
		i = 0;
		
		while (str[i])
		{
			ret = next_str(&str[i]);
			current->nstr = ft_strsub(&str[i], 0, ret);
			i += ret;
			if (str[i + 1] == '%')
			{
				tmp = ft_strsub(&str[i++], 0, 1);
				current->nstr = ft_strjoinfs1(current->nstr, tmp);
				free(tmp);
			}
			ret = next_arg(&str[i]);
			current->arg = ft_strsub(&str[i], 0, ret);
			i += ret;
			current->flags = process_arg(current->arg);
			if (str[i])
			{
				current->next = create_elem(current);
				current = current->next;
			}
		}
}