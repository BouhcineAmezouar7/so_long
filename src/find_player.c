/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:10:10 by bamezoua          #+#    #+#             */
/*   Updated: 2025/01/14 10:41:39 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	player_not_found(t_data *data)
{
	ft_printf("Error\n Player's starting position ('P') not found in map.\n");
	free_all_leaks(data);
}

void	find_initial_player_position(t_data *data)
{
	int	y;
	int	found;
	int	x;

	y = 0;
	found = 0;
	while (data->map[y] && !found)
	{
		x = 0;
		while (data->map[y][x])
		{
			if (data->map[y][x] == 'P')
			{
				data->player_x = x;
				data->player_y = y;
				found = 1;
				break ;
			}
			x++;
		}
		y++;
	}
	if (!found)
		player_not_found(data);
}
