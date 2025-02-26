/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main_bonus.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:21:09 by bamezoua          #+#    #+#             */
/*   Updated: 2025/01/14 15:44:49 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

int	check_map_name(char *filename, char *ext)
{
	int	len_filename;
	int	len_ext;

	if (!filename || !ext)
		return (0);
	len_filename = ft_strlen(filename);
	len_ext = ft_strlen(ext);
	if (len_filename < len_ext)
		return (0);
	if (filename[len_filename - len_ext - 1] == '/')
		return (0);
	if (ft_strncmp(&filename[len_filename - len_ext], ext, len_ext) == 0)
		return (1);
	return (0);
}

void	check_map_path(int ac, char *av)
{
	if (ac != 2 || !check_map_name(av, ".ber"))
	{
		ft_printf("Error\n Map name must end with .ber\n");
		exit(1);
	}
}

void	map_path(t_data *data)
{
	char	**cpy_map;

	cpy_map = malloc(sizeof(char *) * data->height);
	if (!cpy_map)
	{
		perror("Error\n Failed to allocate memory for cpy_map");
		free_all_leaks(data);
	}
	duplicated_map(data, cpy_map);
	check_flood_fill(data, cpy_map);
	ft_free_cpy_map(cpy_map, data->height - 1);
}

void	norm_fix(t_data *data, t_alpha_path *alpha, t_count_path *count)
{
	data->mlx = mlx_init();
	img_data(data);
	count_img_path(data, count);
	alpha_img_path(data, alpha);
}

int	main(int ac, char **av)
{
	t_data			data;
	t_alpha_path	alpha;
	t_count_path	count;
	int				fd;

	check_map_path(ac, av[1]);
	ft_bzero(&data, sizeof(t_data));
	norm_fix(&data, &alpha, &count);
	fd = open(av[1], O_RDONLY);
	check_fd(fd, &data);
	height_with(open(av[1], O_RDONLY), &data);
	data.map = read_map(fd, &data);
	find_initial_player_position(&data);
	map_path(&data);
	close(fd);
	validate_map(&data);
	data.mlx_win = mlx_new_window(data.mlx, data.width * 32, data.height * 32,
			"So Long");
	mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, handle_keypress, &data);
	render_map(&data);
	display_movement_alpha(&data);
	display_movement_count(&data);
	mlx_loop(data.mlx);
	return (0);
}
