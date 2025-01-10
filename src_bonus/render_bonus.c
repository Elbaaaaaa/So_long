/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render_bonus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 16:32:06 by ebella            #+#    #+#             */
/*   Updated: 2025/01/10 16:56:02 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// finds the position of the backs and render it's textures.
void	put_back(t_game *game)
{
	t_texture	back;
	int			i;
	int			j;

	back.path = "./assets/back.xpm";
	back.img = mlx_xpm_file_to_image(game->mlx, back.path, &back.width,
			&back.height);
	if (!back.img)
		exit(1);
	i = 0;
	while (i < game->map.height / 64)
	{
		j = 0;
		while (j < game->map.width / 64)
		{
			if (game->map.map[i][j] == '0' || game->map.map[i][j] == 'P')
				mlx_put_image_to_window(game->mlx, game->win, back.img, j * 64,
					i * 64);
			j++;
		}
		i++;
	}
	mlx_destroy_image(game->mlx, back.img);
}

// render the player on the window.
void	put_player(t_game *game)
{
	t_texture	player;

	player.path = "./assets/player/player.xpm";
	player.img = mlx_xpm_file_to_image(game->mlx, player.path, &player.width,
			&player.height);
	if (!player.img)
		exit(1);
	mlx_put_image_to_window(game->mlx, game->win, player.img, game->player.y
		* 64, game->player.x * 64);
	mlx_destroy_image(game->mlx, player.img);
}

// finds the position of the exit and render it's texture.
void	put_exit(t_game *game)
{
	t_texture	exit;
	int			i;
	int			j;

	exit.path = "./assets/exit.xpm";
	exit.img = mlx_xpm_file_to_image(game->mlx, exit.path, &exit.width,
			&exit.height);
	i = 0;
	while (i < game->map.height / 64)
	{
		j = 0;
		while (j < game->map.width / 64)
		{
			if (game->map.map[i][j] == 'E')
				mlx_put_image_to_window(game->mlx, game->win, exit.img, j * 64,
					i * 64);
			j++;
		}
		i++;
	}
	mlx_destroy_image(game->mlx, exit.img);
}

// finds the position of the collectables and render it's textures.
void	put_collect(t_game *game)
{
	t_texture	collect;
	int			i;
	int			j;

	collect.path = "./assets/collectable.xpm";
	collect.img = mlx_xpm_file_to_image(game->mlx, collect.path, &collect.width,
			&collect.height);
	if (!collect.img)
		exit(1);
	i = 0;
	while (i < game->map.height / 64)
	{
		j = 0;
		while (j < game->map.width / 64)
		{
			if (game->map.map[i][j] == 'C')
				mlx_put_image_to_window(game->mlx, game->win, collect.img, j
					* 64, i * 64);
			j++;
		}
		i++;
	}
	mlx_destroy_image(game->mlx, collect.img);
}

// finds the position of the walls and render it's textures.
void	put_walls(t_game *game)
{
	t_texture	wall;
	int			j;
	int			i;

	wall.path = "./assets/wall.xpm";
	wall.img = mlx_xpm_file_to_image(game->mlx, wall.path, &wall.width,
			&wall.height);
	if (!wall.img)
		exit(1);
	i = 0;
	while (game->map.map[i])
	{
		j = 0;
		while (game->map.map[i][j] != '\n')
		{
			if (game->map.map[i][j] == '1')
				mlx_put_image_to_window(game->mlx, game->win, wall.img, j * 64,
					i * 64);
			j++;
		}
		i++;
	}
	mlx_destroy_image(game->mlx, wall.img);
}
