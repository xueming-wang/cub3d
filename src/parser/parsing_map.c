/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:04:10 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/16 13:12:02 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

char const	g_ply[] = {
	'N',
	'S',
	'E',
	'W',
	'\0'
};

int check_zeroinfo(char **map)
{
    int i;
    int j;
    
    i = 0;
    if (!first_last_line(map))
        return (0);
    while(map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (check_c(map[i][j]) == 0)
                return (0);
            if (map[i][j] == '0')
            {
                if ((size_t)j > (ft_strlen(map[i - 1])) || (size_t)j > (ft_strlen(map[i + 1])))
                    return (0);
                if (!check_horizont(map, i, j) || !check_vertic(map, i, j))
                    return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

void	get_player_pos(t_cub3d *cub3d, int pos_x, int  pos_y,  char direction)
{
	cub3d->player.pos_x = (double)pos_x;
	cub3d->player.pos_y = (double)pos_y;
	cub3d->player.direction = direction;
}


int find_player(t_cub3d *cub3d, char **map)
{
    t_idx	idx;

	ft_bzero(&idx, sizeof(t_idx));
    while (map[idx.i])
    {
        idx.j = 0;   
        while (map[idx.i][idx.j])
        {
            idx.k = 0;
            while (g_ply[idx.k] != '\0')
            {
                if (g_ply[idx.k] == map[idx.i][idx.j] && check_horizont(map, idx.i, idx.j) && check_vertic(map, idx.i, idx.j))
                {
                    get_player_pos(cub3d, idx.j, idx.i, g_ply[idx.k]);
                    idx.player++;
                }
                idx.k++;
            }
            idx.j++;
        }
        idx.i++;
    }
    if (idx.player == 1)
        return (1);
    return (0);
}

void parsing_map(t_cub3d *cub3d)
{
    t_list *tmp1;
    
    tmp1 = NULL;
    tmp1 = sepa_map(cub3d->dataMap);
    tmp1 = tmp1->next;
    cub3d->config = lst_to_tab(tmp1);
    if (!check_zeroinfo(cub3d->config))
    {
        free_texture(cub3d);
        _exit_("Error\n", "map config is wrong!\n", FAILURE);
    }
    if (!find_player(cub3d, cub3d->config))
    {
        free_texture(cub3d);
        _exit_("Error\n", "player config is wrong!\n", FAILURE);
    }
}

