/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tex_part.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:04:12 by xuwang            #+#    #+#             */
/*   Updated: 2021/12/28 15:56:22 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

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
        if ((str[i] == ' ' && ft_isdigit(str[i + 1])) || (str[i] != ' ' && !ft_isdigit(str[i])))
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
    if (nbr < 0 || nbr > 225)
        return (0);
    return (1);
}

static int info_tex(char *str, int len, char **tab, t_cub3d *cub3d)
{
    int fd;
    static int i = 0;
    
    tab = ft_split(str, ' ');
    len = tab_size(tab);
    if (len != 2)
    {
        free_tab(tab);
        return (0);
    }
    fd = open(tab[1], O_RDONLY);
    if(fd < 0)
    {
        free_tab(tab);
        return(0);
    }
    else
    {
        if (i < TEXTURE_MAX)
            set_text_path(cub3d, ft_strdup(tab[1]));
    }
    free_tab(tab);
    return (1);
}

static int info_tex2(char *str, int len, char **tab, int i)
{
    if (ft_strncmp(str + i + 1, " ", 1) != 0)
        return (0);
    tab = ft_split((str + i + 1), ',');
    len = tab_size(tab);
    if (len != 3)
    {
        free_tab(tab);
        return (0);
    }
    i = 0;
    while (tab[i])
    {
        if (!check_nbr2(tab[i]))
        {
            free_tab(tab);
            return (0);
        }
        i++;
    }
    free_tab(tab);
    return (1);
}

int check_text(char *str, t_cub3d *cub3d)
{   
    char **tab = NULL;
    int len;
    int fd;
    int i;

    i = 0;
    fd = -1;
    len = 0;
    if (str[0] == '\0')
        return 1;
    while(str[i] == ' ' && str[i])
        i++;;
    if (ft_strncmp(str + i, "NO", 2) == 0 || ft_strncmp(str + i, "SO", 2) == 0 ||
        ft_strncmp(str + i, "WE", 2) == 0 || ft_strncmp(str + i, "EA", 2) == 0) 
    {
        if(info_tex(str, len, tab, cub3d))
            return(1);
    }
    else if (ft_strncmp(str + i, "F", 1) == 0 || ft_strncmp(str + i, "C", 1) == 0)
    {
        if(info_tex2(str, len, tab, i))
            return(1);
    }
    return (0);
}
