/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_mov.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/09 18:21:11 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/13 15:49:17 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void player_move_w(t_cub3d *cub3d, t_player *player)
{
    player = &cub3d->player;
    
    if (cub3d->mapinfo.map[(int)player->pos_y]
        [(int)(player->pos_x + player->dir_x * player->speed * 2)] == '0')
        player->pos_x += player->dir_x * player->speed;
    if (cub3d->mapinfo.map[(int)(player->pos_y + player->dir_y * player->speed * 2)]
        [(int)player->pos_x] == '0')
        player->pos_y += player->dir_x * player->speed;
}

void player_move_s(t_cub3d *cub3d, t_player *player)
{
    player = &cub3d->player;
    
    if (cub3d->mapinfo.map[(int)player->pos_y]
        [(int)(player->pos_x + player->dir_x * player->speed * 2)] == '0')
        player->pos_x -= player->dir_x * player->speed;
    if (cub3d->mapinfo.map[(int)(player->pos_y + player->dir_y * player->speed * 2)]
        [(int)player->pos_x] == '0')
        player->pos_y -= player->dir_x * player->speed;
}
void player_move_a(t_cub3d *cub3d, t_player *player)
{
    player = &cub3d->player;
    
    if (cub3d->mapinfo.map[(int)player->pos_y]
        [(int)(player->pos_x - player->plane_x * player->speed * 2)] == '0')
        player->pos_x -= player->plane_x * player->speed;
    if (cub3d->mapinfo.map[(int)(player->pos_y - player->plane_y * player->speed * 2)]
        [(int)player->pos_x] == '0')
        player->pos_y -= player->plane_x * player->speed;
}

void player_move_d(t_cub3d *cub3d, t_player *player)
{
    player = &cub3d->player;
    
    if (cub3d->mapinfo.map[(int)player->pos_y]
        [(int)(player->pos_x + player->plane_x * player->speed * 2)] == '0')
        player->pos_x += player->plane_x * player->speed;
    if (cub3d->mapinfo.map[(int)(player->pos_y + player->plane_y * player->speed * 2)]
        [(int)player->pos_x] == '0')
        player->pos_y += player->plane_x * player->speed;
}

