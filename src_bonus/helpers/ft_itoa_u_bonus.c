/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa_u_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/03 09:15:30 by amaarifa          #+#    #+#             */
/*   Updated: 2021/12/03 15:56:08 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf_bonus.h"

static int	count_int_char(unsigned int n)
{
	unsigned int	i;

	i = 0;
	if (n < 0)
		i++;
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa_u(unsigned int n)
{
	int				s;
	char			*str;
	unsigned int	nb;

	if (n == 0)
		return (ft_strdup("0"));
	s = count_int_char(n);
	str = (char *)malloc(sizeof(char) * (s + 1));
	if (!str)
		return (0);
	str[s] = '\0';
	nb = n;
	if (n < 0)
	{
		str[0] = '-';
		nb *= -1;
	}		
	while (nb > 0)
	{
		str[s - 1] = (nb % 10) + 48;
		nb /= 10;
		s--;
	}
	return (str);
}
