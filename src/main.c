/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:56:28 by ebella            #+#    #+#             */
/*   Updated: 2024/12/09 16:25:39 by ebella           ###   ########.fr       */
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
	if (str[i - 1] != 'r'
		|| str[i - 2] != 'e'
		|| str[i - 3] != 'b'
		|| str[i - 4] != '.')
		return (0);
	return (1);
}

int	parsing(int argc, char **argv, t_parse *parse)
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
		return (0);
	if (!check_map_edges(parse))
		return (0);
	if (!check_map_content(parse))
		return (0);
	if (!check_map_elements(parse))
		return (0);
	parse->visited = dup_map(*parse);
	player_pos(parse);
	if (!pathfinding(parse, parse->player_x, parse->player_y))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_parse	parse;
	t_game	game;

	if (!parsing(argc, argv, &parse))
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
	free(parse.visited);
	free(parse.map);
	return (0);
}
