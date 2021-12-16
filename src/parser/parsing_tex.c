/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:04:12 by xuwang            #+#    #+#             */
/*   Updated: 2021/12/16 20:03:06 by xuwang           ###   ########.fr       */
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
        if (str[i] != ' ' && !ft_isdigit(str[i]))
            return (0);
    }
    return (1);
}
static int check_nbr2(char *str)
{
    int nbr;

    if (!check_nbr(str))
        return (0);
    nbr = ft_atoi(str);
    if (nbr >= 0 && nbr <= 225)
        return (1);
    return (0);
}

static int check_name(char *str)
{   
    char **tab;
    int len;
    int fd;
    int i;

    i = 0;
    fd = -1;
    while(str[i] == ' ')
        i++;
    if (ft_strncmp(str + i, "NO", 2) == 0 || ft_strncmp(str + i, "SO", 2) == 0 ||
        ft_strncmp(str + i, "WE", 2) == 0 || ft_strncmp(str + i, "EA", 2) != 0) 
    {
        tab = ft_split(str, ' ');//分成no 和 ./path_to_the_north_texture
        len = sizeof(len)/sizeof(tab[0]);
        if (len != 2)
            return (0);
        fd = open(tab[1], O_RDONLY);
        if(fd < 0)
        {
            _free_(tab);
            return(0);
        }
        _free_(tab);
        return (1);
    }
    else if (ft_strncmp(str + i, "F", 1) == 0 || ft_strncmp(str + i, "C", 1) == 0)
    {
        tab = ft_split(str + i + 1, ',');
        len = sizeof(len)/sizeof(tab[0]);
        if (len != 3)
            return (0);
        while (tab[i])
        {
            if (!check_nbr2(tab[i]))
            {
                _free_(tab);
                return (0);
            }
            i++;
        }
        _free_(tab);
        return (1);
    }
    else
        return (0);
}
int check_texinfo(t_cub3d *cub3d)
{

    while (cub3d->dataMap)
    {
        if (!(check_name(cub3d->dataMap->content)))
            return (0);
        cub3d->dataMap = cub3d->dataMap->next;
    }
    return (1);
}
