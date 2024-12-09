/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/06 22:50:20 by ebella            #+#    #+#             */
/*   Updated: 2024/12/09 16:21:52 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

// check if the player can move to the next position
// if the next position is a wall, the player can't move
int check_move(t_game *game, int x, int y)
{
    if (game->map.map[x][y] == '1')
        return (0);
    if (game->map.map[x][y] == 'E')
    {
        if (game->collect == 0)
            exit(1);
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
void move_player(t_game *game, int x, int y)
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
        mouve_player(game);
    }
}

// if the player press z q s d the player will move to the next position
int key_hook(int keycode, t_game *game)
{
    if (keycode == 122)
        move_player(game, game->player.x - 1, game->player.y);
    if (keycode == 113)
        move_player(game, game->player.x, game->player.y - 1);
    if (keycode == 115)
        move_player(game, game->player.x + 1, game->player.y);
    if (keycode == 100)
        move_player(game, game->player.x, game->player.y + 1);
    if (keycode == 65307)
        exit(1);
    return (0);
}

// render the player mouving on the window
void mouve_player(t_game *game)
{
    t_texture player;

    player.path = "./assets/player.xpm";
    player.img = mlx_xpm_file_to_image(game->mlx, player.path, &player.width,
            &player.height);
    if (!player.img)
        exit(1);
    mlx_put_image_to_window(game->mlx, game->win, player.img, game->player.y
        * 64, game->player.x * 64);
    mlx_destroy_image(game->mlx, player.img);
}