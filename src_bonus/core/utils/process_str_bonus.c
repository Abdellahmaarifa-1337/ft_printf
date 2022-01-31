/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_str_bonus.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/04 15:54:08 by amaarifa          #+#    #+#             */
/*   Updated: 2021/12/04 16:37:12 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../../libftprintf_bonus.h"

int	process_str(char *flags, char type, char **str)
{
	size_t	width;
	size_t	str_len;
	int		n;

	str_len = ft_strlen(*str);
	width = get_width(flags);
	n = 1;
	if (ft_strrchr(flags, '.'))
		n = precision_handler(str, type, flags);
	if (ft_strrchr(flags, '+'))
		n = (plus_handler(str, type));
	if (ft_strrchr(flags, '#'))
		n = (hash_handler(str, type));
	if (width > ft_strlen(*str))
		n = (width_handler(str, flags, width, type));
	if (ft_strrchr(flags, ' ') && ft_strrchr("dui", type))
		n = (space_handler(str, str_len, get_length(flags), flags));
	return (n);
}
