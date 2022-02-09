/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 12:17:34 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/09 13:13:16 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void  ft_deltaDist(t_raycast *ray){
    if (ray->raydird_x == 0)
        
    
}

static void raycasting_init(t_raycast*ray) 
{
    t_player player;
     //calculate ray position and direction
    ray->cameraX = 2 * ray->pix / (double)WIN_WIDTH - 1;
    ray->raydird_x = player.dir_x + player.plane_x * ray->cameraX;
    ray->raydird_y = player.dir_y + player.plane_y * ray->cameraX;
    //which box of the map we're in
    ray->map_x = (int)player.pos_x;
    ray->map_y = (int)player.pos_y;
    
    ray->deltaDist_x = fabs(1 / ray->raydird_x); //绝对值
    ray->deltaDist_y = fabs(1 / ray->raydird_y);
}

static void ft_raycasting(t_raycast *ray)
{
    raycasting_init(ray);
	// _side_dist_initialize(ray);
	// wall_hit(ray);
	// projection_dist_calculate(ray);
	// height_line_calculate(ray);
	// pixel_to_fill_stripe_calculate(ray);
	// drawing(ray);
}

void do_raycasting(t_cub3d *cub3d)
{
    t_raycast ray;

    ft_bzero(&ray, sizeof(t_raycast));
    while(ray.pix < WIN_WIDTH)
    {
       ft_raycasting(&ray);
       ++ray.pix; 
    }
    mlx_put_image_to_window(cub3d->mlx, cub3d->win, cub3d->mlx_img.img_ptr, 0,0);
}