/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 19:41:48 by ebella            #+#    #+#             */
/*   Updated: 2024/12/10 18:48:17 by ebella           ###   ########.fr       */
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

typedef struct s_player
{
	int			x;
	int			y;
	int			moves;
	int			collect;
	int			exit;
	int			hp;
}				t_player;

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

typedef struct s_game
{
	int			collect;
	int			exit;
	t_player	player;
	void		*mlx;
	void		*win;
	t_map		map;

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
int				parsing(int argc, char **argv, t_parse *parse);
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
void			mouve_player(t_game *game);
int				key_hook(int keycode, t_game *game);
int				check_move(t_game *game, int x, int y);
void			move_player(t_game *game, int x, int y);
void			put_exit(t_game *game);
void			init_textures(t_game *game);
void			free_tabs(char **tab);
void			end_game(t_game *game);
void			print_map(t_parse *parse);

#endif