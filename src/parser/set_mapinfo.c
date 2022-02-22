/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mapinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:02:43 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/22 16:58:52 by xuwang           ###   ########.fr       */
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
    cub3d->mapinfo.map = ft_calloc(sizeof(char *), len + 1);
    if (!cub3d->mapinfo.map)
        return ;
    i = 0;
    while (cub3d->config[i])
    {
        if (cub3d->config[i][0] == '\0')
            i++;
        else
            cub3d->mapinfo.map[j++] = cub3d->config[i++];
    }
    cub3d->mapinfo.map[j] = NULL;
}

void set_text_path(t_cub3d *cub3d, char *str1, char *str2)
{
    static int i = 0;

    if (i < TEXTURE_MAX && ft_strcmp(str2, "NO") == 0)
        cub3d->mapinfo.texture[0] = str1;
    else if (i < TEXTURE_MAX && ft_strcmp(str2, "SO") == 0)
        cub3d->mapinfo.texture[1] = str1;
    else if (i < TEXTURE_MAX && ft_strcmp(str2, "WE") == 0)
        cub3d->mapinfo.texture[2] = str1;
    else if (i < TEXTURE_MAX && ft_strcmp(str2, "EA") == 0)
        cub3d->mapinfo.texture[3] = str1;
}


void set_couleur(t_cub3d *cub3d, char *str)
{
    t_SetCouleur setcouleur;
    
    ft_bzero(&setcouleur, sizeof(t_SetCouleur));
    while (str[setcouleur.i] && str[setcouleur.i] == ' ' )
        setcouleur.i++;
    if (str[setcouleur.i] == 'F')
    {
        setcouleur.tab = ft_split((str + setcouleur.i + 1), ',');
        while (setcouleur.tab && setcouleur.tab[setcouleur.j] && setcouleur.k < 3)
        {
            setcouleur.nbr = ft_atoi(setcouleur.tab[setcouleur.j++]);
            cub3d->mapinfo.f_couleur[setcouleur.k++] = setcouleur.nbr;
        }
        free_tab(setcouleur.tab);
    }
    if (str[setcouleur.i] == 'C')
    {
        setcouleur.tab = ft_split((str + setcouleur.i + 1), ',');
        while (setcouleur.tab && setcouleur.tab[setcouleur.j] && setcouleur.k < 3)
        {
            setcouleur.nbr = ft_atoi(setcouleur.tab[setcouleur.j++]);
            cub3d->mapinfo.c_couleur[setcouleur.k++] = setcouleur.nbr;
        }
         free_tab(setcouleur.tab);
    }
}