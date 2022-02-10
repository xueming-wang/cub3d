/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:04:10 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/10 15:46:26 by xuwang           ###   ########.fr       */
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
            if (map[i][j] != '0' && map[i][j] != '1' && map[i][j] != ' ' && map[i][j] != 'N')
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

int check_N(char **map)
{
    int i;
    int j;
    int n;

    n = 0;
    i = 0;
    while (map[i])
    {
        j = 0;   
        while (map[i][j])
        {
            if (map[i][j] == 'N')
                n++;
            j++;
        }
        i++;
    }
    if (n != 1)
        return (0);
    return (1);
}
    

int find_N(char **map)
{
    int i;
    int j;
    int n;
    
    i = 0;
    n = 0;
    while (map[i])
    {
        j = 0;   
        while (map[i][j])
        {
            if (map[i][j] == 'N' && check_N(map) && check_horizont(map, i, j) 
                && check_vertic(map, i, j))
            {
                // parsing.N_y = j;
                // parsing.N_x = i;
                return (1);
            }
            j++;
        }
        i++;
    }
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
    if (!find_N(cub3d->config))
    {
        free_texture(cub3d);
        _exit_("Error\n", "N config is wrong!\n", FAILURE);
    }
}

