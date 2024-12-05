/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 16:33:12 by ebella            #+#    #+#             */
/*   Updated: 2024/12/04 16:59:03 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

int	check_collect(t_data *data)
{
	int	i;
	int	y;
	int	count;

	i = 0;
	count = 0;
	y = 0;
	while (data->map[y])
	{
		while (data->map[y][i])
		{
			if (data->map[y][i] == data->content.collectable)
				count++;
			i++;
		}
		i = 0;
		y++;
	}
	return (count);	
}

