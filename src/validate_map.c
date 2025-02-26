/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:24:50 by bamezoua          #+#    #+#             */
/*   Updated: 2025/01/15 10:14:46 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	check_top_and_bottom_rows(int i, t_map_info *info, t_data *data)
{
	while (i < info->width)
	{
		if (info->map[0][i] != '1')
		{
			ft_printf("Error\n Map is not closed at the top.\n");
			free_all_leaks(data);
		}
		if (info->map[info->height - 1][i] != '1')
		{
			ft_printf("Error\n Map is not closed at the bottom.\n");
			free_all_leaks(data);
		}
		i++;
	}
}

void	check_left_and_right_columns(int j, t_map_info *info, t_data *data)
{
	while (j < info->height)
	{
		if (info->map[j][0] != '1')
		{
			ft_printf("Error\n Map is not closed on the left side.\n");
			free_all_leaks(data);
		}
		if (info->map[j][info->width - 1] != '1')
		{
			ft_printf("Error\n Map is not closed on the right side.\n");
			free_all_leaks(data);
		}
		j++;
	}
}

void	validate_closed_map(char **map, t_data *data)
{
	t_map_info	info;
	int			i;
	int			j;

	info.map = map;
	info.width = 0;
	info.height = 0;
	while (map[0][info.width] && map[0][info.width] != '\n')
		info.width++;
	while (map[info.height])
		info.height++;
	i = 0;
	check_top_and_bottom_rows(i, &info, data);
	j = 0;
	check_left_and_right_columns(j, &info, data);
}

void	check_fd(int fd, t_data *data)
{
	if (fd < 0)
	{
		ft_printf("Error\n Map not found or cannot be opened\n");
		free_all_leaks(data);
	}
}

void	validate_rectangular_map(char **map, t_data *data)
{
	int	width;
	int	i;
	int	row_width;

	width = 0;
	i = 0;
	while (map[0][width] && map[0][width] != '\n')
		width++;
	while (map[i])
	{
		row_width = 0;
		while (map[i][row_width] && map[i][row_width] != '\n')
			row_width++;
		if (row_width != width)
		{
			ft_printf("Error\n Map is not rectangular.\n");
			free_all_leaks(data);
		}
		i++;
	}
}
