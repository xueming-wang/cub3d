/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:40:09 by xuwang            #+#    #+#             */
/*   Updated: 2021/12/20 16:53:54 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
    t_cub3d *cub3d;
    t_parsing parsing;
    
    ft_bzero(&parsing, sizeof(t_parsing));
    if (ac != 2)
        _exit_("Error\n", "bad args", FAILURE);
    cub3d = ft_calloc(1, sizeof(t_cub3d));
    if (!cub3d)
        _exit_("Error\n", "Malloc Error", FAILURE);
    
    ft_parsing(av[1], cub3d, parsing);
    printf("[PARSING OK]\n");
    free_list(cub3d->dataMap);
    free(cub3d);
    return (SUCCESS);
    
}