/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   width_handler_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:26:26 by amaarifa          #+#    #+#             */
/*   Updated: 2021/12/04 10:55:28 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libftprintf_bonus.h"

static int	is_flag_zero(char *flags)
{
	int	i;

	i = 0;
	while (flags[i])
	{
		if (flags[i] == '0')
			return (1);
		else if (ft_isdigit(flags[i]) || flags[i] == '.')
			break ;
		i++;
	}
	return (0);
}

static void	switch_sign(char **str)
{
	int	i;

	i = 0;
	while ((*str)[i])
	{
		if ((*str)[i] == '+' || (*str)[i] == '-')
			break ;
		i++;
	}
	(*str)[0] = (*str)[i];
	(*str)[i] = '0';
}

static int	padding_left(char *s, char **str, char *flags, char type)
{
	int		i;
	char	*temp;

	temp = ft_strjoin(s, *str);
	if (!temp)
		return (-1);
	free(*str);
	*str = temp;
	if (ft_strrchr(flags, '#') && is_flag_zero(flags)
		&& !ft_strrchr(flags, '.'))
	{
		i = 0;
		while ((*str)[i] != type)
			i++;
		(*str)[i] = '0';
		(*str)[0] = '0';
		(*str)[1] = type;
	}
	if ((ft_strrchr(*str, '+') || ft_strrchr(*str, '-')) && is_flag_zero(flags))
		switch_sign(str);
	return (1);
}

int	width_handler(char **str, char *flags, size_t width, char type)
{
	char	*s;
	int		n;
	char	*temp;

	n = 1;
	s = (char *)malloc(width - ft_strlen(*str) + 1);
	if (!s)
		return (-1);
	s[width - ft_strlen(*str)] = '\0';
	if (is_flag_zero(flags) && ft_strrchr("diuxX", type)
		&& !ft_strrchr(flags, '.') && !ft_strrchr(flags, '-'))
		ft_memset(s, '0', width - ft_strlen(*str));
	else
		ft_memset(s, ' ', width - ft_strlen(*str));
	if (ft_strrchr(flags, '-'))
	{
		temp = ft_strjoin(*str, s);
		free(*str);
		*str = temp;
	}
	else
		n = (padding_left(s, str, flags, type));
	free(s);
	return (n);
}
