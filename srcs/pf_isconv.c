/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pf_isconv.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: benjamin <benjamin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/30 15:45:09 by benjamin          #+#    #+#             */
/*   Updated: 2019/01/30 15:51:04 by benjamintle      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int pf_isconv(char c)
{
	if (c == 'c' || c == 's' || c == 'p' || c == 'd' || c == 'i' ||
		c == 'o' || c == 'u' || c == 'x' || c == 'X')
		return(1);
	return(0);
}
