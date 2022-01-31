/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_handler_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:24:30 by amaarifa          #+#    #+#             */
/*   Updated: 2021/12/03 17:06:41 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libftprintf_bonus.h"

int	hash_handler(char **str, char type)
{
	char	*temp;

	temp = NULL;
	if (type == 'x' && (*str)[0] != '0')
	{
		temp = ft_strjoin("0x", *str);
		if (!temp)
			return (-1);
		free(*str);
		*str = temp;
	}
	else if (type == 'X' && (*str)[0] != '0')
	{
		temp = ft_strjoin("0X", *str);
		if (!temp)
			return (-1);
		free(*str);
		*str = temp;
	}
	return (1);
}
