/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move_player_alpha_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/13 12:01:03 by bamezoua          #+#    #+#             */
/*   Updated: 2025/01/20 09:51:19 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_alpha_path(t_data *data, t_alpha_path *alpha, int i)
{
	alpha->number_img = ft_itoa(i);
	if (!alpha->number_img)
		free_all_leaks(data);
	alpha->plus_xpm = ft_strjoin(alpha->number_img, ".xpm");
	if (!alpha->plus_xpm)
	{
		free(alpha->number_img);
		free_all_leaks(data);
	}
	alpha->file_path = ft_strjoin("./textures/alpha/", alpha->plus_xpm);
	if (!alpha->file_path)
	{
		free(alpha->plus_xpm);
		free_all_leaks(data);
	}
	data->alpha_img[i] = mlx_xpm_file_to_image(data->mlx, alpha->file_path,
			&alpha->width_img, &alpha->height_img);
	if (!data->alpha_img[i])
	{
		free(alpha->file_path);
		free(alpha->plus_xpm);
		free(alpha->number_img);
		free_all_leaks(data);
	}
}

void	alpha_img_path(t_data *data, t_alpha_path *alpha)
{
	int	i;
	int	max;

	i = 0;
	max = 26;
	alpha->width_img = 8;
	alpha->height_img = 16;
	while (i < max)
	{
		check_alpha_path(data, alpha, i);
		free(alpha->file_path);
		free(alpha->plus_xpm);
		free(alpha->number_img);
		i++;
	}
}

void	move_alpha_to_img(t_data *data)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = "moves";
	while (str[i] != '\0')
	{
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->alpha_img[str[i]
			- 'a'], 7 + j, 7);
		if (!data->alpha_img[i])
			free_all_leaks(data);
		j += 16;
		i++;
	}
}

void	free_alpha_imgs(t_data *data)
{
	int	i;

	i = 0;
	while (i < 26)
	{
		if (data->alpha_img[i])
		{
			mlx_destroy_image(data->mlx, data->alpha_img[i]);
			data->alpha_img[i] = NULL;
		}
		i++;
	}
}

void	display_movement_alpha(t_data *data)
{
	move_alpha_to_img(data);
}
