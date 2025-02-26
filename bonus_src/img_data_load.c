/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   img_data_load.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/19 11:12:03 by bamezoua          #+#    #+#             */
/*   Updated: 2025/01/20 09:50:24 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	error_imgs_found(t_data *data)
{
	ft_printf("Error\n img Not found\n");
	free_all_leaks(data);
}

void	img_data(t_data *data)
{
	int	img_width;
	int	img_height;

	img_width = 32;
	img_height = 32;
	data->box_img = mlx_xpm_file_to_image(data->mlx, "./textures/box.xpm",
			&img_width, &img_height);
	data->player_img = mlx_xpm_file_to_image(data->mlx, "./textures/deno.xpm",
			&img_width, &img_height);
	data->coin_img = mlx_xpm_file_to_image(data->mlx, "./textures/coin.xpm",
			&img_width, &img_height);
	data->close_exit_img = mlx_xpm_file_to_image(data->mlx,
			"./textures/exit_close.xpm", &img_width, &img_height);
	data->open_exit_img = mlx_xpm_file_to_image(data->mlx,
			"./textures/exit_open.xpm", &img_width, &img_height);
	data->enemy_img = mlx_xpm_file_to_image(data->mlx, "./textures/enemy.xpm",
			&img_width, &img_height);
	data->background_img = mlx_xpm_file_to_image(data->mlx,
			"./textures/background.xpm", &img_width, &img_height);
	if (!data->box_img || !data->player_img || !data->enemy_img
		|| !data->coin_img || !data->close_exit_img || !data->open_exit_img
		|| !data->background_img)
		error_imgs_found(data);
}
