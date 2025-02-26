/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keypress_bonus.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:19:46 by bamezoua          #+#    #+#             */
/*   Updated: 2025/01/15 15:43:55 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	close_window(t_data *data)
{
	free_all_leaks(data);
	return (0);
}

int	update_player_position(t_data *data, int new_x, int new_y, int keycode)
{
	data->map[data->player_y][data->player_x] = '0';
	data->map[new_y][new_x] = 'P';
	data->player_x = new_x;
	data->player_y = new_y;
	if (keycode == XK_a || keycode == XK_w || keycode == XK_s
		|| keycode == XK_d)
	{
		data->move_count++;
		ft_printf("Move count: %d\n", data->move_count);
	}
	mlx_clear_window(data->mlx, data->mlx_win);
	render_map(data);
	display_movement_count(data);
	display_movement_alpha(data);
	return (0);
}

int	check_exit(t_data *data)
{
	if (data->coins == data->total_coins)
	{
		ft_printf("All coins collected! Exiting game...\n");
		free_all_leaks(data);
		return (1);
	}
	return (0);
}

int	handle_map_interactions(t_data *data, int new_x, int new_y)
{
	if (data->map[new_y][new_x] == 'C')
	{
		data->coins++;
		data->map[new_y][new_x] = '0';
		ft_printf("Collected %d/%d coins\n", data->coins, data->total_coins);
	}
	if (data->map[new_y][new_x] == 'E')
	{
		if (check_exit(data) == 0)
		{
			ft_printf("Error\n Take all collected! and Exiting game...\n");
			return (0);
		}
	}
	if (data->map[new_y][new_x] == 'N')
	{
		ft_printf("Error\n You are losing the Game! Exiting game...\n");
		free_all_leaks(data);
	}
	return (1);
}

int	handle_keypress(int keycode, void *param)
{
	t_data	*data;
	int		new_x;
	int		new_y;

	data = (t_data *)param;
	new_x = data->player_x;
	new_y = data->player_y;
	if (keycode == XK_Escape)
		close_window(data);
	if (keycode == XK_a)
		new_x--;
	else if (keycode == XK_w)
		new_y--;
	else if (keycode == XK_d)
		new_x++;
	else if (keycode == XK_s)
		new_y++;
	if (new_x < 0 || new_y < 0 || !data->map[new_y] || !data->map[new_y][new_x])
		return (0);
	if (data->map[new_y][new_x] == '1')
		return (0);
	if (!handle_map_interactions(data, new_x, new_y))
		return (0);
	return (update_player_position(data, new_x, new_y, keycode));
}
