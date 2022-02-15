/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_casting_set.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:03:29 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/15 19:43:02 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void  sideDist_init(t_raycast *ray, t_player *player)
{
    if (ray->raydir_x < 0)
    {
        ray->step_x = -1;
        ray->sideDist_x = (player->pos_x - ray->map_x) * ray->deltaDist_x;
    }
    else
    {
        ray->step_x = 1;
        ray->sideDist_x = (ray->map_x + 1.0 - player->pos_x) * ray->deltaDist_x;
    }
    if (ray->raydir_y < 0)
    {
        ray->step_y = -1;
        ray->sideDist_y = (player->pos_y - ray->map_y) * ray->deltaDist_y;
    }
    else
    {
        ray->step_y = 1;
        ray->sideDist_y = (ray->map_y + 1.0 - player->pos_y) * ray->deltaDist_y;
    } 
}

void hit_wall(t_raycast *ray, t_cub3d *cub3d)
{
    while(ray->hit == 0)
    {
        //jump to next map square, either in x-direction, or in y-direction
        if(ray->sideDist_x < ray->sideDist_y)
        {
            ray->sideDist_x += ray->deltaDist_x;
            ray->map_x +=  ray->step_x;
            if (ray->step_x == 1)
			    ray->side = e_NO;
		    else if (ray->step_x == -1)
				ray->side = e_SO;
        }
        else
        {
            ray->sideDist_y += ray->deltaDist_y;
            ray->map_y += ray->step_y;
            if (ray->step_y == 1)
				ray->side = e_WE;
			else if (ray->step_y == -1)
				ray->side = e_EA;
        }
        if(cub3d->mapinfo.map[ray->map_y][ray->map_x] == '1') 
            ray->hit = 1;
    }
}

//Calculate distance projected on camera direction. 
//This is the shortest distance from the point where the wall is
void  set_perpWallDist(t_raycast *ray, t_player *player)
{
    if (ray->side == 0 || ray->side == 1) 
		ray->perpWallDist = (ray->map_x - player->pos_x + (1 - ray->step_x) / 2) / ray->raydir_x;
	else
		ray->perpWallDist = (ray->map_y - player->pos_y + (1 - ray->step_y) / 2) / ray->raydir_y;
}

 //Calculate height of line to draw on screen
void set_lineHeight(t_raycast *ray)
{
    ray->line_height = (int)(WIN_HEIGHT / ray->perpWallDist);
}

// calculate lowest and highest pixel to fill in current stripe
void  set_drawinfo(t_raycast *ray, t_player *player)
{
    ray->draw_start = (-ray->line_height / 2 + ((WIN_HEIGHT / 2) * player->cam_height));
	if (ray->draw_start < 0)
		ray->draw_start = 0;
	ray->draw_end = (ray->line_height / 2 + ((WIN_HEIGHT / 2) * player->cam_height));
	if (ray->draw_end >= WIN_HEIGHT)
		ray->draw_end = WIN_HEIGHT;
}
