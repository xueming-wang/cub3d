/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   util.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:11:25 by xuwang            #+#    #+#             */
/*   Updated: 2021/12/15 16:45:07 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

// void print_error(char *s1, char *s2, int fd)
// {
//     if (s1)
//         ft_putstr_fd(s1, fd);
//     if (s2)
//         ft_putstr_fd(s2, fd);
//     ft_putstr_fd("\n", fd);
// }

// void _free_(void)
// {
    
// }

void _exit_(char *s1, char *s2, int ret)
{
    if (s1)
        ft_putstr(s1);
    if (s2)
        ft_putstr(s2);
    //_free_();
    return(ret);
}