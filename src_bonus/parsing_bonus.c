/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 11:35:35 by ebella            #+#    #+#             */
/*   Updated: 2024/12/24 17:20:31 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// read the file and return an array of strings with the content of the file
int	check_map(t_parse *parse)
{
	char	**map;
	int		i;
	int		num_lines;

	i = 0;
	num_lines = map_lines(parse);
	map = malloc(sizeof(char *) * (num_lines + 1));
	if (!map)
		return (0);
	parse->fd = open(parse->file, O_RDONLY);
	while (i < num_lines)
	{
		map[i] = get_next_line(parse->fd);
		i++;
	}
	map[i] = NULL;
	while (get_next_line(parse->fd))
		;
	parse->map = map;
	close(parse->fd);
	return (1);
}

// check if the map is a rectangle
// if the length of the first line is different from the length of the other
// lines the map is not a rectangle return 0
// a line finish's with '\n' so the length of the line
// is the length of the string
int	check_map_rectangle(t_parse *parse)
{
	int	i;
	int	len;

	if (!parse || !parse->map || !parse->map[0])
		return (0);
	i = 0;
	len = ft_strlen(parse->map[0]);
	while (parse->map[i])
	{
		if (ft_strlen(parse->map[i]) != len)
			return (0);
		i++;
	}
	return (1);
}

// check if the map is surrounded by walls
// the first and last line must be filled with '1'
// the first column is filled with '1'
// the last column is filled with '\n
int	check_map_edges(t_parse *parse)
{
	int	i;

	i = 0;
	while (parse->map[0][i] != '\n')
	{
		if (parse->map[0][i] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (i < parse->lines)
	{
		if (parse->map[i][0] != '1' || parse->map[i][ft_strlen(parse->map[i])
			- 2] != '1')
			return (0);
		i++;
	}
	i = 0;
	while (parse->map[parse->lines - 1][i] != '\n')
	{
		if (parse->map[parse->lines - 1][i] != '1')
			return (0);
		i++;
	}
	return (1);
}

// check if the map contains only 0, 1, P, E, C
// if not return 0
int	check_map_content(t_parse *parse)
{
	int	i;
	int	j;

	parse->player = 0;
	parse->exit = 0;
	parse->collect = 0;
	if (!parse || !parse->map || !parse->map[0])
		return (0);
	i = 0;
	while (parse->map[i])
	{
		j = 0;
		while (parse->map[i][j])
		{
			if (parse->map[i][j] != '0' && parse->map[i][j] != '1'
				&& parse->map[i][j] != 'P' && parse->map[i][j] != 'E'
				&& parse->map[i][j] != 'C' && parse->map[i][j] != 'D'
				&& parse->map[i][j] != '\n')
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}

// check if there the right number of each elements.
// if not return 0
int	check_map_elements(t_parse *parse)
{
	int	i;
	int	j;

	if (!parse || !parse->map || !parse->map[0])
		return (0);
	i = 0;
	while (parse->map[i])
	{
		j = 0;
		while (parse->map[i][j])
		{
			if (parse->map[i][j] == 'P')
				parse->player++;
			if (parse->map[i][j] == 'E')
				parse->exit++;
			if (parse->map[i][j] == 'C')
				parse->collect++;
			j++;
		}
		i++;
	}
	parse->game.collect = parse->collect;
	if (parse->player != 1 || parse->exit != 1 || parse->collect < 1)
		return (0);
	return (1);
}
