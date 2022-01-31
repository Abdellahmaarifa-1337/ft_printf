/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_specification_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:49:58 by amaarifa          #+#    #+#             */
/*   Updated: 2021/12/04 16:45:02 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libftprintf_bonus.h"

static char	*protect_str(char *str)
{
	if (!str)
		return (ft_strdup("(null)"));
	return (str);
}

int	get_specification(size_t *index, const char *format, va_list args)
{
	size_t	i;
	char	*flags;
	char	*s;
	int		n;

	i = *index;
	while (!ft_strrchr("cspdiuxX%", format[i])
		&& (ft_strrchr("# +-0.", format[i]) || ft_isdigit(format[i])))
		i++;
	flags = ft_substr(format, *index, i - (*index));
	if (!ft_strrchr("cspdiuxX", format[i]))
		s = ft_chartostr(format[i]);
	else
		s = protect_str(get_string(args, format[i]));
	n = applay_flags(&s, format[i], flags);
	if (n == -1)
		return (-1);
	write(1, s, n);
	free(flags);
	*index = i + 1;
	if (s)
		free(s);
	return (n);
}
