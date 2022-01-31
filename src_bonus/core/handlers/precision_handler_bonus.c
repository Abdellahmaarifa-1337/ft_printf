/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   precision_handler_bonus.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:12:20 by amaarifa          #+#    #+#             */
/*   Updated: 2021/12/04 14:21:38 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libftprintf_bonus.h"

static int	precision_decimal(char **str, size_t l)
{
	char	*s;
	int		i;
	char	*temp;

	i = 0;
	s = (char *)malloc(l - ft_strlen(*str) + 1);
	s[l - ft_strlen(*str)] = '\0';
	temp = ft_strjoin(ft_memset(s, '0', l - ft_strlen(*str)), *str);
	if (!temp)
		return (-1);
	free(s);
	free(*str);
	*str = temp;
	if (ft_strrchr(*str, '-'))
	{
		while ((*str)[i] != '-')
			i++;
		(*str)[i] = '0';
		(*str)[0] = '-';
	}
	return (1);
}

int	precision_handler(char **str, char type, char *flags)
{
	size_t	l;
	char	*temp;

	l = get_length(flags);
	if (type == 's')
	{
		temp = ft_substr(*str, 0, l);
		free(*str);
		*str = temp;
	}
	if (l == 0 && (*str)[0] == '0' && ft_strlen(*str))
		(*str)[0] = '\0';
	if (ft_strrchr(*str, '-'))
		l++;
	if (ft_strrchr("diuxX", type) && (int)(l - ft_strlen(*str)) > 0)
		if (precision_decimal(str, l) == -1)
			return (-1);
	return (l);
}
