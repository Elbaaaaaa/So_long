/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 12:55:02 by ebella            #+#    #+#             */
/*   Updated: 2024/12/05 17:15:22 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// return the number of lines in the map and change the value of parse->lines
int map_lines(t_parse *parse)
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