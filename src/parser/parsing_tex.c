/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:04:12 by xuwang            #+#    #+#             */
/*   Updated: 2021/12/17 20:25:25 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
 // 确认 皮肤信息
static int check_nbr(char *str)
{
    int i;
    int len;

    i = 0;
    len = ft_strlen(str);
    while (str[i] == ' ' && str[i])
        i++;
    if(len == i)
        return (0);
    while (str[i])
    {
        if (str[i] != ' ' && !ft_isdigit(str[i]))
            return (0);
        i++;
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


static int check_info(char *str)
{   
    char **tab = NULL;
    int len;
    int fd;
    int i;

    i = 0;
    fd = -1;
    while(str[i] == ' ' && str[i])
        i++;
    //  printf("%s\n", str);
    if (ft_strncmp(str + i, "NO", 2) == 0 || ft_strncmp(str + i, "SO", 2) == 0 ||
        ft_strncmp(str + i, "WE", 2) == 0 || ft_strncmp(str + i, "EA", 2) == 0) 
    {
        tab = ft_split(str, ' ');//分成no 和 ./path_to_the_north_texture
        len = tab_size(tab);
        if (len != 2)
        {
             _free_(tab);
            return (0);
        }
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
        tab = ft_split((str + i + 1), ',');
        len = tab_size(tab);
        if (len != 3)
        {
            _free_(tab);
            return (0);
        }
        i = 0;
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
    
    return (0);
}

static int check_dup(t_list *list)
{
    int i;
    static int tab[6] = {0};
    char *str = NULL;
    t_list *tmp = list;
    
    while (tmp && tmp->content)
    { 
        i = 0;
        str = (char *)tmp->content;
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
        tmp = tmp->next;
    }
    if (tab[0] > 1 || tab[2] > 1 || tab[3] > 1 || tab[4] > 1 || tab[5] > 1)
        return (0);
    return (1);
}


void check_texinfo(t_cub3d *cub3d)
{
    if (!check_dup(cub3d->dataMap))
        _exit_("Error\n", "Texinfo duplicate!\n", FAILURE);
    while (cub3d->dataMap)
    {   
        if (!check_info(cub3d->dataMap->content))
             _exit_("Error\n", "Texinfo is wrong!\n", FAILURE);
        cub3d->dataMap = cub3d->dataMap->next;
    }
}
