/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_bonus.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bamezoua <bamezoua@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/11 09:45:10 by bamezoua          #+#    #+#             */
/*   Updated: 2025/01/20 09:52:06 by bamezoua         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_BONUS_H
# define SO_LONG_BONUS_H
# include "../ft_printf/ft_printf.h"
# include "../get_next_line/get_next_line.h"
# include "../libft/libft.h"
# include <X11/X.h>
# include <X11/keysym.h>
# include <fcntl.h>
# include <mlx.h>

typedef struct s_data
{
	void	*mlx;
	void	*mlx_win;
	int		move_count;
	void	*player_img;
	void	*enemy_img;
	void	*box_img;
	void	*coin_img;
	int		coins;
	int		total_coins;
	int		player_x;
	int		player_y;
	char	**map;
	void	*close_exit_img;
	void	*open_exit_img;
	void	*background_img;
	int		width;
	int		height;
	int		height_img;
	int		width_img;
	char	tmp;
	void	*count_img[10];
	void	*alpha_img[26];
}			t_data;

typedef struct img_size
{
	int		width_img;
	int		height_img;
}			t_img_size;

typedef struct validate_map
{
	int		exit_count;
	int		collectible_count;
	int		start_position_count;
	int		enimy_count;
	int		y;
	int		x;
	int		other;
}			t_validate_map;

typedef struct s_map_info
{
	char	**map;
	int		width;
	int		height;
}			t_map_info;

typedef struct s_alpha_path
{
	char	*file_path;
	char	*number_img;
	char	*plus_xpm;
	int		width_img;
	int		height_img;
}			t_alpha_path;

typedef struct s_count_path
{
	char	*file_path;
	char	*number_img;
	char	*plus_xpm;
	int		width_img;
	int		height_img;
}			t_count_path;

int			handle_keypress(int keycode, void *param);
void		render_map(t_data *data);
char		**read_map(int fd, t_data *data);
void		height_with(int fd, t_data *data);
void		player_not_found(t_data *data);
void		find_initial_player_position(t_data *data);
void		validate_map_elements(char **map, t_data *data);
void		validate_closed_map(char **map, t_data *data);
void		validate_rectangular_map(char **map, t_data *data);
void		duplicated_map(t_data *data, char **cpy_map);
void		flood_fill(t_data *data, char **cpy_map, int player_x,
				int player_y);
void		check_flood_fill(t_data *data, char **cpy_map);
void		free_all_leaks(t_data *data);
int			close_window(t_data *data);
void		ft_free_cpy_map(char **cpy_map, int i);
void		display_movement_count(t_data *data);
void		free_map(char **map);
void		count_img_path(t_data *data, t_count_path *count);
void		free_count_imgs(t_data *data);
void		display_movement_alpha(t_data *data);
void		alpha_img_path(t_data *data, t_alpha_path *alpha);
void		check_fd(int fd, t_data *data);
void		check_map_path(int ac, char *av);
int			check_map_name(char *filename, char *ext);
void		img_data(t_data *data);
void		validate_map(t_data *data);
void		free_count_imgs(t_data *data);
void		free_alpha_imgs(t_data *data);
void		check_full_screen(t_data *data, int i, int j, char *buffer);

#endif