/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemy_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 18:39:06 by ebella            #+#    #+#             */
/*   Updated: 2024/12/27 18:18:21 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

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
// go trough the linked list of enemies and put the enemy on the map
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
				mlx_put_image_to_window(game->mlx, game->win, enemy.img, j * 64,
					i * 64);
			j++;
		}
		i++;
	}
	mlx_destroy_image(game->mlx, enemy.img);
}

// move the enemy one step to the right and one to the left 
void	move_enemy(t_game *game)
{
	t_enemy	*enemy;

	enemy = game->enemys;
	while (enemy)
	{
		if (game->map.map[enemy->x][enemy->y + 1] == '0')
		{
			game->map.map[enemy->x][enemy->y] = '0';
			put_back_local(game, enemy->x, enemy->y);
			enemy->y++;
			game->map.map[enemy->x][enemy->y] = 'D';
		}
		else if (game->map.map[enemy->x][enemy->y - 1] == '0')
		{
			game->map.map[enemy->x][enemy->y] = '0';
			put_back_local(game, enemy->x, enemy->y);
			enemy->y--;
			game->map.map[enemy->x][enemy->y] = 'D';
		}
		if (game->player.x == enemy->x && game->player.y == enemy->y)
			end_game(game);
		enemy = enemy->next;
	}
}

void	put_back_local(t_game *game, int x, int y)
{
	t_texture	back;

	back.path = "./assets/back.xpm";
	back.img = mlx_xpm_file_to_image(game->mlx, back.path, &back.width,
			&back.height);
	if (!back.img)
		exit(1);
	mlx_put_image_to_window(game->mlx, game->win, back.img, y * 64, x * 64);
	mlx_destroy_image(game->mlx, back.img);
}
