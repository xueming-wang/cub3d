/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:04:12 by xuwang            #+#    #+#             */
/*   Updated: 2021/12/16 18:01:03 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
 // 确认 皮肤信息
static int check_nbr(char *str)
{
    int i;

    i = 0;
    while (str[i])
    {
        if (str[i] != ' ' && str[i] != ',' && !ft_isdigit(str[i]))
            return (0);
    }
    return (1);
}
static int check_nbr2(char *str)
{
    int i;
    int nbr;

    if (!check_nbr(str))
        return (0);
    nbr = ft_atoi(str);
    if (nbr >= 0 && nbr <= 225)
        return (1);
    return (0);
}

static int check_name(char *str, int i)
{   
    char **tab;
    int len;
    int fd;

    fd = 0;
    tab = ft_split(str, ' '); //分成no 和 ./path_to_the_north_texture
    len = sizeof(len)/sizeof(tab[0]);
    if (strcmp(tab[0], "NO") == 0 || strcmp(tab[0], "WE") == 0 || strcmp(tab[0], "SO") == 0 || strcmp(tab[0], "EA") == 0)
    {
        if (len == 2)
        {
            fd = open(tab[1], O_RDONLY);
            if(fd >=0 )
            {
                close(fd);
                return(1));
            }
        }
    }
    else if (strcmp(tab[0], "F") == 0 || strcmp(tab[0], "C") == 0)
    {
        
    }
    return (0);
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
