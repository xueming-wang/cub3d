/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/17 18:26:07 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/16 13:06:38 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int tab_size(char **src)
{
    int i = 0;

    while (src != NULL && src[i] != NULL)
        ++i;
    return (i);
}
char **lst_to_tab(t_list *list)
{
    char **map;
    int len;
    int i;
    t_list *tmp;
    
    i = 0;
    len = ft_lstsize(list);
    map = malloc(sizeof(char *) * (len + 1));
    if (!map)
        return (NULL);
    tmp = list;
    while (tmp && i < len)
    {
        map[i] = ft_strdup((char *)tmp->content);
        tmp = tmp->next;
        i++;   
    } 
    map[i] = NULL;
    return (map);
}

int check_c(char c)
{
    if (c != '0' && c != '1' && c != ' ' && c != 'N' && c != 'S' && c != 'W'  && c != 'E')
        return (0);
    return (1);
}