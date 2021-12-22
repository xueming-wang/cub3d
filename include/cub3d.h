/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:05:00 by xuwang            #+#    #+#             */
/*   Updated: 2021/12/22 20:36:39 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>

#define FAILURE 1
#define SUCCESS 0

typedef struct s_parsing
{
    int fd;
    int read;
    char *line;
    int N_x;
    int N_y;
    
}t_parsing;

typedef struct s_map
{
    int i;
    t_list *tmp;
    char *str;
    int tab[6];
    
}t_map;

typedef struct s_cub3d
{
    t_list *dataMap;
    char **map;
    
}t_cub3d;

int main(int ac, char **av);

/* parsing */
void parsing_texinfo(t_cub3d *cub3d);
int first_last_line(char **map);
void ft_parsing(char *av, t_cub3d *cub3d, t_parsing parsing);
int tab_size(char **src);
t_list *sepa_map(t_list *list);
void parsing_map(t_cub3d *cub3d, t_parsing parsing);
int check_horizont(char **map, int x, int y);
int check_vertic(char **map, int x, int y);
int first_last_line(char **map);

/*exit*/
void free_tab(char **tab);
void free_cub3d(t_cub3d *cub3d);
void _exit_(char *s1, char *s2, int ret);
void free_list(t_list *list);

#endif 