/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/01 17:23:04 by amaarifa          #+#    #+#             */
/*   Updated: 2021/12/03 15:40:58 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf_bonus.h"

char	*ft_strrchr(const char *s, int c)
{
	int				size;
	unsigned char	*str;

	str = (unsigned char *)s;
	size = ft_strlen((const char *)str);
	while (size >= 0)
	{
		if (str[size] == (unsigned char)c)
			return ((char *)&str[size]);
		size--;
	}
	return (0);
}
