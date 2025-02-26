/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fused.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-12 09:39:28 by bamezoua          #+#    #+#             */
/*   Updated: 2024-11-12 09:39:28 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putchar(int c)
{
	write(1, &c, 1);
	return (1);
}

char	*ft_strchr(const char *s, int c)
{
	size_t	i;
	char	b;
	char	*str;

	str = (char *)s;
	b = (char)c;
	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == b)
			return (&str[i]);
		i++;
	}
	if (b == '\0')
		return (&str[i]);
	return (NULL);
}

int	ft_pustr(char *str)
{
	int	l;
	int	i;

	if (str == NULL)
		str = "(null)";
	l = 0;
	i = 0;
	while (str[i] != '\0')
	{
		l += write(1, &str[i], 1);
		i++;
	}
	return (l);
}

int	ft_putnbr(int nb)
{
	int	nb2;
	int	l;

	nb2 = 0;
	l = 0;
	if (nb == -2147483648)
	{
		l += write(1, "-2147483648", 11);
	}
	else
	{
		if (nb < 0)
		{
			ft_putchar('-');
			nb = nb * -1;
			l++;
		}
		if (nb >= 10)
		{
			l += ft_putnbr(nb / 10);
		}
		nb2 = nb % 10 + '0';
		l += write(1, &nb2, 1);
	}
	return (l);
}

int	ft_printu(unsigned int nb)
{
	unsigned int	nb2;
	int				l;

	l = 0;
	nb2 = 0;
	if (nb >= 10)
	{
		l += ft_putnbr(nb / 10);
	}
	nb2 = nb % 10 + '0';
	l += write(1, &nb2, 1);
	return (l);
}
