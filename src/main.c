/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:56:28 by ebella            #+#    #+#             */
/*   Updated: 2024/12/05 17:37:48 by ebella           ###   ########.fr       */
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
	if (!check_map_rectangle(parse) 
		|| !check_map_edges(parse)
		|| !check_map_content(parse)
		|| !check_map_elements(parse))
		return (0);
	return (1);
}

int	main(int argc, char **argv)
{
	t_parse	parse;
	int		i;
	int		j;

	if (!parsing(argc, argv, &parse))
		return (write(1, "Error_CACA\n", 12), 0);
	if (!check_map(&parse))
		return (write(1, "Error_KAKA\n", 12), 0);
	if (!parse.map || !parse_map(&parse))
		return (write(1, "Error_COULANTE\n", 15), 0);
	i = 0;
	j = 0;
	while (i < parse.lines)
	{
		j = 0;
		while (parse.map[i][j])
		{
			write(1, &parse.map[i][j], 1);
			j++;
		}
		free(parse.map[i]);
		i++;
	}
	free(parse.map);
}
