/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/09 16:26:05 by ebella            #+#    #+#             */
/*   Updated: 2024/12/09 16:28:04 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void    init_textures(t_game *game)
{
	put_walls(game);
	put_back(game);
	put_player(game);
	put_collect(game);
	put_exit(game);
}
