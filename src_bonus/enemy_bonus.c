/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:39:06 by ebella            #+#    #+#             */
/*   Updated: 2024/12/24 14:40:27 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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


void	idle_enemy(t_game *game)
{
	static int	i = 0;

	if (i == 0)
		game->enemy.textures.path = "./assets/enemy/monster1.xpm";
	else if (i == 1)
		game->enemy.textures.path = "./assets/enemy/monster2.xpm";
	else if (i == 2)
		game->enemy.textures.path = "./assets/enemy/monster3.xpm";
	else if (i == 3)
		game->enemy.textures.path = "./assets/enemy/monster4.xpm";
	i++;
	if (i == 4)
		i = 0;
}


// animate the enemy idle position
// checks the map and put an enemy in every position where there is an enemy ('D')
//D = Danger
void	put_enemy(t_game *game)
{
	t_texture	enemy;
	int			i;
	int			j;

	enemy.path = game->enemy.textures.path;
	enemy.img = mlx_xpm_file_to_image(game->mlx, enemy.path, &enemy.width,
			&enemy.height);
	if (!enemy.img)
		exit(1);
	i = 0;
	while (i < game->map.height / 64)
	{
		j = 0;
		while (j < game->map.width / 64)
		{
			if (game->map.map[i][j] == 'D')
				mlx_put_image_to_window(game->mlx, game->win, enemy.img, j
					* 64, i * 64);
			j++;
		}
		i++;
	}
	mlx_destroy_image(game->mlx, enemy.img);
}
// initialize the enemy position, in a linked list of enemies
int	init_enemy(t_game *game)
{
	int i;
	t_enemy	*enemy;

	i  = enemy_nb(game->map.map);
	game->nb_enemy = i;
	while (i > 0)
	{
		enemy = malloc(sizeof(*enemy));
		if (!enemy)
			return (0);
		enemy->x = 0;
		enemy->y = 0;
		enemy = enemy->next;
		i--;
	}
	return (1);
}

// initialize the enemy position, in a linked list of enemies
// and put the enemy on the map
void	enemy_move(t_game *game)
{
	t_enemy	*enemy;
	int i;
	int j;

	enemy = &game->enemy;
	i = 0;
	while (i < game->map.height / 64)
	{
		j = 0;
		while (j < game->map.width / 64)
		{
			if (game->map.map[i][j] == 'D')
			{
				enemy->x = i;
				enemy->y = j;
				enemy = enemy->next;
			}
			j++;
		}
		i++;
	}
}