/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:27:25 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/08 16:24:49 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	_window(t_cub3d *cub3d)
{
    cub3d->mlx = mlx_init();
	if (NULL == cub3d->mlx)
        exit_mlx("Error: mlx error\n", FAILURE, cub3d);
	cub3d->win = mlx_new_window(cub3d->mlx, 800, 800, "cub3d");
	if (NULL == cub3d->win)
	{
		exit_mlx("Error: mlx window error\n", FAILURE, cub3d);
	}
}

static void	_image(t_cub3d *cub3d)
{
	t_img	*img;  //创建i一个img的指针 给 mlx_img

	img =  &cub3d->mlx_img;
	img->img_ptr = mlx_new_image(cub3d->mlx, 800, 800);
	if (NULL == img->img_ptr)
		_exit_(NULL, NULL, FAILURE);
	cub3d->mlx_img.addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size, &img->endian);
}

// static int	_window_destroy(t_cub3d *cub3d)
// {
	
// 	mlx_destroy_window(cub3d->mlx, cub3d->win);
// 	exit_mlx(NULL, FAILURE, cub3d);
// 	return (1);
// }

// static int	_game_loop(void)
// {
// 	do_raycasting();
// 	key_control();
// 	return (1);
// }

void	start_game(t_cub3d *cub3d)
{
	_window(cub3d);
	_image(cub3d);
	// player_initialize();
	// tex_initialize();
	// mlx_hook(sglt()->win_ptr, 2, 1L << 0, key_pressing, NULL);
	// mlx_hook(sglt()->win_ptr, 3, 1L << 1, key_releasing, NULL);
	// mlx_hook(sglt()->win_ptr, RED_CROSS, 1L << 2, _window_destroy, NULL);
	// mlx_loop_hook(sglt()->mlx_ptr, _game_loop, NULL);
	// mlx_loop(sglt()->mlx_ptr);
}