/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/23 12:04:44 by ebella            #+#    #+#             */
/*   Updated: 2024/12/24 16:58:15 by ebella           ###   ########.fr       */
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
}

void	put_idle(t_game *game)
{
	t_texture	idle;

	idle.path = game->player.textures.path;
	idle.img = mlx_xpm_file_to_image(game->mlx, idle.path, &idle.width,
			&idle.height);
	if (!idle.img)
		exit(1);
	mlx_put_image_to_window(game->mlx, game->win, idle.img, game->player.y
		* 64, game->player.x * 64);
	mlx_destroy_image(game->mlx, idle.img);
}

void	print_moves(t_game *game)
{
	char *moves;

	moves = ft_itoa(game->player.moves);
	mlx_string_put(game->mlx, game->win, 20, 20, 0x00FF0000, moves);
	put_walls(game);
	free(moves);
}

int hooks(t_game *game)
{
	idle_anim(game);
	put_idle(game);
	print_moves(game);
	idle_enemy(game);
	put_enemy(game);
	usleep(100000);
	return (0);
}
