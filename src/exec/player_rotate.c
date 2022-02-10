/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   player_rotate.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 12:56:51 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/10 13:01:54 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	player_rotate_left(t_player *player)
{
	double		old_dir_x;
	double		old_plane_x;
    
	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(-player->rot_speed)
		- player->dir_y * sin(-player->rot_speed);
	player->dir_y = old_dir_x * sin(-player->rot_speed)
		+ player->dir_y * cos(-player->rot_speed);
	player->plane_x = player->plane_x * cos(-player->rot_speed)
		- player->plane_y * sin(-player->rot_speed);
	player->plane_y = old_plane_x * sin(-player->rot_speed)
		+ player->plane_y * cos(-player->rot_speed);
}

void	player_rotate_right(t_player *player)
{
	
	double		old_dir_x;
	double		old_plane_x;

	old_dir_x = player->dir_x;
	old_plane_x = player->plane_x;
	player->dir_x = player->dir_x * cos(player->rot_speed)
		- player->dir_y * sin(player->rot_speed);
	player->dir_y = old_dir_x * sin(player->rot_speed)
		+ player->dir_y * cos(player->rot_speed);
	player->plane_x = player->plane_x * cos(player->rot_speed)
		- player->plane_y * sin(player->rot_speed);
	player->plane_y = old_plane_x * sin(player->rot_speed)
		+ player->plane_y * cos(player->rot_speed);
}