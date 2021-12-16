/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:18:13 by xuwang            #+#    #+#             */
/*   Updated: 2021/12/16 20:33:05 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//确认是不是文件名字
int parsing_filename(char *av)
{
    if(ft_strrchr(av, '.') == NULL)
        _exit_("Error\n", "File Name is Wrong!\n", FAILURE);
    if(ft_strcmp(av, "cub") != 0)
        _exit_("Error\n", "File Name is Wrong!\n", FAILURE);
    return (1);
} 

//获取文件数据到data
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
        ft_lstadd_back(&cub3d->dataMap, ft_lstnew(ft_strdup(parsing.line)));
        free(parsing.line);
    }    
    close(parsing.fd);
}

void parsing(char *av, t_cub3d *cub3d)
{
    parsing_file(av, cub3d);
    check_texinfo(cub3d);

   
}