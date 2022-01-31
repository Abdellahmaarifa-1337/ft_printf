/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_string.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:52:17 by amaarifa          #+#    #+#             */
/*   Updated: 2021/12/04 15:56:41 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libftprintf_bonus.h"

char	*get_string(va_list args, char type)
{
	char	*temp;
	char	*res;

	if (type == 's')
		return (ft_strdup(va_arg(args, char *)));
	if (type == 'c')
		return (ft_chartostr(va_arg(args, int)));
	if (type == 'd' || type == 'i')
		return (ft_itoa(va_arg(args, int)));
	if (type == 'u')
		return (ft_itoa_u(va_arg(args, unsigned)));
	if (type == 'x')
		return (ft_itohex(va_arg(args, unsigned int), 'l'));
	if (type == 'X')
		return (ft_itohex(va_arg(args, unsigned int), 'u'));
	if (type == 'p')
	{
		temp = ft_itohex(va_arg(args, unsigned long), 'l');
		res = ft_strjoin("0x", temp);
		free(temp);
		return (res);
	}
	return (0);
}
