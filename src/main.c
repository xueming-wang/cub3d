/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@42.student.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/16 18:40:09 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/08 11:58:42 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int main(int ac, char **av)
{
    t_cub3d *cub3d;
    
    cub3d = ft_calloc(1, sizeof(t_cub3d));
    if (!cub3d)
        _exit_("Error\n", "Malloc Error", FAILURE);
    ft_parsing(av[1], cub3d, parsing);
    printf("[PARSING OK]\n");
    free_cub3d(cub3d);
    return (SUCCESS); 
}