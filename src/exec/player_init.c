/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 15:20:51 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/09 15:40:00 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void player_init(t_cub3d *cub3d)
{
    t_player *player;
    
    player = &cub3d->player;
    player->pos_x += 0.5;
    player->plane_y += 0.5;
    
}