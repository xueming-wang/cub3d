/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_mapinfo.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 20:02:43 by xuwang            #+#    #+#             */
/*   Updated: 2021/12/28 16:13:02 by xuwang           ###   ########.fr       */
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
            cub3d->mapinfo.map[j++] = cub3d->config[i++];
    }
    cub3d->mapinfo.map[j] = NULL;
}

void set_text_path(t_cub3d *cub3d, char *str)
{
    static int i = 0;

    if (i < TEXTURE_MAX)
        cub3d->mapinfo.texture[i++] = str;
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
    }
    if (str[setcouleur.i] == 'C')
    {
        setcouleur.tab = ft_split((str + setcouleur.i + 1), ',');
        while (setcouleur.tab && setcouleur.tab[setcouleur.j] && setcouleur.k < 3)
        {
            setcouleur.nbr = ft_atoi(setcouleur.tab[setcouleur.j++]);
            cub3d->mapinfo.c_couleur[setcouleur.k++] = setcouleur.nbr;
        }
    }
}