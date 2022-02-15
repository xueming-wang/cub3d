/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 15:18:13 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/15 16:59:14 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void parsing_filename(char *av)
{
    int i;

    i = 0;
    if(ft_strrchr(av, '.') == NULL)
        _exit_("Error\n", "File Name is Wrong!\n", FAILURE);
    while (av[i] != '.' )
        i++;
    if(ft_strcmp(av + i, ".cub") != 0)
        _exit_("Error\n", "File Name is Wrong!\n", FAILURE);
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
        ft_lstadd_back(&cub3d->dataMap, ft_lstnew(ft_strdup(parsing.line)));
        free(parsing.line);
    }  
    close(parsing.fd);
}

void text_count(t_parsing_map *map)
{
    while (map->str[map->i] && map->str[map->i] == ' ')
            map->i++;
    if (ft_strncmp(map->str + map->i, "NO", 2) == 0)
        map->tab[0] += 1;
    else if (ft_strncmp(map->str + map->i, "SO", 2) == 0)
        map->tab[1] += 1;
    else if (ft_strncmp(map->str + map->i, "WE", 2) == 0)
        map->tab[2] += 1;
    else if (ft_strncmp(map->str + map->i, "EA", 2) == 0)
        map->tab[3] += 1;
    else if (ft_strncmp(map->str + map->i, "F", 1) == 0)
        map->tab[4] += 1;
    else if (ft_strncmp(map->str + map->i, "C", 1) == 0)
        map->tab[5] += 1;
}

t_list *sepa_map(t_list *list)
{
    t_parsing_map map;
    
    ft_bzero(&map, sizeof(t_parsing_map));
    map.tmp = list;
    while (map.tmp && map.tmp->content)
    {
        map.i = 0;
        map.str = (char *)map.tmp->content;
        text_count(&map);
        if (map.tab[0] == 1 && map.tab[2] == 1 && map.tab[3] == 1 && map.tab[4] == 1 && map.tab[5] == 1)
            break;
        map.tmp = map.tmp->next;
    }
    return (map.tmp);
}

void ft_parsing(int ac, char *av, t_cub3d *cub3d)
{
    t_parsing parsing;
     
    ft_bzero(&parsing, sizeof(t_parsing));
    if (ac != 2)
        _exit_("Error\n", "bad args", FAILURE);
    parsing_file(av, cub3d, parsing);
    parsing_texinfo(cub3d);
    parsing_map(cub3d);
    map_after_parser(cub3d);
    int i = 0;
    while (cub3d->mapinfo.map[i])
    {
        int j = 0;
        while (cub3d->mapinfo.map[i][j])
        {
            printf("%c", cub3d->mapinfo.map[i][j]);
            j++;
        }
         printf("\n");
        i++;
    }
}   
