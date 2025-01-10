/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:41:48 by ebella            #+#    #+#             */
/*   Updated: 2025/01/10 18:26:18 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include "../lib/libft/libft.h"
# include "../lib/mlx/mlx.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <time.h>

typedef struct s_pos
{
	int			px_x;
	int			px_y;
}				t_pos;

typedef struct s_map
{
	int			width;
	int			height;
	char		**map;
	char		**visited;
}				t_map;

typedef struct s_texture
{
	char		*texture;
	void		*img;
	int			width;
	int			height;
	char		*path;
}				t_texture;

typedef struct s_player
{
	int			x;
	int			y;
	int			moves;
	int			collect;
	int			exit;
	t_texture	textures;
}				t_player;

typedef struct s_enemy
{
	int			x;
	int			y;
	int			dir;
	int			index;
	struct s_enemy	*next;
	t_texture	textures;
}				t_enemy;

typedef	struct s_fps
{
	int			fps;
	int			frames;
}				t_fps;

typedef struct s_game
{
	int			collect;
	int			exit;
	int			nb_enemy;
	t_player	player;
	void		*mlx;
	void		*win;
	t_map		map;
	t_enemy		enemy;
	t_enemy		*enemys;
	t_pos		pos;
	t_fps		fps;

}				t_game;

typedef struct s_parse
{
	int			fd;
	char		*file;
	char		**map;
	int			player;
	int			exit;
	int			collect;
	int			lines;
	int			player_x;
	int			player_y;
	int			width;
	t_game		game;
}				t_parse;


int				check_map(t_parse *parse);
int				valid_file(int argc, char **argv, t_parse *parse);
int				check_suffix(char *str);
int				check_exist(char *str, t_parse *parse);
int				check_map_rectangle(t_parse *parse);
int				check_map_edges(t_parse *parse);
int				check_map_content(t_parse *parse);
int				check_map_elements(t_parse *parse);
int				parse_map(t_parse *parse);
int				map_lines(t_parse *parse);
int				pathfinding(t_parse *parse, int i, int j);
char			**dup_map(t_parse parse);
void			player_pos(t_parse *parse);
void			render(t_game *game, t_parse *parse);
void			init(t_game *game, t_parse *parse);
void			init_window(t_game *game);
void			put_walls(t_game *game);
int				map_width(t_parse *parse);
void			put_back(t_game *game);
void			put_player(t_game *game);
void			put_collect(t_game *game);
int				key_hook(int keycode, t_game *game);
int				check_move(t_game *game, int x, int y);
void			move_player(t_game *game, int x, int y);
void			put_exit(t_game *game);
void			init_textures(t_game *game);
void			free_tabs(char **tab);
void			end_game(t_game *game);
void			print_map(t_parse *parse);
void			idle_anim(t_game *game);
void			put_idle(t_game *game);
void			print_moves(t_game *game);
int				hooks(t_game *game);
void			get_player_pos(t_game *game);
void			put_enemy(t_game *game);
void			idle_enemy(t_game *game);
int				init_enemy(t_game *game);
void			init_enemy_pos(t_game *game);
void    		move_enemy(t_game *game);
void			put_back_local(t_game *game, int x, int y);
void			free_enemys(t_enemy *enemys);
void			slow_program(t_game *game);
void			put_hearts(t_game *game, int x, int y);
void			animate_hearts(t_game *game);
void			put_wall_local(t_game *game, int x, int y);

#endif