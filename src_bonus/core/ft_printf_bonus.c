/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 08:49:23 by amaarifa          #+#    #+#             */
/*   Updated: 2021/12/04 15:53:49 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf_bonus.h"

int	ft_printf(const char *format, ...)
{
	va_list		args;
	size_t		i;
	size_t		size;
	int			len;

	size = 0;
	i = 0;
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			i++;
			len = get_specification(&i, format, args);
			if (len == -1)
				return (0);
			size += len;
			continue ;
		}
		else
			size += write(1, format + i, 1);
		i++;
	}
	va_end(args);
	return (size);
}
