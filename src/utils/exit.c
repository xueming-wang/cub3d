/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:11:25 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/22 17:06:32 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void free_tab(char **tab)
{
    int i;

    i = 0;
    while (tab[i])
    {
        free(tab[i]);
        i++;
    }
    _free((void **)&tab);
    tab = NULL;
}

// void free_cub3d(t_cub3d *cub3d)
// {   
//     if (cub3d)
//     {
//         mlx_img_clean(cub3d);
//         tex_img_clean(cub3d);
//         if (cub3d->set_couleur.tab)
//             free_tab(cub3d->set_couleur.tab);
//         if (cub3d->dataMap)
//             free_list(cub3d->dataMap);
//         if (cub3d->config)
//             free_tab(cub3d->config);
//         if (cub3d->mapinfo.map)
//         {
//             free_texture(cub3d);
//             free_tab(cub3d->mapinfo.map);
//         }
//         mlx_destroy_window(cub3d->mlx, cub3d->win);
// 	    mlx_destroy_display(cub3d->mlx);
//         // free(cub3d->mlx);
//         free(cub3d);
//         cub3d = NULL;
//     }
// }


// void exit_mlx(char *s1, int ret, t_cub3d *cub3d)
// {
//     if (s1)
//         ft_putstr(s1);
//     (void)cub3d;
//     //free_cub3d(cub3d);
//     exit(ret);
// }

void _free(void **to_free)
{
    free(*to_free);
    *to_free = NULL;
}

void exit_clean(t_cub3d *cub) {
    int i;

    if (cub)
    {
        i = 0;
        while (i < TEXTURE_MAX)
        {
            if (cub->tex_img[i].img_ptr)
                mlx_destroy_image(cub->mlx, cub->tex_img[i].img_ptr);
            i++;
        }
        if (cub->mlx_img.img_ptr)
            mlx_destroy_image(cub->mlx, cub->mlx_img.img_ptr);
        mlx_destroy_window(cub->mlx, cub->win);
		mlx_destroy_display(cub->mlx);
        _free((void **)&cub->mlx);
        if (cub->dataMap)
            ft_lstclear(&cub->dataMap, free);
        i = 0;
        if (cub->config)
        {
            while (cub->config[i])
                _free((void **)&cub->config[i++]);
            free(cub->config);
        }
        i = 0;
        if (cub->mapinfo.map)
        {
            while (i < TEXTURE_MAX)
            {
                if (cub->mapinfo.texture[i])
                    _free((void **)&cub->mapinfo.texture[i]);
                i++;
            }
            free(cub->mapinfo.map);
        }
        _free((void **)&cub);
    }
}

void _exit_(char *s1, char *s2, int ret, t_cub3d *cub)
{
    if (s1)
        ft_putstr(s1);
    if (s2)
        ft_putstr(s2);
    exit_clean(cub);
    exit(ret);
}