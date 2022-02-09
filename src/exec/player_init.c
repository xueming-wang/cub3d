/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:20:51 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/09 18:07:21 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

typedef struct s_ply_dir
{
    char   dir;
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
        if (player->direction == ply_dir[i].dir)
        {
            player->dir_x = ply_dir[i].dir_x;
            player->dir_y = ply_dir[i].dir_y;
            player->plane_x = ply_dir[i].plane_x;
            player->plane_y = ply_dir[i].plane_y;
        }
    }
}

void player_init(t_cub3d *cub3d)
{
    t_player *player;
    
    player = &cub3d->player;
    player->pos_x += 0.5;
    player->plane_y += 0.5;
    set_player_dir(player);
    player->rot_speed = 0.10;
    player->speed = 0.10;
    player->cam_height = 1.0;
}