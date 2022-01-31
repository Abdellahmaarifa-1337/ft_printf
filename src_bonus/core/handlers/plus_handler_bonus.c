/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   plus_handler_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:20:23 by amaarifa          #+#    #+#             */
/*   Updated: 2021/12/03 18:54:32 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libftprintf_bonus.h"

int	plus_handler(char **str, char type)
{
	char	*temp;

	temp = NULL;
	if (ft_atoi(*str) >= 0
		&& ft_strrchr("di", type)
		&& ft_isdigit((*str)[0]))
	{
		temp = ft_strjoin("+", *str);
		if (!temp)
			return (-1);
		free(*str);
		*str = temp;
	}
	return (1);
}
