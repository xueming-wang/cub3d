/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_game.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:27:25 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/18 16:52:34 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	_window(t_cub3d *cub3d)
{
    cub3d->mlx = mlx_init();
	if (NULL == cub3d->mlx)
        exit_mlx("Error: mlx error\n", FAILURE, cub3d);
	cub3d->win = mlx_new_window(cub3d->mlx, WIN_WIDTH, WIN_HEIGHT, "cub3d");
	if (NULL == cub3d->win)
		exit_mlx("Error: mlx window error\n", FAILURE, cub3d);
}

void	_image(t_cub3d *cub3d)
{
	t_img	*img;  //创建i一个img的指针 给 mlx_img

	img =  &cub3d->mlx_img;
	img->img_ptr = mlx_new_image(cub3d->mlx, WIN_WIDTH, WIN_HEIGHT);
	if (NULL == img->img_ptr)
		exit_mlx("Error: img_ptr error\n", FAILURE, cub3d);
	cub3d->mlx_img.addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size, &img->endian);
}

int	window_destroy(t_cub3d *cub3d)
{
	(void)cub3d;
	mlx_destroy_window(cub3d->mlx, cub3d->win);
	exit_mlx(NULL, SUCCESS, cub3d);
	return (1);
}

int	_game_loop(t_cub3d *cub3d)
{
	do_raycasting(cub3d);  //射线和案件
	key_control(cub3d);
	return (1);
}

void	start_game(t_cub3d *cub3d)
{
	_window(cub3d);
	_image(cub3d);
	player_init(cub3d);//初始化
	tex_init(cub3d); //皮肤初始化
	mlx_hook(cub3d->win, 2, 1L << 0, key_press, cub3d);   //按键
	mlx_hook(cub3d->win, 3, 1L << 1, key_release, cub3d);  //松开
	mlx_hook(cub3d->win, RED_CROSS, 1L << 2, window_destroy, cub3d); //红色 删除窗口
 	mlx_loop_hook(cub3d->mlx, _game_loop, cub3d);  //程序循环运行
	mlx_loop(cub3d->mlx);   
}