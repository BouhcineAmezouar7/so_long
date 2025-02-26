/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/04 10:45:30 by bamezoua          #+#    #+#             */
/*   Updated: 2024/11/08 09:49:32 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t count, size_t size)
{
	char	*s;

	if (size != 0 && count > SIZE_MAX / size)
		return (NULL);
	s = (char *)malloc(count * size);
	if (s == NULL)
		return (NULL);
	ft_bzero(s, count * size);
	return (s);
}
