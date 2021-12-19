/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_map.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:04:10 by xuwang            #+#    #+#             */
/*   Updated: 2021/12/19 17:57:02 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//1, 必须被强包围 否则返回错误
//2. 地图放在文件的最后

t_list *sepa_map(t_list *list)
{
    int i;
    static int tab[6] = {0};
    t_list *sepa;
    sepa = list;
    char *str = NULL;
    
    while (sepa && sepa->content)
    { 
        i = 0;
        str = (char *)sepa->content;
        while (str[i] == ' ' && str[i])
            i++;
        if (ft_strncmp(str + i, "NO", 2) == 0)
            tab[0] += 1;
        else if (ft_strncmp(str + i, "SO", 2) == 0)
            tab[1] += 1;
        else if (ft_strncmp(str + i, "WE", 2) == 0)
            tab[2] += 1;
        else if (ft_strncmp(str + i, "EA", 2) == 0)
            tab[3] += 1;
        else if (ft_strncmp(str + i, "F", 1) == 0)
            tab[4] += 1;
        else if (ft_strncmp(str + i, "C", 1) == 0)
            tab[5] += 1;
        if (tab[0] == 1 && tab[2] == 1 && tab[3] == 1 && tab[4] == 1 && tab[5] == 1)
            break;
        sepa = sepa->next;
    }
    return (sepa);
}



void parsing_map(t_cub3d *cub3d)
{
   while(cub3d->dataMap)
   {
       if (cub3d->dataMap == sepa_map(cub3d->dataMap))
            break;
        cub3d->dataMap = cub3d->dataMap->next;
   }
    printf("%s\n", cub3d->dataMap->content);
    
    
 
    
}