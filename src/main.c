/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/06 14:21:09 by bamezoua          #+#    #+#             */
/*   Updated: 2025/01/20 09:47:34 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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
	data->background_img = mlx_xpm_file_to_image(data->mlx,
			"./textures/background.xpm", &img_width, &img_height);
	if (!data->box_img || !data->player_img
		|| !data->coin_img || !data->close_exit_img
		|| !data->open_exit_img || !data->background_img)
	{
		printf("Eroor\n Image Not found\n");
		free_all_leaks(data);
	}
}

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
		ft_printf("Error\n Map name uncorrect .ber\n");
		exit(1);
	}
}

int	main(int ac, char **av)
{
	t_data	data;
	int		fd;

	check_map_path(ac, av[1]);
	ft_bzero(&data, sizeof(t_data));
	data.mlx = mlx_init();
	img_data(&data);
	fd = open(av[1], O_RDONLY);
	check_fd(fd, &data);
	height_with(open(av[1], O_RDONLY), &data);
	data.map = read_map(fd, &data);
	find_initial_player_position(&data);
	map_path(&data);
	close(fd);
	validate_rectangular_map(data.map, &data);
	validate_map_elements(data.map, &data);
	validate_closed_map(data.map, &data);
	data.mlx_win = mlx_new_window(data.mlx, data.width * 32, data.height * 32,
			"So Long");
	mlx_hook(data.mlx_win, 17, 0, close_window, &data);
	mlx_hook(data.mlx_win, 2, 1L << 0, handle_keypress, &data);
	render_map(&data);
	mlx_loop(data.mlx);
	return (0);
}
