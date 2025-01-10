/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:09:39 by ebella            #+#    #+#             */
/*   Updated: 2025/01/10 16:59:47 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// I slow diffrent actions in the game, so it renders properly.
void	slow_program(t_game *game)
{
	if (game->fps.frames % 600 == 0)
	{
		idle_anim(game);
		put_idle(game);
		idle_enemy(game);
	}
	put_enemy(game);
	if (game->fps.frames % 700 == 0)
	{
		move_enemy(game);
		put_wall_local(game, 0, 0);
	}
}

// Put the wall at a local position so i can print the moves properly.
void	put_wall_local(t_game *game, int x, int y)
{
	t_texture	back;

	back.path = "./assets/wall.xpm";
	back.img = mlx_xpm_file_to_image(game->mlx, back.path, &back.width,
			&back.height);
	if (!back.img)
		exit(1);
	mlx_put_image_to_window(game->mlx, game->win, back.img, y * 64, x * 64);
	mlx_destroy_image(game->mlx, back.img);
}
