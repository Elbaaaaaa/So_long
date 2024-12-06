/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathfinding.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 12:02:16 by ebella            #+#    #+#             */
/*   Updated: 2024/12/06 19:29:14 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// finds the i and y of the player
void	player_pos(t_parse *parse)
{
	int	i;
	int	j;

	i = 0;
	while (parse->map[i])
	{
		j = 0;
		while (parse->map[i][j])
		{
			if (parse->map[i][j] == 'P')
			{
				parse->player_x = i;
				parse->player_y = j;
				return ;
			}
			j++;
		}
		i++;
	}
}

// duplicate the map
char	**dup_map(t_parse parse)
{
	char	**map;
	int		i;

	i = 0;
	map = malloc(sizeof(char *) * (parse.lines + 1));
	if (!map)
		return (NULL);
	while (i < parse.lines)
	{
		map[i] = ft_strdup(parse.map[i]);
		if (!map[i])
		{
			while (i > 0)
			{
				free(map[i]);
				i--;
			}
			free(map);
			return (NULL);
		}
		i++;
	}
	map[i] = NULL;
	return (map);
}

// i will start from the player position and check 
//if there is a path to the exit
// i will look in foor directions up, down, left, right
// if i find a wall i dont recurse on it, i recurse on everythig else
// if i find the exit i return 1
// if i dont find the exit i return 0
int	pathfinding(t_parse *parse, int i, int j)
{
	if (i < 0 || j < 0 || i >= parse->lines
		|| j >= ft_strlen(parse->visited[0]))
		return (0);
	if (parse->exit == 0 && parse->collect == 0)
		return (1);
	if (parse->visited[i][j] == '1' || parse->visited[i][j] == 'X')
		return (0);
	if (parse->visited[i][j] == 'C')
		parse->collect--;
	if (parse->visited[i][j] == 'E')
		parse->exit--;
	parse->visited[i][j] = 'X';
	if (pathfinding(parse, i - 1, j))
		return (1);
	if (pathfinding(parse, i + 1, j))
		return (1);
	if (pathfinding(parse, i, j - 1))
		return (1);
	if (pathfinding(parse, i, j + 1))
		return (1);
	return (0);
}