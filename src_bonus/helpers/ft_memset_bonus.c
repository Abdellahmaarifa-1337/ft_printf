/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/02 07:06:32 by amaarifa          #+#    #+#             */
/*   Updated: 2021/12/03 15:40:31 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf_bonus.h"

void	*ft_memset(void *b, int c, size_t len)
{
	size_t		i;
	char		*s;

	i = 0;
	s = (char *)b;
	while (i < len)
	{
		s[i] = c;
		i++;
	}
	return (s);
}
