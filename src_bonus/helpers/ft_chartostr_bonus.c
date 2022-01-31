/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_chartostr_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 12:01:55 by amaarifa          #+#    #+#             */
/*   Updated: 2021/12/03 22:40:41 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libftprintf_bonus.h"

char	*ft_chartostr(char c)
{
	char	*s;

	s = (char *)malloc(sizeof(char) * 2);
	if (!s)
		return (0);
	s[0] = c;
	s[1] = '\0';
	return (s);
}
