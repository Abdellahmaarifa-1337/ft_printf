/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf_bonus.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amaarifa <amaarifa@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 08:46:49 by amaarifa          #+#    #+#             */
/*   Updated: 2021/12/04 15:57:09 by amaarifa         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_BONUS_H
# define LIBFTPRINTF_BONUS_H
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
int		precision_handler(char **str, char type, char *flags);
int		plus_handler(char **str, char type);
int		hash_handler(char **str, char type);
int		width_handler(char **str, char *flags, size_t width, char type);
char	*ft_strjoin(char const *s1, char const *s2);
void	*ft_memmove(void *dst, const void *src, size_t len);
void	*ft_memset(void *b, int c, size_t len);
int		space_handler(char **str, size_t str_len, size_t length, char *flags);
size_t	get_width(char *flags);
char	*ft_strdup(const char	*src);
int		get_length(char *flags);
int		get_specification(size_t *index, const char *format, va_list args);
char	*get_string(va_list args, char type);
int		applay_flags(char **s, char type, char *flags);
int		process_str(char *flags, char type, char **str);
#endif