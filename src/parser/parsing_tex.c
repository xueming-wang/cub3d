/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_tex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/27 15:13:36 by xuwang            #+#    #+#             */
/*   Updated: 2021/12/27 16:51:20 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int check_dup(t_list *list)
{
    t_parsing_map dup;
    
    ft_bzero(&dup, sizeof(t_parsing_map));
    dup.tmp = list;
    while (dup.tmp && dup.tmp->content)
    { 
        dup.i = 0;
        dup.str = (char *)dup.tmp->content;
        text_count(&dup);
        dup.tmp = dup.tmp->next;
    }
    if (dup.tab[0] > 1 || dup.tab[2] > 1 || dup.tab[3] > 1 || dup.tab[4] > 1 || dup.tab[5] > 1)
        return (0);
    return (1);
}


void parsing_texinfo(t_cub3d *cub3d)
{
    t_list *tmp = NULL;
    t_list  *tmp2 = NULL;
    tmp2 = cub3d->dataMap;
    int i;
    int j;

    j = 0;
    i = 0;
    tmp = sepa_map(tmp2);
    if (check_dup(tmp2) == 0)
        _exit_("Error\n", "Texinfo duplicate!\n", FAILURE);
    while (tmp2)
    {  
        printf("%s\n", tmp2->content);
        if (check_text(tmp2->content) == 1 && i < TEXTURE_MAX)
        {
            cub3d->map.texture[i] = tmp2->content;
            i++;
        }
        if (check_text(tmp2->content) == 2 && j < COULEUR_MAX)
        {
            cub3d->map.couleur[j] = tmp2->content;
            j++;
        }
        if (!check_text(tmp2->content))
             _exit_("Error\n", "Texinfo is wrong!\n", FAILURE);
        if (tmp == tmp2)
            break;
        tmp2 = tmp2->next;
    }
}

