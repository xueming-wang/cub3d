/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:05:00 by xuwang            #+#    #+#             */
/*   Updated: 2021/12/19 17:39:12 by xuwang           ###   ########.fr       */
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
    
}t_parsing;

// typedef struct s_dup {
//     int id;
//     char *name;
//     int n;
// } t_dup;

typedef struct s_cub3d
{
    t_list *dataMap;
    
}t_cub3d;

//void print_error(char *s1, char *s2, int fd);
/* parsing */
void _free_(char **tab);
void _exit_(char *s1, char *s2, int ret);
void parsing_texinfo(t_cub3d *cub3d);
void parsing(char *av, t_cub3d *cub3d);
int main(int ac, char **av);
void free_list(t_list *list);
int tab_size(char **src);
t_list *sepa_map(t_list *list);
void parsing_map(t_cub3d *cub3d);

#endif 