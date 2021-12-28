/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mapinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:02:43 by xuwang            #+#    #+#             */
/*   Updated: 2021/12/28 14:22:41 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void map_after_parser(t_cub3d *cub3d)
{
    int len;
    int i;
    int j;

    j = 0;
    i = 0;
    len = 0;
    while (cub3d->config[i])
    {
        if (cub3d->config[i][0] != '\0')
            len++;
        i++;
    }
    cub3d->mapinfo.map = malloc(sizeof(char *) * (len + 1));
    if (!cub3d->mapinfo.map)
        return ;
    i = 0;
    while (cub3d->config[i])
    {
        if (cub3d->config[i][0] == '\0')
            i++;
        else
        {
            cub3d->mapinfo.map[j] = cub3d->config[i];
            j++;
            i++;
        }
    }
    cub3d->mapinfo.map[j] = NULL;
}

void set_text_path(t_cub3d *cub3d, char *str)
{
    static int i = 0;

    if (i < TEXTURE_MAX)
        cub3d->mapinfo.texture[i++] = str;
    //printf("%s\n", cub3d->mapinfo.texture[0]);
  
}

void set_couleur(t_cub3d *cub3d, char *str)
{
    int i;
    char **tab = NULL;
    int nbr;
    int j;
    int k;
    
    k = 0;
    j = 0;
    nbr = 0;
    i = 0;
    while (str[i] && str[i] == ' ' )
        i++;
    if (ft_strncmp(str + i, "F", 1) == 0)
    {
        tab = ft_split((str + i + 1), ',');
        while (tab && tab[j] && k < 3)
        {
            nbr = ft_atoi(tab[j]);
            cub3d->mapinfo.f_couleur[k] = nbr;
            printf("%d\n", cub3d->mapinfo.f_couleur[k]);
            j++;
            k++;
        }
    }
    else if (ft_strncmp(str + i, "C", 1) == 0)
    {
        tab = ft_split((str + i + 1), ',');
        while (tab && tab[j] && k < 3)
        {
            nbr = ft_atoi(tab[j]);
            cub3d->mapinfo.c_couleur[k] = nbr;
             printf("%d\n", cub3d->mapinfo.c_couleur[k]);
            j++;
            k++;
        }
    }
}