/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:04:10 by xuwang            #+#    #+#             */
/*   Updated: 2021/12/19 21:17:44 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//1, 必须被强包围 否则返回错误
//2. 地图放在文件的最后

// int check_map(char *str, int first_last_line)
// {
//     int i;
//     int len;
    
//      len = ft_strlen(str);
//     if (first_last_line == 1)
//     {
//         i = 0;
//         while (str[i])
//         {
//             if (str[i] != '1' || str[i] != ' ')
//                 return (0);
//             i++;
//         }
//     }
//     else
//     {
//         if ((str[0] != '1') || (str[len - 1] != '1'))
//             return (0);   
//     }
//     return (1);
// }



int check_zero(char **Map)
{
    int i;
    int j;
    int i_len;
    int j_len;

    i = 0;
    while (Map[i][j])
    {
        j = 0;   
        while (Map[i][j])
        {
            if (Map[i][j] == '0')
            {
            
            }
        }
    }
}

char **tabMap(t_list *list)
{
    char **tabMap;
    int len;
    int i;
    t_list *tmp;
    
    i = 0;
    len = ft_lstsize(list);
    tabMap = malloc(sizeof(char *) * (len + 1));
    if (!tabMap)
        return (NULL);
    tmp = list;
    while (tmp && i < len)
    {
        tabMap[i] = ft_strdup((char *)tmp->content);
        tmp = tmp->next;
        i++;   
    } 
    tabMap[i] = NULL;
    return (tabMap);
}

void parsing_map(t_cub3d *cub3d)
{
    t_list *tmp1 = NULL;
    tmp1 = sepa_map(cub3d->dataMap);
    tmp1 = tmp1->next;
    cub3d->Map = tabMap(tmp1);
    
  
    
    
 
    
}