/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 13:41:31 by cajulien          #+#    #+#             */
/*   Updated: 2019/03/06 17:06:18 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "struct.h"

t_flags 	process_flag(char *str)
{
	t_flags		flags;
	int		i;

	i = 0;

	return(flags);
}

int			next_str(char *str, char **buffer)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (str[i])
	{
		if (str[i] == '%' && str[i + 1] != '%')
		{
			*buffer = ft_strsub(str, 0, i);
			return (i);
		}
		else if (str[i] == '%' && str[i + 1] == '%')
		{
			*buffer = ft_strsub(str, 0, i);
			i++;
		}
		else if (str[i] == '\\')
		{

		}
		else
			i++;
	}
	return (i);
}

int			next_arg(char *str, char **buffer)
{
	int		i;

	i = 0;
	while (str[i])
	{
		
	}
	return (i);
}

int			*parser(char *str, t_arg *link)
{
	int		ret;
	int		i;
	char	*tmp;

	i = 0;
	tmp = NULL;
	while (str[i])
	{
		ret = next_str(&str[i], &tmp);
		link->nstr = ft_strdups(tmp);
		free(tmp);
		i += ret;
		tmp = next_arg(&str[i], &tmp);
		link->flags = process_flag(tmp);
		free(tmp);
		i += ret;
		str[i] ? link->next = create_elem(link) : 0;
	}
	return (1);
}

t_arg		**init(char *str)
{
	t_arg	**list;
	t_arg	*first;

	if (str == NULL)
		return (NULL);
	if (!(first = create_elem(NULL)))
		return (NULL);
	list = &first;
	if(!ft_parse(str, first))
	{
		free_list(list);
		return(NULL);
	}	
	return (list);
}
