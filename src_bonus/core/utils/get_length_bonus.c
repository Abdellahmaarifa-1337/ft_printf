/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_length_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 12:54:41 by amaarifa          #+#    #+#             */
/*   Updated: 2021/12/04 14:21:20 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libftprintf_bonus.h"

int	get_length(char *flags)
{
	int		i;
	size_t	l;
	char	*s;

	i = 0;
	l = 0;
	if (ft_strrchr(flags, '.'))
	{
		flags = ft_strrchr(flags, '.') + 1;
		while (ft_isdigit(flags[i]))
			i++;
		s = ft_substr(flags, 0, i);
		if (!s)
			return (-1);
		l = ft_atoi(s);
		free(s);
	}
	return (l);
}
