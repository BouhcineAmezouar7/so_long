/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_all_leaks_bonus.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:02:46 by bamezoua          #+#    #+#             */
/*   Updated: 2025/01/14 15:52:02 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	free_map(char **map)
{
	int	i;

	i = 0;
	if (map)
	{
		while (map[i])
		{
			free(map[i]);
			i++;
		}
		free(map);
	}
}

void	ft_free_cpy_map(char **cpy_map, int i)
{
	if (!cpy_map)
		return ;
	while (i >= 0)
	{
		free(cpy_map[i]);
		cpy_map[i] = NULL;
		i--;
	}
	free(cpy_map);
}

void	free_img(t_data *data)
{
	if (data->player_img)
		mlx_destroy_image(data->mlx, data->player_img);
	if (data->box_img)
		mlx_destroy_image(data->mlx, data->box_img);
	if (data->coin_img)
		mlx_destroy_image(data->mlx, data->coin_img);
	if (data->close_exit_img)
		mlx_destroy_image(data->mlx, data->close_exit_img);
	if (data->enemy_img)
		mlx_destroy_image(data->mlx, data->enemy_img);
	if (data->background_img)
		mlx_destroy_image(data->mlx, data->background_img);
	if (data->open_exit_img)
		mlx_destroy_image(data->mlx, data->open_exit_img);
}

void	free_all_leaks(t_data *data)
{
	free_count_imgs(data);
	free_alpha_imgs(data);
	if (data)
	{
		if (data->map)
			free_map(data->map);
		if (data->mlx)
		{
			free_img(data);
			if (data->mlx_win)
				mlx_destroy_window(data->mlx, data->mlx_win);
			mlx_destroy_display(data->mlx);
			free(data->mlx);
		}
	}
	exit(0);
}
