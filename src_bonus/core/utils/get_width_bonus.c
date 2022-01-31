/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_width_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:37:46 by amaarifa          #+#    #+#             */
/*   Updated: 2021/12/04 10:55:37 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libftprintf_bonus.h"

size_t	get_width(char *flags)
{
	size_t		i;
	size_t		start;
	size_t		width;
	char		*temp;

	i = 0;
	start = 0;
	width = 0;
	while (flags[i] && flags[i] != '.')
	{
		if (ft_isdigit(flags[i]) && flags[i] != '0')
		{
			start = i;
			while (ft_isdigit(flags[i]))
				i++;
			temp = ft_substr(flags, start, i - start + 1);
			width = ft_atoi(temp);
			free(temp);
			break ;
		}
		i++;
	}
	return (width);
}
