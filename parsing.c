/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: cajulien <cajulien@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/01 12:02:58 by cajulien          #+#    #+#             */
/*   Updated: 2019/02/01 18:16:38 by cajulien         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"



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
	while (str[i] && !is_spec(str[i], SPECSET))
		i++;
	return (i);
}

static void		process_arg(t_data *data)
{
	int		i;
	int		j;
	char	*tmp;

	if (data->arg[0] != '%')
		return ;
	data->narg = 1;
	i = 1;
	tmp = data->arg;
	while(tmp[i] && is_spec(tmp[i], OPTSET))
		i++;		
	data->flags->opt = ft_strsub(tmp, 1, i);
	j = i;
	while(tmp[i] && is_spec(tmp[i], WIDTHSET))
		i++;
	data->flags->width = ft_strsub(tmp, j, i);
	j = i;
	while(tmp[i] && is_spec(tmp[i], PRECSET))
		i++;
	tmp[i - 1] == '*' ? data->narg += 1 : 0;
	data->flags->prec = ft_strsub(tmp, j, i);
	while(tmp[i] && is_spec(tmp[i], LENGTHSET))
		i++;
	tmp[i - 1] == '*' ? data->narg += 1 : 0;	
	data->flags->length = ft_strsub(tmp, j, i);
}

static int		doublepercent(char *str, int i, t_data *current)
{
	char	*tmp;
	int		ret;

	tmp = ft_strsub(&str[i], 0, 1);
	current->nstr = ft_strjoinfs1(current->nstr, tmp);
	free(tmp);
	i += 2;
	ret = next_str(&str[i]);
	tmp = ft_strsub(&str[i], 0, ret);
	current->nstr = ft_strjoinfs1(current->nstr, tmp);
	free(tmp);
	i += ret;
	return (i);
}

void			parse(char *str, t_data **data)
{
		int		i;
		int		ret;
		t_data	*current;

		if (!data || !*data)
			return ;
		current = *data;
		i = 0;
		while (str[i])
		{
			ret = next_str(&str[i]);
			current->nstr = ft_strsub(&str[i], 0, ret);
			i += ret;
			while (str[i + 1] == '%')
				i = doublepercent(str, i, current);
			ret = next_arg(&str[i]);
			current->arg = ft_strsub(&str[i], 0, ret + 1);
			i += ret + 1;
			process_arg(current);
			if (str[i])
			{
				current->next = create_elem(current);
				current = current->next;
			}
		}
}
