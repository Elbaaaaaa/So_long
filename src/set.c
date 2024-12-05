/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ebella <ebella@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/04 14:36:10 by ebella            #+#    #+#             */
/*   Updated: 2024/12/04 16:58:52 by ebella           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/so_long.h"

void	set_content(t_cnt *cnt)
{
	cnt->exit = 'E';
	cnt->collectable = 'C';
	cnt->player = 'P';
	cnt->wall = '1';
	cnt->floor = '0';
	cnt->space = ' ';
	cnt->count_c = 0;
	cnt->count_e = 0;
	cnt->count_p = 0;
}

void	set_img(t_data *data)
{
	data->img.heigth = 80;
	data->img.width = 80;
	data->img.floor = "./assets/floor_1.xpm";
	data->img.wall = "./assets/wall_1.xpm";
	data->img.collectable = "./assets/collectable_1.xpm";
	data->img.exit = "./assets/exit_1.xpm";
	data->img.player = "./assets/player.xpm";
	data->img.img_floor = mlx_xpm_file_to_image(data->mlx_ptr, data->img.floor,
			&data->img.width, &data->img.heigth);
	data->img.img_wall = mlx_xpm_file_to_image(data->mlx_ptr, data->img.wall,
			&data->img.width, &data->img.heigth);
	data->img.img_collectable = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.collectable, &data->img.width, &data->img.heigth);
	data->img.img_exit = mlx_xpm_file_to_image(data->mlx_ptr, data->img.exit,
			&data->img.width, &data->img.heigth);
	data->img.img_player = mlx_xpm_file_to_image(data->mlx_ptr,
			data->img.player, &data->img.width, &data->img.heigth);
}