/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:26:05 by ebella            #+#    #+#             */
/*   Updated: 2024/12/27 15:07:20 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	init_textures(t_game *game)
{
	game->clock = 0;
	put_walls(game);
	put_back(game);
	idle_enemy(game);
	put_enemy(game);
	put_player(game);
	put_collect(game);
	put_exit(game);
}

void	free_tabs(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	free(tab);
}

void	free_enemys(t_enemy *enemys)
{
	t_enemy	*tmp;

	while (enemys)
	{
		tmp = enemys;
		enemys = enemys->next;
		free(tmp);
	}
}

void	end_game(t_game *game)
{
	mlx_destroy_window(game->mlx, game->win);
	mlx_destroy_display(game->mlx);
	free(game->mlx);
	free_tabs(game->map.map);
	if (game->enemys)
		free_enemys(game->enemys);
	exit(0);
}
