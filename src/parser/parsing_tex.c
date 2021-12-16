/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:04:12 by xuwang            #+#    #+#             */
/*   Updated: 2021/12/16 17:08:34 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
 // 确认 皮肤信息

 [     aaa     ,cc,bbb       ]
 sp -> ,
 [  225aa   ]
 [,]
 [  1cc  ]
 [.]
 [bbb]
static int check_nbr(char *str)
{
    int i;
    char **tab;
    int len;
    int nbr;
    
    i = 0;
    tab = ft_split(str, ",");
    len = sizeof(len)/sizeof(tab[0]);
    if (len != 3)
        return (0);
    while(tab[i])
    {
        
        nbr = ft_atoi(tab[i]);
        if (nbr < 0 || nbr > 225)
            return (0);
        i++;
    }
    free(tab);
    return (1);
}

static int check_name(char *str, int i)
{   
    char **tab;
    int len;
    int fd;

    fd = 0;
    tab = ft_split(str, ' '); //分成no 和 ./path_to_the_north_texture
    len = sizeof(len)/sizeof(tab[0]);
    if (len != 2)
        return (0);
    if (i == 1)
    {   
        if (strcmp(tab[0], "NO") != 0 && strcmp(tab[0], "WE") != 0 && strcmp(tab[0], "SO") != 0 && strcmp(tab[0], "EA") != 0)
            return (0);
        fd = open(tab[1], O_RDONLY);
        if(fd < 0)
            return (0);
        close(fd);
    }
    else
    {
        if (strcmp(tab[0], "F") != 0 && strcmp(tab[0], "C") != 0)
            return (0);
        check_nbr(tab[1])
            return (0);
    }
    return (1);
}
int check_texinfo(t_cub3d *cub3d, int i)
{
    while (cub3d->dataMap)
    {
       check_name(cub3d)
        
       

        
        free(tab);
        cub3d->dataMap = cub3d->dataMap->next;
    }
}
