/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:55:02 by ebella            #+#    #+#             */
/*   Updated: 2024/12/10 18:58:30 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// return the number of lines in the map and change the value of parse->lines
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

// initialize the map height and width with the parse lines and parse length
// pixel size is 64
void	init(t_game *game, t_parse *parse)
{
	parse->width = map_width(parse);
	game->map.height = (parse->lines * 64);
	if (game->map.height > 1920)
		return (write(1, "Error, map too big\n", 19), free_tabs(parse->map),
			exit(1));
	game->map.width = (parse->width - 1) * 64;
	if (game->map.width > 1080)
		return (write(1, "Error, map too big\n", 19), free_tabs(parse->map),
			exit(1));
	game->collect = map_coins(parse, game);
	game->exit = parse->exit;
	game->player.x = parse->player_x;
	game->player.y = parse->player_y;
	game->player.moves = 0;
	game->player.collect = 0;
	game->player.exit = 0;
	game->player.hp = 0;
	game->map.map = parse->map;
}
