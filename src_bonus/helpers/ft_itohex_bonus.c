/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itohex_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/23 16:31:22 by amaarifa          #+#    #+#             */
/*   Updated: 2021/12/04 16:46:10 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf_bonus.h"

int	calc_nb_size(unsigned long nb_decimal)
{
	unsigned long	size;

	size = 0;
	if (nb_decimal <= 0)
	{
		size++;
		nb_decimal = nb_decimal * -1;
	}
	while (nb_decimal != 0)
	{
		nb_decimal = nb_decimal / 16;
		size++;
	}
	return (size);
}

void	ft_putnbr_base(unsigned long nb, char *base, char *s, int index)
{
	unsigned long		res;

	if (nb < 0)
	{
		res = nb * -1;
		s[index] = '-';
		index++;
	}
	else
		res = nb;
	if (res >= 16)
	{
		ft_putnbr_base(res / 16, base, s, index + 1);
		s[index] = base[res % 16];
		index++;
	}
	else
	{
		s[index] = base[res];
		index++;
	}
}

void	str_revers(char	*s)
{
	int		i;
	int		j;
	int		max;
	char	temp;

	i = 0;
	while (s[i])
		i++;
	j = 0;
	if (s[0] == '-')
		j = 1;
	max = (i - j) / 2;
	while (max > 0)
	{
		temp = s[i - 1];
		s[i - 1] = s[j];
		s[j] = temp;
		i--;
		j++;
		max--;
	}
}

char	*ft_itohex(unsigned long nbr, char type)
{
	unsigned long	size;
	char			*s;

	size = calc_nb_size(nbr);
	s = (char *)malloc(sizeof(char) * (size + 1));
	if (!s)
		return (0);
	if (type == 'l')
		ft_putnbr_base(nbr, "0123456789abcdef", s, 0);
	else
		ft_putnbr_base(nbr, "0123456789ABCDEF", s, 0);
	s[size] = '\0';
	str_revers(s);
	return (s);
}
