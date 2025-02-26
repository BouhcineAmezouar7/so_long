/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/14 13:03:30 by bamezoua          #+#    #+#             */
/*   Updated: 2025/01/15 10:45:33 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	duplicated_map(t_data *data, char **cpy_map)
{
	int	i;

	i = 0;
	while (i < data->height)
	{
		cpy_map[i] = malloc(data->width + 1);
		if (!cpy_map[i])
		{
			perror("Error\n Failed to allocate memory for cpy_map row");
			ft_free_cpy_map(cpy_map, i - 1);
			free_all_leaks(data);
			return ;
		}
		ft_memset(cpy_map[i], 'W', data->width);
		cpy_map[i][data->width] = '\0';
		i++;
	}
}

void	flood_fill(t_data *data, char **cpy_map, int player_x, int player_y)
{
	if (player_x < 0 || player_y < 0 || player_y >= data->height
		|| player_x >= (int)ft_strlen(data->map[player_y]))
		return ;
	if (data->map[player_y][player_x] == '1'
		|| cpy_map[player_y][player_x] == 'V')
		return ;
	if (data->map[player_y][player_x] == 'E'
		&& data->coins != data->total_coins)
	{
		cpy_map[player_y][player_x] = 'V';
		return ;
	}
	cpy_map[player_y][player_x] = 'V';
	flood_fill(data, cpy_map, player_x - 1, player_y);
	flood_fill(data, cpy_map, player_x + 1, player_y);
	flood_fill(data, cpy_map, player_x, player_y - 1);
	flood_fill(data, cpy_map, player_x, player_y + 1);
}

void	check_condition(t_data *data, int x, int y, char **cpy_map)
{
	if (x >= 0 && x < (int)ft_strlen(data->map[y]) && y >= 0
		&& y < data->height)
	{
		if (data->map[y][x] == 'C' && cpy_map[y][x] != 'V')
		{
			ft_printf("Error\n Collectible at (%d, %d) is unreachable\n", x, y);
			ft_free_cpy_map(cpy_map, data->height - 1);
			free_all_leaks(data);
		}
		if (data->map[y][x] == 'E' && cpy_map[y][x] != 'V')
		{
			ft_printf("Error\n Exit at (%d, %d) is unreachable\n", x, y);
			ft_free_cpy_map(cpy_map, data->height - 1);
			free_all_leaks(data);
		}
	}
}

void	check_flood_fill(t_data *data, char **cpy_map)
{
	int	y;
	int	x;

	y = 0;
	flood_fill(data, cpy_map, data->player_x, data->player_y);
	while (y < data->height)
	{
		x = 0;
		while (x < data->width)
		{
			check_condition(data, x, y, cpy_map);
			x++;
		}
		y++;
	}
}
