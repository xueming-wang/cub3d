/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:18:13 by xuwang            #+#    #+#             */
/*   Updated: 2021/12/15 17:09:59 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//确认是不是文件名字
int parsing_filename(char *av)
{
    int i;
    
    i = ft_strlen(av);
    while (av[i] != '.')
        i--;
    if (i = 0)
        _exit_("Error\n", "File Name is Wrong!\n", FAILURE);
    i++;
    if(ft_strcmp((av + i), "cub") != 0)
        _exit_("Error\n", "File Name is Wrong!\n", FAILURE);
    return (1);
} 

//获取文件数据
void parsing_file(char *av, t_cub3d *cub3d)
{
    t_parsing parsing;
    
    ft_bzero(&parsing, sizeof(t_parsing));
    parsing.read = 1;
    if (av)
        parsing_filename(av);
    parsing.fd = open(av, O_RDONLY);
    if (parsing.fd < 0)
        _exit_("Error\n", "Map Not Exist!\n", FAILURE);
    while (parsing.read)
    {
        parsing.read = get_next_line(parsing.fd, &parsing.line);
        cub3d->data[i++] = ft_strdup(parsing.line);
        free(parsing.line);    
    }    
    close(parsing.fd);
}