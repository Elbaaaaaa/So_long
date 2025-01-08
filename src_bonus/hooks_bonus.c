/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hooks_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/30 15:09:39 by ebella            #+#    #+#             */
/*   Updated: 2024/12/30 17:00:10 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	slow_program(t_game *game)
{
	if (game->fps.frames % 70 == 0)
	{
		idle_anim(game);
		put_idle(game);
		print_moves(game);
		idle_enemy(game);
		// animate_hearts(game);
	}
	put_hearts(game, 0, 10);
	put_enemy(game);
	if (game->fps.frames % 700 == 0)
	{
		move_enemy(game);
		put_wall_local(game, 0, 0);
	}
}
void	put_hearts(t_game *game, int x, int y)
{
	int	i;

	i = 0;
	while (i < game->hearts.nb)
	{
		game->hearts.textures->img = mlx_xpm_file_to_image(game->mlx,
				game->hearts.textures->path, &game->hearts.textures->width,
				&game->hearts.textures->height);
		if (!game->hearts.textures->img)
			exit(1);
		mlx_put_image_to_window(game->mlx, game->win, game->hearts.textures->img, y * 64, x * 64);
		mlx_destroy_image(game->mlx, game->hearts.textures->img);
		i++;
	}
}

void	animate_hearts(t_game *game)
{
	static int	i = 0;

	if (i == 0)
		game->hearts.textures->path = "./assets/heart/heart1.xpm";
	else if (i == 1)
		game->hearts.textures->path = "./assets/heart/heart2.xpm";
	else if (i == 2)
		game->hearts.textures->path = "./assets/heart/heart3.xpm";
	else if (i == 3)
		game->hearts.textures->path = "./assets/heart/heart4.xpm";
	i++;
	if (i == 4)
		i = 0;
}

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