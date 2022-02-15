/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:20:51 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/15 15:29:46 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_ply_dir
{
    char   id;
    double dir_x;
    double	dir_y;
    double	plane_x;
	double	plane_y;
    
}t_ply_dir;

static t_ply_dir const ply_dir[] = {
    {'N', 0.0, -1.0, 0.66, 0.0},
    {'S', 0.0, 1.0, -0.66, 0.0},
    {'W', -1.0, 0.0, 0.0, -0.66},
    {'E', 1.0, 0.0, 0.0, 0.66},
};

static void	set_player_dir(t_player *player)
{
    int i;

    i = 0;
    while (i < PLY_DIR)
    {
        if (player->direction == ply_dir[i].id)
        {
            player->dir_x = ply_dir[i].dir_x;
            player->dir_y = ply_dir[i].dir_y;
            player->plane_x = ply_dir[i].plane_x;
            player->plane_y = ply_dir[i].plane_y;
            
        }
        i++;
    }
}

void player_init(t_cub3d *cub3d)
{
    cub3d->player.pos_x += 0.5;
    cub3d->player.pos_y += 0.5;
    set_player_dir(&cub3d->player);
     cub3d->player.rot_speed = 0.10;
     cub3d->player.speed = 0.10;
     cub3d->player.cam_height = 1.0;
}