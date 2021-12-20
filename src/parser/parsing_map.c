/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:04:10 by xuwang            #+#    #+#             */
/*   Updated: 2021/12/20 16:55:30 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//1, 必须被强包围 否则返回错误
//2. 地图放在文件的最后

int check_zero(char **str, t_parsing parsing, int x, int y)
{
    int check = 0;
    int j = y;
    while(str[x][j] && x < parsing.i_len)
    {
        if (str[x][j] == '1' )
            check++;
        j++;
    }
    j = y;
    while(str[x][j] && x < parsing.i_len)
    {
        if (str[x][j] == '1' )
            check++;
        j--;
    }
    if (check == 2)
        return 1;
    return (0);
}

int check_zero2(char **str, t_parsing parsing, int x, int y)
{
    int check = 0;
    int i = x;
    while(str[i][y] && x < parsing.i_len)
    {
        if (str[i][y] == '1' )
            check++;
        i++;
    }
    i = y;
    while(str[i][y] && x < parsing.i_len)
    {
        if (str[i][y] == '1' )
            check++;
        i--;
    }
    if (check == 2)
        return 1;
    return (0);
}

int check_zero3(char **Map, t_parsing parsing)
{
    int i = 0;
    int j = 0;
    
    while(Map[i][j])
    {
        j = 0;
        while (Map[i][j])
        {
            if (Map[i][j] == '0')
            {
               if (!check_zero(Map, parsing, i, j) || !check_zero2(Map, parsing, i, j))
                    return (0);
            }
            j++;
        }
        i++;
    }
    return (1);
}

void find_N(char **Map, t_parsing parsing)
{
    int i;
    int j;

    i = 0;
    j = 0;
    while (Map[i][j])
    {
        j = 0;   
        while (Map[i][j])
        {
            if (Map[i][j] == 'N')
            {
                parsing.N_y = j;
                parsing.N_x = i;
            }
            j++;
        }
        i++;
    }
    parsing.i_len = i;
    parsing.j_len = j;
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

void parsing_map(t_cub3d *cub3d, t_parsing parsing)
{
    t_list *tmp1 = NULL;
    tmp1 = sepa_map(cub3d->dataMap);
    tmp1 = tmp1->next;
    cub3d->map = lst_to_tab(tmp1);
    find_N(cub3d->map, parsing);
    if (!check_zero3(cub3d->map, parsing))
       _exit_("Error\n", "map is wrong!\n", FAILURE);
    
 
    
}