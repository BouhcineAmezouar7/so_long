/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   display_move_player_count_bonus.c                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 08:51:45 by bamezoua          #+#    #+#             */
/*   Updated: 2025/01/20 09:51:26 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	check_count_path(t_data *data, t_count_path *alpha, int i)
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
	alpha->file_path = ft_strjoin("./textures/count/", alpha->plus_xpm);
	if (!alpha->file_path)
	{
		free(alpha->plus_xpm);
		free_all_leaks(data);
	}
	data->count_img[i] = mlx_xpm_file_to_image(data->mlx, alpha->file_path,
			&alpha->width_img, &alpha->height_img);
	if (!data->count_img[i])
	{
		free(alpha->file_path);
		free(alpha->plus_xpm);
		free(alpha->number_img);
		free_all_leaks(data);
	}
}

void	count_img_path(t_data *data, t_count_path *alpha)
{
	int	i;
	int	max;

	i = 0;
	max = 10;
	alpha->width_img = 8;
	alpha->height_img = 16;
	while (i < max)
	{
		check_count_path(data, alpha, i);
		free(alpha->file_path);
		free(alpha->plus_xpm);
		free(alpha->number_img);
		i++;
	}
}

void	move_count_to_img(t_data *data)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	j = 0;
	str = ft_itoa(data->move_count);
	if (!str)
		free_all_leaks(data);
	if (str)
	{
		while (str[i] != '\0')
		{
			mlx_put_image_to_window(data->mlx, data->mlx_win,
				data->count_img[str[i] - '0'], 87 + j, 7);
			if (!data->count_img[i])
			{
				free(str);
				free_all_leaks(data);
			}
			j += 16;
			i++;
		}
		free(str);
	}
}

void	free_count_imgs(t_data *data)
{
	int	i;

	i = 0;
	while (i < 10)
	{
		if (data->count_img[i])
		{
			mlx_destroy_image(data->mlx, data->count_img[i]);
			data->count_img[i] = NULL;
		}
		i++;
	}
}

void	display_movement_count(t_data *data)
{
	move_count_to_img(data);
}
