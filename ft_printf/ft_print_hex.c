/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_hex.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:39:14 by bamezoua          #+#    #+#             */
/*   Updated: 2024/11/16 10:04:28 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_adress(unsigned long c)
{
	int				l;
	unsigned int	num;
	char			*str;

	l = 0;
	num = 0;
	str = "0123456789abcdef";
	if (c >= 16)
	{
		l += ft_adress(c / 16);
	}
	num = c % 16;
	write(1, &str[num], 1);
	return (l + 1);
}

int	ft_convert(unsigned int n, const char s)
{
	int				l;
	unsigned int	num;
	char			c;

	l = 0;
	num = 0;
	if (n >= 16)
		l += ft_convert(n / 16, s);
	num = n % 16;
	c = "0123456789abcdef"[num];
	if (s == 'X' && c >= 'a' && c <= 'z')
		c -= 32;
	write(1, &c, 1);
	return (l + 1);
}
