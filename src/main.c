/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:56:28 by ebella            #+#    #+#             */
/*   Updated: 2025/01/10 18:33:37 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// check if the file exist
int	check_exist(char *str, t_parse *parse)
{
	int	fd;

	fd = open(str, O_RDONLY);
	if (fd < 0)
		return (0);
	parse->fd = fd;
	parse->file = str;
	return (1);
}

int	check_suffix(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	if (str[i - 1] != 'r' || str[i - 2] != 'e' || str[i - 3] != 'b'
		|| str[i - 4] != '.')
		return (0);
	return (1);
}

int	valid_file(int argc, char **argv, t_parse *parse)
{
	if (argc != 2)
		return (0);
	if (!check_suffix(argv[1]))
		return (0);
	if (!check_exist(argv[1], parse))
		return (0);
	return (1);
}

int	parse_map(t_parse *parse)
{
	if (!check_map_rectangle(parse))
		return (free_tabs(parse->map), 0);
	if (!check_map_edges(parse))
		return (free_tabs(parse->map), 0);
	if (!check_map_content(parse))
		return (free_tabs(parse->map), 0);
	if (!check_map_elements(parse))
		return (free_tabs(parse->map), 0);
	parse->game.map.visited = dup_map(*parse);
	if (!parse->game.map.visited)
		return (free_tabs(parse->map), 0);
	player_pos(parse);
	if (!pathfinding(parse, parse->player_x, parse->player_y))
		return (free_tabs(parse->game.map.visited),
			free_tabs(parse->map), 0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_parse	parse;
	t_game	game;

	if (!valid_file(argc, argv, &parse))
		return (write(1, "Error, file not found\n", 23), 0);
	if (!check_map(&parse))
		return (write(1, "Error, map not loaded correctly\n", 23), 0);
	if (!parse.map || !parse_map(&parse))
		return (write(1, "Error, map not valid\n", 22), 0);
	init(&game, &parse);
	init_window(&game);
	init_textures(&game);
	mlx_key_hook(game.win, key_hook, &game);
	mlx_loop(game.mlx);
	return (0);
}
