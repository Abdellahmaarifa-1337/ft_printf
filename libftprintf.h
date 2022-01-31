/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 08:46:49 by amaarifa          #+#    #+#             */
/*   Updated: 2021/12/04 14:38:59 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H
# include <stdlib.h>
# include <stdarg.h>
# include <unistd.h>

int		ft_printf(const char *format, ...);
char	*ft_itoa_u(unsigned int n);
char	*ft_itoa(int n);
int		ft_isdigit(int c);
size_t	ft_strlen(const char *s);
char	*ft_strrchr(const char *s, int c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	*ft_itohex(unsigned long nbr, char type);
char	*ft_chartostr(char c);
int		ft_atoi(const char	*str);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_strdup(const char	*src);
#endif