/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rphuyal <rphuyal@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/21 18:22:43 by rphuyal           #+#    #+#             */
/*   Updated: 2022/11/21 18:22:46 by rphuyal          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static char	*print_pointer(unsigned long long num, int *flength)
{
	char	*str;

	str = NULL;
	if (num == 0)
		*flength += ft_putstr("(nil)");
	else
	{
		*flength += ft_putstr("0x");
		str = ft_gethexstr(num, HEXMIN);
	}
	return (str);
}

static void	print_conversions(char c, va_list args_ptr, int *flength)
{
	char	*str;

	str = NULL;
	if (c == 'c')
		*flength += ft_putchar(va_arg(args_ptr, int));
	else if (c == 's')
		*flength += ft_putstr(va_arg(args_ptr, char *));
	else if (c == 'p')
		str = print_pointer(va_arg(args_ptr, unsigned long long), flength);
	else if (c == 'd' || c == 'i')
		str = ft_getintstr(va_arg(args_ptr, int));
	else if (c == 'u')
		str = ft_getintstr(va_arg(args_ptr, unsigned int));
	else if (c == 'x')
		str = ft_gethexstr(va_arg(args_ptr, unsigned int), HEXMIN);
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
		if (*str == '%' && *(str++))
		{
			print_conversions(*str, args_ptr, &flenght);
		}
		else
			flenght += ft_putchar(*str);
		str++;
	}
	va_end(args_ptr);
	return (flenght);
}

/*
int main(void)
{
	printf("%x\n", INT_MAX);
	ft_printf("%x\n", INT_MAX);

	printf("%s\n", "dfgdf");
	ft_printf("%s\n", "dfgdf");

	printf(" %p ", 16);
	ft_printf(" %p ", 16);
	
	printf("%p\n", '0');
	ft_printf("%p\n", '0');

	//printf("NULL %s NULL\n", NULL);
	//ft_printf("NULL %s NULL\n", NULL);

	printf(" %x ", 16);
	ft_printf(" %x ", 16);
}
*/
