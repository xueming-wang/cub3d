/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:11:25 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/18 16:53:18 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_list(t_list *list)
{
    if (list)
        ft_lstclear(&list, free);
}

void free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    free(tab);
    tab = NULL;
}

void free_cub3d(t_cub3d *cub3d)
{
    mlx_img_clean(cub3d);
    tex_img_clean(cub3d);
    
    if (cub3d)
    {
        if (cub3d->set_couleur.tab)
            free_tab(cub3d->set_couleur.tab);
        if (cub3d->dataMap)
            free_list(cub3d->dataMap);
        if (cub3d->config)
            free_tab(cub3d->config);
        if (cub3d->mapinfo.map)
            free_tab(cub3d->mapinfo.map);
        free(cub3d);
        cub3d = NULL;
    }
}


void exit_mlx(char *s1, int ret, t_cub3d *cub3d)
{
    if (s1)
        ft_putstr(s1);
    (void)cub3d;
    //free_cub3d(cub3d);
    exit(ret);
}

void _exit_(char *s1, char *s2, int ret)
{
    if (s1)
        ft_putstr(s1);
    if (s2)
        ft_putstr(s2);
    exit(ret);
}