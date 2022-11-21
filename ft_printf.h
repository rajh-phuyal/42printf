/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42lisboa.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:10:24 by rphuyal           #+#    #+#             */
/*   Updated: 2022/11/21 15:35:50 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# define HEXMIN "0123456789abcdef"
# define HEXMAX "0123456789ABCDEF"
# define DECIMAL "0123456789"

# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>
# include <stdarg.h>
# include <limits.h>

int		ft_putchar(char c);
int		ft_strlen(const char *str);
int		get_hex_len(unsigned long long n);
int		get_int_len(long n);
int		ft_printf(const char *str, ...);
char	*ft_getintstr(long n);
char	*ft_gethexstr(unsigned long long num, char *base);
int		ft_putstr(char *str);
char	*ft_strchr(const char *str, int c);
char	*ft_strrev(char *str);

#endif