/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map_bonus.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:10:13 by bamezoua          #+#    #+#             */
/*   Updated: 2025/01/19 11:05:08 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	height_with(int fd, t_data *data)
{
	char	*buffer;
	char	*temp_buffer;
	int		i;
	int		j;

	i = 0;
	j = 0;
	buffer = get_next_line(fd);
	if (!buffer)
		return ;
	while (buffer[i] != '\n' && buffer[i] != '\0')
		i++;
	temp_buffer = get_next_line(fd);
	while (temp_buffer)
	{
		j++;
		free(temp_buffer);
		temp_buffer = get_next_line(fd);
	}
	j++;
	check_full_screen(data, i, j, buffer);
	data->width = i;
	data->height = j;
	free(buffer);
}

void	check_map_data(t_data *data, int x, int y, t_img_size *size)
{
	if (data->map[y][x] == '1')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->box_img,
			size->width_img, size->height_img);
	else if (data->map[y][x] == 'P')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->player_img,
			size->width_img, size->height_img);
	else if (data->map[y][x] == 'C')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->coin_img,
			size->width_img, size->height_img);
	else if (data->map[y][x] == 'E' && data->coins != data->total_coins)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->close_exit_img,
			size->width_img, size->height_img);
	else if (data->map[y][x] == 'E' && data->coins == data->total_coins)
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->open_exit_img,
			size->width_img, size->height_img);
	else if (data->map[y][x] == 'N')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->enemy_img,
			size->width_img, size->height_img);
	else if (data->map[y][x] == '0')
		mlx_put_image_to_window(data->mlx, data->mlx_win, data->background_img,
			size->width_img, size->height_img);
}

void	render_map(t_data *data)
{
	t_img_size	size;
	int			x;
	int			y;

	size.width_img = 0;
	size.height_img = 0;
	y = 0;
	while (data->map[y])
	{
		size.width_img = 0;
		x = 0;
		while (data->map[y][x])
		{
			check_map_data(data, x, y, &size);
			size.width_img += 32;
			x++;
		}
		size.height_img += 32;
		y++;
	}
}

char	**read_map(int fd, t_data *data)
{
	char	**map;
	int		i;
	char	*line;
	int		j;

	i = 0;
	map = malloc((data->height + 1) * sizeof(char *));
	data->total_coins = 0;
	if (!map)
		free_all_leaks(data);
	line = get_next_line(fd);
	while (line)
	{
		j = 0;
		while (line[j])
		{
			if (line[j] == 'C')
				data->total_coins++;
			j++;
		}
		map[i++] = line;
		line = get_next_line(fd);
	}
	map[i] = NULL;
	return (map);
}
