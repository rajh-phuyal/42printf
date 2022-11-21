/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nexus <nexus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/11 13:09:49 by rphuyal           #+#    #+#             */
/*   Updated: 2022/11/21 00:15:36 by nexus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static void	print_conversions(char c, va_list args_ptr, int *flength)
{
	char	*str;

	str = NULL;
	if (c == 'c')
		*flength += ft_putchar(va_arg(args_ptr, int));
	else if (c == 's')
		*flength += ft_putstr(va_arg(args_ptr, char *));
	else if (c == 'p')
	{
		*flength += write(1, "0x", 2);
		str = ft_gethexstr(va_arg(args_ptr, unsigned long long), HEXMIN);
	}
	else if (c == 'd' || c == 'i')
		str = ft_getintstr(va_arg(args_ptr, int));
	else if (c == 'u')
		str = ft_getintstr(va_arg(args_ptr, unsigned int));
	else if (c == 'x')
		str = ft_gethexstr(va_arg(args_ptr, unsigned int), HEXMAX);
	else if (c == 'X')
		str = ft_gethexstr(va_arg(args_ptr, unsigned int), HEXMAX);
	else if (c == '%')
		*flength += write(1, "%", 1);
	if (str)
		*flength += ft_putstr(str);
}

int	ft_printf(const char *str, ...)
{
	va_list	args_ptr;
	int		flenght;

	va_start(args_ptr, str);
	flenght = 0;
	while (*str)
	{
		if (*str == '%')
			print_conversions(*str, args_ptr, &flenght);
		else
			flenght += ft_putchar(*str);
		str++;
	}
	va_end(args_ptr);
	return (flenght);
}
