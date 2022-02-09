/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:20:51 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/09 17:27:30 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//static void	_set_player_dir(t_player *player)
// {
//     int i;

//     i = 0;
//     while (i < )
// }

void player_init(t_cub3d *cub3d)
{
    t_player *player;
    
    player = &cub3d->player;
    player->pos_x += 0.5;
    player->plane_y += 0.5;
    //set_playerdir(player);
    player->rot_speed = 0.10;
    player->speed = 0.10;
    player->cam_height = 1.0;
}