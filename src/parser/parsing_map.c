/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:04:10 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/15 13:53:01 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"


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
            if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' ' && map[i][j] != 'N'
                && map[i][j] != 'S' && map[i][j] != 'W'  && map[i][j] != 'E')
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


// int check_player(char **map)
// {
//     int i;
//     int j;
//     int n;

//     n = 0;
//     i = 0;
//     while (map[i])
//     {
//         j = 0;   
//         while (map[i][j])
//         {
//             if (map[i][j] == 'N' || map[i][j] == 'S' || map[i][j] == 'E' || map[i][j] == 'W')
//                 n++;
//             j++;
//         }
//         i++;
//     }
//     if (n != 1)
//         return (0);
//     return (1);
// }
    
static char const	g_ply[] = {
	'N',
	'S',
	'E',
	'W',
	'\0'
};

void	get_player_pos(t_cub3d *cub3d, int pos_x, int  pos_y,  char direction)
{
	cub3d->player.pos_x = (double)pos_x;
	cub3d->player.pos_y = (double)pos_y;
	cub3d->player.direction = direction;
}

typedef struct s_idx
{
	int	i;
	int	j;
	int	k;
	int	player;
}	t_idx;

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
                    // printf("%d, %d, %c", idx.i, idx.j ,g_ply[idx.k]);
                    get_player_pos(cub3d, idx.i, idx.j, g_ply[idx.k]);
                    idx.player++;
                    break ;
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

char **lst_to_tab(t_list *list)
{
    char **map;
    int len;
    int i;
    t_list *tmp;
    
    i = 0;
    len = ft_lstsize(list);
    map = malloc(sizeof(char *) * (len + 1));
    if (!map)
        return (NULL);
    tmp = list;
    while (tmp && i < len)
    {
        map[i] = ft_strdup((char *)tmp->content);
        tmp = tmp->next;
        i++;   
    } 
    map[i] = NULL;
    return (map);
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

