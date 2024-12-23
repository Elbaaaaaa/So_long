/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:50:20 by ebella            #+#    #+#             */
/*   Updated: 2024/12/23 14:03:45 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// check if the player can move to the next position
// if the next position is a wall, the player can't move
int	check_move(t_game *game, int x, int y)
{
	if (game->map.map[x][y] == '1')
		return (0);
	if (game->map.map[x][y] == 'E')
	{
		if (game->collect == 0)
			end_game(game);
		return (0);
	}
	if (game->map.map[x][y] == 'C')
	{
		game->collect--;
		game->map.map[x][y] = '0';
		put_back(game);
	}
	return (1);
}

// move the player to the next position
// and render the player on the window
void	move_player(t_game *game, int x, int y)
{
	if (check_move(game, x, y))
	{
		put_back(game);
		game->player.x = x;
		game->player.y = y;
		game->player.moves++;
		write(1, "Moves: ", 7);
		ft_putnbr_fd(game->player.moves, 1);
		write(1, "\n", 1);
		put_player(game);
	}
}

int	key_hook(int keycode, t_game *game)
{
	if (keycode == 119)
		move_player(game, game->player.x - 1, game->player.y);
	if (keycode == 97)
		move_player(game, game->player.x, game->player.y - 1);
	if (keycode == 115)
		move_player(game, game->player.x + 1, game->player.y);
	if (keycode == 100)
		move_player(game, game->player.x, game->player.y + 1);
	if (keycode == 65307)
		end_game(game);
	return (0);
}
