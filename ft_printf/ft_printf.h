/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/12 09:53:23 by bamezoua          #+#    #+#             */
/*   Updated: 2024/11/16 10:07:16 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int		ft_putchar(int c);
int		ft_putnbr(int nb);
int		ft_pustr(char *str);
int		ft_printf(const char *str, ...);
int		ft_convert(unsigned int n, const char s);
int		ft_adress(unsigned long c);
int		ft_printu(unsigned int nb);
char	*ft_strchr(const char *s, int c);

#endif
