/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:05:00 by xuwang            #+#    #+#             */
/*   Updated: 2021/12/15 17:09:25 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
#define CUB3D_H

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define FAILURE 1
#define SUCCESS 0

typedef struct s_parsing
{
    int fd;
    int read;
    int len;
    char *line;
    
}t_parsing;

typedef struct s_cub3d
{
    char **data;
    
}t_cub3d;


//void print_error(char *s1, char *s2, int fd);
//void _free_(void);
void _exit_(char *s1, char *s2, int ret);


#endif 