/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   applay_flags_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:51:29 by amaarifa          #+#    #+#             */
/*   Updated: 2021/12/04 16:40:18 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libftprintf_bonus.h"

int	applay_flags(char **s, char type, char *flags)
{
	int	n;
	int	i;

	i = 0;
	n = 0;
	if (type == 'c' && *s && !(*s)[0])
	{
		*s[0] = 1;
		if (!(*s) || !flags || (process_str(flags, type, s) == -1))
			return (-1);
		n = ft_strlen(*s);
		while ((*s)[i] != 1)
			i++;
		(*s)[i] = 0;
	}
	else if (n == -1 || !(*s) || !flags
		|| (process_str(flags, type, s) == -1))
		return (-1);
	else
		n = ft_strlen(*s);
	return (n);
}
