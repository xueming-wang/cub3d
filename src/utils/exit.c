/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:11:25 by xuwang            #+#    #+#             */
/*   Updated: 2021/12/22 14:30:23 by xuwang           ###   ########.fr       */
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
    if (cub3d)
    {
        if (cub3d->dataMap)
            free_list(cub3d->dataMap);
        if (cub3d->map)
            free_tab(cub3d->map);
        free(cub3d);
        cub3d = NULL;
    }
   
}
void _exit_(char *s1, char *s2, int ret)
{
    if (s1)
        ft_putstr(s1);
    if (s2)
        ft_putstr(s2);
    exit(ret);
}