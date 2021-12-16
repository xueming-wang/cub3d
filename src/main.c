/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:40:09 by xuwang            #+#    #+#             */
/*   Updated: 2021/12/16 19:42:03 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
    t_cub3d *cub3d;
    
    if (ac != 2)
        _exit_("Error\n", "bad args", FAILURE);
    cub3d = ft_malloc(sizeof(t_cub3d), 1);
    if (!cub3d)
        _exit_("Error\n", "Malloc Error", FAILURE);
    parsing(av[1], cub3d);
    free_list(cub3d->dataMap);
    free(cub3d);
    return (SUCCESS);
}