/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:05:00 by xuwang            #+#    #+#             */
/*   Updated: 2021/12/28 16:50:07 by xuwang           ###   ########.fr       */
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

#define TEXTURE_MAX 4
#define COULEUR_MAX 3


typedef struct s_parsing
{
    int fd;
    int read;
    char *line;
    int N_x;
    int N_y;
    
}t_parsing;

typedef struct s_setCouleur
{
    int i;
    char **tab;
    int nbr;
    int j;
    int k;
    
}t_SetCouleur;

typedef struct s_parsing_map
{
    int i;
    t_list *tmp;
    char *str;
    int tab[6];

}t_parsing_map;

typedef struct s_cmap
{
    char **map;
    char *texture[TEXTURE_MAX];
    int f_couleur[COULEUR_MAX];
    int c_couleur[COULEUR_MAX];
    
}t_map;

typedef struct s_cub3d
{
    t_list *dataMap;
    char **config;
    t_map mapinfo;
    
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
void text_count(t_parsing_map *map);
int check_dup(t_list *list);
int check_text(char *str, t_cub3d *cub3d);
void map_after_parser(t_cub3d *cub3d);
void set_couleur(t_cub3d *cub3d, char *str);
void set_text_path(t_cub3d *cub3d, char *str1, char *str2);

/*exit*/
void free_tab(char **tab);
void free_cub3d(t_cub3d *cub3d);
void _exit_(char *s1, char *s2, int ret);
void free_list(t_list *list);
void free_texture(t_cub3d *cub3d);

#endif 