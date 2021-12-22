/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:04:10 by xuwang            #+#    #+#             */
/*   Updated: 2021/12/22 14:57:49 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_zero1(char **map, int x, int y)
{
    int check = 0;
    int j = y;
    
    while(map[x][j])
    {
        if (map[x][j] == '1' )
        {
            check++;
            break;
        }
        if (map[x][j] == ' ')
            break;
        j++;
    }
    
    j = y;
    while(map[x][j])
    {
        if (map[x][j] == '1' )
        {
            check++;
            break;
        }
        if (map[x][j] == ' ')
            break;
        j--;
    }
    if (check == 2)
        return 1;
    return (0);
}

int check_zero2(char **map, int x, int y)
{
    int check = 0;
    int i = x;
    
    while(map[i][y])
    {
        if (map[i][y] == '1')
        {
            check++;
            break;
        }
        if (map[i][y] == ' ')
            break;
        i++;
    }
    i = x;
    while(map[i][y])
    {
        if (map[i][y] == '1' )
        {
            check++;
            break;
        }
        if (map[i][y] == ' ')
            break;
        i--;
    }
    if (check == 2)
        return 1;
    return (0);
}

int first_last_line(char **map)
{
    size_t i;
    int j;

    j = 0;
    i = tab_size(map) - 1;
    printf("%zu\n", i);
    while (map[0][j])
    {
        if (map[0][j] != '1' && map[0][j] != ' ')
            return (0);
        j++;
    }
    j = 0;
    while (map[i][j])
    {
        if (map[i][j] != '1' && map[i][j] != ' ')
            return (0);
        j++;
    }
    return (1);
}
int check_zero(char **map)
{
    int i = 0;
    int j = 0;
    
    if (! first_last_line(map))
        return (0);
    while(map[i])
    {
        j = 0;
        while (map[i][j])
        {
            if (map[i][j] == '0')
            {
                if (j > ((int)ft_strlen(map[i - 1])) || j > ((int)ft_strlen(map[i + 1])))
                    return (0);
                //printf("%d, %d\n", i ,j);
                if (!check_zero1(map, i, j) || !check_zero2(map, i, j))
                {
                    
                    return (0);
                }
            }
            j++;
        }
        i++;
    }
    return (1);
}

int check_N(char **map)   //n被包围
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
    {
        printf("%d\n", n);
        return (0);
    }
    return (1);
}
    

int find_N(char **map, t_parsing parsing)
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
            if (map[i][j] == 'N' && check_N(map) && check_zero1(map, i, j) && check_zero2(map, i, j))
            {
                parsing.N_y = j;
                parsing.N_x = i;
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

void parsing_map(t_cub3d *cub3d, t_parsing parsing)
{
    t_list *tmp1 = NULL;
    tmp1 = sepa_map(cub3d->dataMap);
    tmp1 = tmp1->next;
    cub3d->map = lst_to_tab(tmp1);
    int i = 0;
    while(cub3d->map[i])
    {
        printf("%s\n", cub3d->map[i]);
        i++;
    }
    if (!check_zero(cub3d->map))
       _exit_("Error\n", "map is wrong!\n", FAILURE);
    if (!find_N(cub3d->map, parsing))
        _exit_("Error\n", "N is wrong!\n", FAILURE);
    if (!check_N(cub3d->map))
         _exit_("Error\n", "N is wrong!\n", FAILURE);
   
}