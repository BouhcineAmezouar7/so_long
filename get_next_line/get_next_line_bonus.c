/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          #+#  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024-11-19 10:39:51 by bamezoua          #+#    #+#             */
/*   Updated: 2024-11-19 10:39:51 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

static char	*join_free(char *stock, char *buffer)
{
	char	*temp;

	temp = ft_strjoin(stock, buffer);
	free(stock);
	stock = NULL;
	return (temp);
}

static char	*ft_join(char *stock, int fd)
{
	char	*buffer;
	ssize_t	bytes_read;

	if (!stock)
		stock = ft_strdup("");
	buffer = malloc((size_t)BUFFER_SIZE + 1);
	if (buffer == NULL)
		return (NULL);
	bytes_read = 1;
	while (bytes_read > 0)
	{
		bytes_read = read(fd, buffer, BUFFER_SIZE);
		if (bytes_read == -1)
		{
			free(stock);
			free(buffer);
			return (NULL);
		}
		buffer[bytes_read] = '\0';
		stock = join_free(stock, buffer);
		if (ft_strchr(buffer, '\n'))
			break ;
	}
	free(buffer);
	return (stock);
}

void	freetemp(char *temp)
{
	if (temp[0] == '\0')
	{
		free(temp);
		temp = NULL;
	}
}

char	*free_if_empty(char *temp)
{
	if (temp && temp[0] == '\0')
	{
		free(temp);
		temp = NULL;
	}
	return (temp);
}

char	*get_next_line(int fd)
{
	static char	*stock[1024];
	char		*res;
	char		*temp;
	int			i;

	i = 0;
	if (BUFFER_SIZE <= 0 || fd < 0 || fd >= 1024)
		return (NULL);
	stock[fd] = ft_join(stock[fd], fd);
	if (stock[fd] == NULL || stock[fd][0] == '\0')
	{
		free(stock[fd]);
		stock[fd] = NULL;
		return (NULL);
	}
	while (stock[fd][i] && stock[fd][i] != '\n')
		i++;
	res = ft_substr(stock[fd], 0, i + 1);
	temp = ft_substr(stock[fd], i + 1, ft_strlen(stock[fd]) - i + 1);
	free(stock[fd]);
	stock[fd] = NULL;
	stock[fd] = free_if_empty(temp);
	return (res);
}
