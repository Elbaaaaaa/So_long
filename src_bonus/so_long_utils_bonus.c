/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:55:02 by ebella            #+#    #+#             */
/*   Updated: 2025/01/10 17:01:52 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// return the number of lines in the map and initialize the lines for parsing.
int	map_lines(t_parse *parse)
{
	int		num_lines;
	char	*line;

	num_lines = 0;
	line = get_next_line(parse->fd);
	while (line)
	{
		free(line);
		line = get_next_line(parse->fd);
		num_lines++;
	}
	free(line);
	parse->lines = num_lines;
	close(parse->fd);
	return (num_lines);
}

// return the number of coins in the map and initialize the collect for game.
int	map_coins(t_parse *parse, t_game *game)
{
	int	i;
	int	j;
	int	coins;

	i = 0;
	coins = 0;
	while (parse->map[i])
	{
		j = 0;
		while (parse->map[i][j])
		{
			if (parse->map[i][j] == 'C')
				coins++;
			j++;
		}
		i++;
	}
	game->collect = coins;
	return (coins);
}

// return the width of the map and initialize the width for the parsing.
int	map_width(t_parse *parse)
{
	int	i;
	int	len;
	int	max_len;

	i = 0;
	max_len = 0;
	while (parse->map[i])
	{
		len = ft_strlen(parse->map[i]);
		if (len > max_len)
			max_len = len;
		i++;
	}
	parse->width = max_len;
	return (max_len);
}

// initialize the window with the width and height of the map.
void	init_window(t_game *game)
{
	game->mlx = mlx_init();
	if (!game->mlx)
		exit(1);
	game->win = mlx_new_window(game->mlx, game->map.width, game->map.height,
			"so_long");
	if (!game->win)
		exit(1);
}

// initialize the game with the parsing and game values.
// if the map is too big, exit the program.
// if the enemy is not initialized, exit the program.
// if the map is too big, exit the program.
void	init(t_game *game, t_parse *parse)
{
	parse->width = map_width(parse);
	game->map.width = (parse->width - 1) * 64;
	if (game->map.width > 1920)
		return (write(1, "Error, map too big\n", 19), free_tabs(parse->map),
			exit(1));
	game->map.height = (parse->lines * 64);
	if (game->map.height > 1080)
		return (write(1, "Error, map too big\n", 19), free_tabs(parse->map),
			exit(1));
	game->collect = map_coins(parse, game);
	game->exit = parse->exit;
	game->player.x = parse->player_x;
	game->player.y = parse->player_y;
	game->fps.frames = 0;
	game->fps.time = 0;
	game->player.moves = 0;
	game->player.collect = 0;
	game->player.exit = 0;
	game->map.map = parse->map;
	game->hearts.nb = 3;
	if (init_enemy(game) == 0)
		return (write(1, "Error, enemy not initialized\n", 29),
			free_tabs(parse->map), exit(1));
	init_enemy_pos(game);
}
