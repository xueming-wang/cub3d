/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:11:25 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/14 14:44:54 by xuwang           ###   ########.fr       */
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

void mlx_img_clean (t_cub3d *cub3d)
{
    if (cub3d->mlx_img.img_ptr != NULL)
        mlx_destroy_image(cub3d->mlx, cub3d->mlx_img.img_ptr);
}

void tex_img_clean(t_cub3d *cub3d)
{
    int i = 0;
    while(i < TEXTURE_MAX)
    {
        if(cub3d->tex_img[i].img_ptr != NULL)
            mlx_destroy_image(cub3d->mlx, cub3d->tex_img[i].img_ptr);
        i++;
    }
}

void free_cub3d(t_cub3d *cub3d)
{
    mlx_img_clean(cub3d);
    tex_img_clean(cub3d);
    if (cub3d)
    {
        if (cub3d->dataMap)
            free_list(cub3d->dataMap);
        if (cub3d->config)
            free_tab(cub3d->config);
        free(cub3d);
        cub3d = NULL;
    }
}


void exit_mlx(char *s1, int ret, t_cub3d *cub3d)
{
    if (s1)
        ft_putstr(s1);
    free_cub3d(cub3d);
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