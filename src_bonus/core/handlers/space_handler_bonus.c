/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   space_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:34:03 by amaarifa          #+#    #+#             */
/*   Updated: 2021/12/03 17:37:58 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libftprintf_bonus.h"

int	space_handler(char **str, size_t str_len, size_t length, char *flags)
{
	size_t	width;
	char	*temp;

	width = get_width(flags);
	if ((*str)[0] != '-' && (*str)[0] != '+')
	{
		if (width > str_len && (length == 0 || width > length))
		{
			if (ft_strrchr(flags, '-'))
			{
				ft_memmove(*str + 1, *str, ft_strlen(*str) - 1);
				(*str)[0] = ' ';
			}
		}
		else
		{
			temp = ft_strjoin(" ", *str);
			if (!temp)
				return (-1);
			free(*str);
			*str = temp;
		}
	}
	return (1);
}
