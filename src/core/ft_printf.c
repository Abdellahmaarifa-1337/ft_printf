/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 08:49:23 by amaarifa          #+#    #+#             */
/*   Updated: 2021/12/04 17:52:21 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf.h"

static char	*get_string(va_list args, char type)
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

static char	*protect_str(char *str)
{
	if (!str)
		return (ft_strdup("(null)"));
	return (str);
}

static int	get_specification(size_t *index, const char *format, va_list args)
{
	size_t	i;
	char	*s;
	int		n;

	i = *index;
	n = 0;
	while (!ft_strrchr("cspdiuxX%", format[i]))
		i++;
	if (!ft_strrchr("cspdiuxX", format[i]))
		s = ft_chartostr(format[i]);
	else
		s = protect_str(get_string(args, format[i]));
	if (s && !s[0] && format[i] == 'c')
		n = 1;
	else if (s)
		n = ft_strlen(s);
	write(1, s, n);
	*index = i + 1;
	if (s)
		free(s);
	return (n);
}

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
