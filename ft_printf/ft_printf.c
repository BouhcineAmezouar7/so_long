/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:38:38 by bamezoua          #+#    #+#             */
/*   Updated: 2024/11/16 09:43:04 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	pcas(void *p)
{
	int	count;

	count = 0;
	count += ft_pustr("0x");
	count += ft_adress((unsigned long)p);
	return (count);
}

static int	boss(char str, va_list arg)
{
	int	count;

	count = 0;
	if (str == 'd' || str == 'i')
		count += ft_putnbr(va_arg(arg, int));
	else if (str == 'u')
		count += ft_printu(va_arg(arg, unsigned int));
	else if (str == 's')
		count += ft_pustr(va_arg(arg, char *));
	else if (str == 'c')
		count += ft_putchar(va_arg(arg, int));
	else if (str == 'x' || str == 'X')
		count += ft_convert(va_arg(arg, unsigned int), str);
	else if (str == 'p')
		count += pcas(va_arg(arg, void *));
	else if (str == '%')
		count += ft_putchar('%');
	return (count);
}

int	ft_printf(const char *str, ...)
{
	va_list	arg;
	int		i;
	int		count;

	i = 0;
	count = 0;
	if (write(1, 0, 0) == -1)
		return (-1);
	va_start(arg, str);
	while (str[i])
	{
		if (str[i] == '%' && ft_strchr("diusxcXp%", str[i + 1]))
		{
			i++;
			if (str[i] != '\0')
				count += boss(str[i], arg);
		}
		else
		{
			count += ft_putchar(str[i]);
		}
		i++;
	}
	va_end(arg);
	return (count);
}
