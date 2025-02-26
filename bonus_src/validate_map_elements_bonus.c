/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_map_elements_bonus.c                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:42:57 by bamezoua          #+#    #+#             */
/*   Updated: 2025/01/14 15:46:26 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long_bonus.h"

void	not_found(t_validate_map valide, t_data *data)
{
	if (valide.exit_count != 1)
	{
		ft_printf("Error\n The map must contain exactly 1 exit ('E'). Found:\
			%d\n", valide.exit_count);
		free_all_leaks(data);
	}
	if (valide.collectible_count < 1)
	{
		ft_printf("Error\n The map must contain at least 1 collectible ('C'). Found:\
			%d\n", valide.collectible_count);
		free_all_leaks(data);
	}
	if (valide.start_position_count != 1)
	{
		ft_printf("Error\n The map must contain exactly 1 starting position ('P'). Found:\
			%d\n", valide.start_position_count);
		free_all_leaks(data);
	}
	if (valide.other != 0)
	{
		ft_printf("Error\n The map not have valid elements %d\n", valide.other);
		free_all_leaks(data);
	}
}

int	is_invalid_char(char c)
{
	return (c != 'N' && c != '\n' && c != 'P' && c != '1' && c != '0'
		&& c != 'C' && c != 'E');
}

void	process_map_char(char c, t_validate_map *valide)
{
	if (c == 'E')
		valide->exit_count++;
	else if (c == 'C')
		valide->collectible_count++;
	else if (c == 'P')
		valide->start_position_count++;
	else if (c == 'N')
		valide->enimy_count++;
	else if (is_invalid_char(c))
		valide->other++;
}

void	validate_map_elements(char **map, t_data *data)
{
	t_validate_map	valide;

	ft_bzero(&valide, sizeof(t_validate_map));
	while (map[valide.y])
	{
		valide.x = 0;
		while (map[valide.y][valide.x])
		{
			process_map_char(map[valide.y][valide.x], &valide);
			valide.x++;
		}
		valide.y++;
	}
	not_found(valide, data);
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
