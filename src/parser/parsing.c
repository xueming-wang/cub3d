/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:18:13 by xuwang            #+#    #+#             */
/*   Updated: 2021/12/17 18:35:53 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

//确认是不是文件名字
void parsing_filename(char *av)
{
    int i;

    i = 0;
    if(ft_strrchr(av, '.') == NULL)
        _exit_("Error\n", "11File Name is Wrong!\n", FAILURE);
    while (av[i] != '.' )
        i++;
    if(ft_strcmp(av + i, ".cub") != 0)
    {   
        _exit_("Error\n", "222File Name is Wrong!\n", FAILURE);
    }
} 

//获取文件数据到data
void parsing_file(char *av, t_cub3d *cub3d)
{
    t_parsing parsing;
   
    ft_bzero(&parsing, sizeof(t_parsing));
    parsing.read = 1;
    parsing.fd = -1;
    parsing_filename(av);
    parsing.fd = open(av, O_RDONLY);
    if (parsing.fd < 0)
         _exit_("Error\n", "Cannot open file!\n", FAILURE);
    while (parsing.read > 0)
    {
        parsing.read = get_next_line(parsing.fd, &parsing.line);
        if (parsing.line[0] != '\0')
            ft_lstadd_back(&cub3d->dataMap, ft_lstnew(ft_strdup(parsing.line)));
        free(parsing.line);
    }  
    close(parsing.fd);
}
void parsing(char *av, t_cub3d *cub3d)
{
    parsing_file(av, cub3d);
    check_texinfo(cub3d);
    //check_map();
}