/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:05:00 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/14 12:51:12 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

#include "libft.h"
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <fcntl.h>
#include "mlx.h"
#include <math.h>

# define FAILURE 1
# define SUCCESS 0

# define TEXTURE_MAX 4
# define COLOR_MAX 3

# define NAME "Cub3D"
# define WIN_HEIGHT 800
# define WIN_WIDTH  800
# define PLY_DIR 4
# define KEYMAX 6

# if defined (__APPLE__) && (__MACH__)
#  define KEY_ESC 53
#  define KEY_W 13
#  define KEY_A 0
#  define KEY_S 1
#  define KEY_D 2
#  define KEY_LEFT 123
#  define KEY_RIGHT 124
#  define RED_CROSS 17
# else
#  define KEY_ESC 65307
#  define KEY_W 119
#  define KEY_S 115
#  define KEY_A 97
#  define KEY_D 100
#  define KEY_LEFT 65361
#  define KEY_RIGHT 65363
#  define RED_CROSS 33
# endif

enum e_path
{
	e_NO = 0,
	e_SO,
	e_WE,
	e_EA,
	e_F,
	e_C
};
typedef struct s_parsing
{
    int fd;
    int read;
    char *line;
    // int N_x;
    // int N_y;
    
}t_parsing;

typedef struct s_setCouleur
{
    int i;
    char **tab;
    int nbr;
    int j;
    int k;
    
}t_SetCouleur;

typedef struct s_player
{
	char	direction;
	double	pos_x;
	double	pos_y;
	double	dir_x;
	double	dir_y;
	double	plane_x;
	double	plane_y;
	double	cam_height;
	double	speed;
	double	rot_speed;
    
}	t_player;


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
    unsigned char f_couleur[COLOR_MAX];
    unsigned char c_couleur[COLOR_MAX];
    
}t_map;

typedef struct s_img
{
    void	*img_ptr;
	char	*addr;  
	int		bpp; //bits_per_pixel
	int		size;
	int		endian;
	int		width;
	int		height;
    
}t_img;

typedef struct s_key
{
	int	a;
	int	w;
	int	s;
	int	d;
	int left;
	int right;
}	t_key;

typedef struct s_raycast
{
	int			pix;
	double		cameraX;
	double		raydir_x;  //direction vector
	double		raydir_y;
	int			map_x;
	int			map_y;
	double		sideDist_x;  //length of ray from current position to next x or y-side
	double		sideDist_y;
	double		deltaDist_x; //length of ray from one x or y-side to next x or y-side
	double		deltaDist_y;
	double		perpWallDist;
	int			step_x;
	int			step_y;
	int			hit;  //was there a wall hit?
	int			side;  //was a NS or a EW wall hit?
	int			line_height;
	int			draw_start;
	int			draw_end;
	double		*zbuffer;
}t_raycast;

typedef struct s_line
{
	int		start;
	int		end;
	int		line_x;
	int		line_y;
	int		tex_x;
	int		tex_y;
}	t_line;

typedef struct s_cub3d
{
    t_list *dataMap;
    char **config;
    t_map mapinfo;
	void *win;
    void *mlx;
    t_img mlx_img;
    t_img tex_img[TEXTURE_MAX];
    t_player player;
	t_key key;
	
}t_cub3d;



int main(int ac, char **av);

/* parsing */
void parsing_texinfo(t_cub3d *cub3d);
int first_last_line(char **map);
void ft_parsing(int ac, char *av, t_cub3d *cub3d);
int tab_size(char **src);
t_list *sepa_map(t_list *list);
void parsing_map(t_cub3d *cub3d);
int check_horizont(char **map, int x, int y);
int check_vertic(char **map, int x, int y);
int first_last_line(char **map);
void text_count(t_parsing_map *map);
int check_dup(t_list *list);
int check_text(char *str, t_cub3d *cub3d);
void map_after_parser(t_cub3d *cub3d);
void set_couleur(t_cub3d *cub3d, char *str);
void set_text_path(t_cub3d *cub3d, char *str1, char *str2);

/* exec */
void	start_game(t_cub3d *cub3d);
void player_init(t_cub3d *cub3d);
void  sideDist_init(t_raycast *ray, t_player *player);
void hit_wall(t_raycast *ray, t_cub3d *cub3d);
void  set_perpWallDist(t_raycast *ray, t_player *player);
void set_lineHeight(t_raycast *ray);
void  set_drawinfo(t_raycast *ray, t_player *player);
void  color_vertic(t_line *line, unsigned int const color, t_img *img);
void text_vertic(t_line *line , t_img text, t_raycast *ray, t_img *img);
void player_move_w(t_cub3d *cub3d, t_player *player);
void player_move_a(t_cub3d *cub3d, t_player *player);
void player_move_s(t_cub3d *cub3d, t_player *player);
void player_move_d(t_cub3d *cub3d, t_player *player);
void	player_rotate_left(t_player *player);
void	player_rotate_right(t_player *player);
void 	do_raycasting(t_cub3d *cub3d);
void	drawing(t_raycast *ray, t_cub3d *cub3d);
int		key_press(int keycode, t_cub3d *cub3d);
int		key_release(int keycode, t_cub3d *cub3d);
void	key_control(t_cub3d *cub3d);
void	tex_init(t_cub3d *cub3d);
void	drawing(t_raycast *ray, t_cub3d *cub3d);


/*exit*/
void free_tab(char **tab);
void free_cub3d(t_cub3d *cub3d);
void _exit_(char *s1, char *s2, int ret);
void free_list(t_list *list);
void free_texture(t_cub3d *cub3d);
void exit_mlx(char *s1, int ret, t_cub3d *cub3d);

#endif 