/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:04:44 by ebella            #+#    #+#             */
/*   Updated: 2025/01/15 16:45:30 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// animate the player idle position
void	idle_anim(t_game *game)
{
	static int	i = 0;

	if (i == 0)
		game->player.textures.path = "./assets/player/idle1.xpm";
	else if (i == 1)
		game->player.textures.path = "./assets/player/idle2.xpm";
	else if (i == 2)
		game->player.textures.path = "./assets/player/idle3.xpm";
	else if (i == 3)
		game->player.textures.path = "./assets/player/idle4.xpm";
	else if (i == 4)
		game->player.textures.path = "./assets/player/idle5.xpm";
	else if (i == 5)
		game->player.textures.path = "./assets/player/idle6.xpm";
	else if (i == 6)
		game->player.textures.path = "./assets/player/idle7.xpm";
	i++;
	if (i == 7)
		i = 0;
	if (!game->player.textures.path)
		end_game(game);
}

// render the animated player idle position.
void	put_idle(t_game *game)
{
	t_texture	idle;

	idle.path = game->player.textures.path;
	idle.img = mlx_xpm_file_to_image(game->mlx, idle.path, &idle.width,
			&idle.height);
	if (!idle.img)
		end_game(game);
	mlx_put_image_to_window(game->mlx, game->win, idle.img, game->player.y * 64,
		game->player.x * 64);
	mlx_destroy_image(game->mlx, idle.img);
}

// print the number of moves on the window.
void	print_moves(t_game *game)
{
	char	*moves;

	moves = ft_itoa(game->player.moves);
	mlx_string_put(game->mlx, game->win, 20, 20, 0x00FF0000, moves);
	free(moves);
}

// initialize the enemy positions in a linked list of enemies.
void	init_enemy_pos(t_game *game)
{
	t_enemy	*enemy;
	int		i;
	int		j;

	enemy = game->enemys;
	while (enemy)
	{
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
}

// the loop of all the events in the game.
int	hooks(t_game *game)
{
	t_enemy	*enemy;

	enemy = game->enemys;
	while (enemy)
	{
		if (game->player.x == enemy->x && game->player.y == enemy->y)
			end_game(game);
		enemy = enemy->next;
	}
	game->fps.frames++;
	if (game->fps.frames == 1000)
		game->fps.frames = 0;
	print_moves(game);
	slow_program(game);
	mlx_hook(game->win, DestroyNotify, 0, end_game, game);
	return (0);
}
