/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:18:13 by xuwang            #+#    #+#             */
/*   Updated: 2021/12/22 18:04:23 by xuwang           ###   ########.fr       */
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
        _exit_("Error\n", "222File Name is Wrong!\n", FAILURE);
}

void parsing_file(char *av, t_cub3d *cub3d, t_parsing parsing)
{
    parsing.read = 1;
    parsing.fd = -1;
    parsing_filename(av);
    parsing.fd = open(av, O_RDONLY);
    if (parsing.fd < 0)
         _exit_("Error\n", "Cannot open file!\n", FAILURE);
    while (parsing.read > 0)
    {
        parsing.read = get_next_line(parsing.fd, &parsing.line);
        // if (parsing.line[0] != '\0')
        ft_lstadd_back(&cub3d->dataMap, ft_lstnew(ft_strdup(parsing.line)));
        free(parsing.line);
    }  
    close(parsing.fd);
}

t_list *sepa_map(t_list *list)
{
    int i;
    int tab[6] = {0};
   
    t_list *sepa;
    sepa = list;
    char *str = NULL;

    while (sepa && sepa->content)
    {
        i = 0;
        str = (char *)sepa->content;
        while (str[i] == ' ' && str[i])
            i++;
        if (ft_strncmp(str + i, "NO", 2) == 0)
            tab[0] += 1;
        else if (ft_strncmp(str + i, "SO", 2) == 0)
            tab[1] += 1;
        else if (ft_strncmp(str + i, "WE", 2) == 0)
            tab[2] += 1;
        else if (ft_strncmp(str + i, "EA", 2) == 0)
            tab[3] += 1;
        else if (ft_strncmp(str + i, "F", 1) == 0)
            tab[4] += 1;
        else if (ft_strncmp(str + i, "C", 1) == 0)
            tab[5] += 1;
        if (tab[0] == 1 && tab[2] == 1 && tab[3] == 1 && tab[4] == 1 && tab[5] == 1)
            break;
        sepa = sepa->next;
    }
    return (sepa);
}

void ft_parsing(char *av, t_cub3d *cub3d, t_parsing parsing)
{
    parsing_file(av, cub3d, parsing);
    parsing_texinfo(cub3d);
    parsing_map(cub3d, parsing);
}