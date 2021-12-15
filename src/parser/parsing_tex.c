/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:04:12 by xuwang            #+#    #+#             */
/*   Updated: 2021/12/15 19:43:02 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"
 // 确认 皮肤信息

static int check_espace(char *str)
{
    int i;
    int count;

    i = 0;
    count = 0;
    while (str[i] == ' ')
        i++;
    while (str[i])
    {
        if (str[i] == ' ')
        {   
            count++;
            while(str[i + 1] == ' ')
                i++;
        }
        i++;
    }
    if (count > 1)
        return (0);
    return (1);
}

static char **str_to_tab(char *line, int i)
{
    char **tab;
    
    if (i == 1)
    {
        if (!check_espace(line))
            return NULL;
    }
    else
    {
        if (line)
            tab = ft_split(line);
    }
    return (tab);
}
static int check_name(char *tab)
{   
    int i;
    
    i = 0;
    if (ft_strncmp(tab[i], "NO", 2) != 0 && ft_strncmp(tab[i], "SO", 2) != 0 && ft_strncmp(tab[i], "WE", 2) != 0
        ft_strncmp(tab[i], "EA", 2) != 0 && ft_strncmp(tab[i], "F", 1) != 0 && ft_strncmp(tab[i], "C", 1) != 0) 
        return (0);    
    return (1);
}

static int check_file(char *tab)
{
    int fd;

    fd = 0;
    fd = open(tab, O_RDONLY);
    if (fd < 0)
        return (0);
    return (1);
}

int check_texinfo(char *str)
{
    if (!str)
        return (0);
    str_to_tab(str, ) == NULL)
        return (0);
    if (!check_name(tab[0]))
        return (0); //确认名字
    if (!check_file(tab[1]))
        return (0); //确认文件打开;
    return (1);
}
