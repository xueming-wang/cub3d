/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_img.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/08 11:27:25 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/10 12:34:14 by xuwang           ###   ########.fr       */
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

static int	_window_destroy(t_cub3d *cub3d)
{
	mlx_destroy_window(cub3d->mlx, cub3d->win);
	exit_mlx(NULL, FAILURE, cub3d);
	return (1);
}

static int	_game_loop(t_cub3d *cub3d)
{
	do_raycasting(cub3d);  //射线和案件
	//key_control();
	return (1);
}

void	start_game(t_cub3d *cub3d)
{
	t_key key;
	key = ft_bzero(&key, sizeof(t_key));
	key = &cub3d->key;
	
	_window(cub3d);
	_image(cub3d);
	player_init(cub3d);//初始化
	// tex_initialize(); //皮肤初始化
	mlx_hook(cub3d->win, 2, 1L << 0, key_pressing, NULL);   //按键
	mlx_hook(cub3d->win, 3, 1L << 1, key_releasing, NULL);  //松开
	// mlx_hook(cub3d->win, RED_CROSS, 1L << 2, _window_destroy, NULL); //红色 删除窗口
 	// mlx_loop_hook(cub3d->mlx, _game_loop, NULL);  //程序循环运行
	// mlx_loop(cub3d->mlx);   
}