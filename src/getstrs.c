/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   getstrs.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nexus <nexus@student.42.fr>                +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/02 16:16:14 by rphuyal           #+#    #+#             */
/*   Updated: 2022/11/21 00:22:06 by nexus            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../ft_printf.h"

static int	get_int_len(long n)
{
	int	len;

	len = 0;
	if (n <= 0)
		len++;
	while (n)
	{
		len++;
		n = n / 10;
	}
	return (len);
}

static int	get_hex_len(unsigned long long n)
{
	int	len;

	len = 0;
	while (n > 0)
	{
		n /= 16;
		len++;
	}
	return (len);
}

char	*ft_gethexstr(unsigned long long num, char *base)
{
	char	*str;
	int		i;
	int		base_len;

	i = 0;
	base_len = 0;
	while (base[base_len])
		base_len++;
	str = malloc(sizeof(char) * get_hex_len(num) + 1);
	while (num > 0)
	{
		str[i++] = base[num % base_len];
		num /= base_len;
	}
	str[i] = '\0';
	return (ft_strrev(str));
}

char	*ft_getintstr(long n)
{
	char	*arr;
	int		len;
	long	i;

	len = get_int_len(n);
	i = n;
	arr = (char *)malloc(sizeof(char) * len + 1);
	if (!arr)
		return (NULL);
	*(arr + len) = '\0';
	if (i == 0)
		arr[0] = '0';
	else if (i < 0)
	{
		arr[0] = '-';
		i *= -1;
	}
	while (i)
	{
		arr[len - 1] = i % 10 + 48;
		len--;
		i = i / 10;
	}
	return (arr);
}
