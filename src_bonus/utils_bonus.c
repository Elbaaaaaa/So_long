/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:26:05 by ebella            #+#    #+#             */
/*   Updated: 2024/12/27 17:38:21 by ebella           ###   ########.fr       */
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

int	enemy_nb(char **map)
{
	int	i;
	int	j;
	int	nb;

	i = 0;
	nb = 0;
	while (map[i])
	{
		j = 0;
		while (map[i][j])
		{
			if (map[i][j] == 'D')
				nb++;
			j++;
		}
		i++;
	}
	return (nb);
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

// initialize the enemy position, in a linked list of enemies
int	init_enemy(t_game *game)
{
	int		i;
	t_enemy	*enemy;

	i = enemy_nb(game->map.map);
	game->nb_enemy = i;
	game->enemys = NULL;
	while (i > 0)
	{
		enemy = malloc(sizeof(*enemy));
		if (!enemy)
			return (0);
		enemy->x = 0;
		enemy->y = 0;
		enemy->next = game->enemys;
		game->enemys = enemy;
		i--;
	}
	return (1);
}
