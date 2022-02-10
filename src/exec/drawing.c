/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   drawing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 11:56:29 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/10 12:11:12 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	draw_side(t_line *line, double wall_x, t_raycast *ray, t_cub3d *cub3d)
{
	t_img const	tex_view_by_player[TEXTURE_MAX] = {
		cub3d->tex_img[e_EA],
		cub3d->tex_img[e_WE],
		cub3d->tex_img[e_SO],
		cub3d->tex_img[e_NO]
	};
	int			tex_x;
	t_img		tex;
	int			i;

	tex = tex_view_by_player[e_NO];
	i = 0;
	while (++i < TEXTURE_MAX)
		if (i == ray->side)
			tex = tex_view_by_player[i];
	tex_x = (int)(wall_x * (double)tex.width);
	if ((ray->side == 0 || ray->side == 1) && ray->ray_dir_x > 0)
		tex_x = tex.width - tex_x - 1;
	if ((ray->side == 2 || ray->side == 3) && ray->ray_dir_y < 0)
		tex_x = tex.width - tex_x - 1;
	line->start = ray->draw_start;
	line->end = ray->draw_end;
	line->tex_x = tex_x;
	text_vertic(line , text, ray, &cub3d->mlx_img);
}

static void	draw_ceiling_floor(t_line *line, t_raycast *ray, t_cub3d *cub3d)
{
	unsigned char const	*c = cub3d->mapinfo.c_couleur;
	unsigned char const	*f = cub3d->mapinfo.f_couleur;

	line->start = 0;
	line->end = ray->draw_start;
	fill_color_vertically(line, create_rgb(c[0], c[1], c[2]));
	line->start = ray->draw_end;
	line->end = W_HEIGHT;
	fill_color_vertically(line, create_rgb(f[0], f[1], f[2]));
}

void	drawing(t_raycast *ray, t_cub3d *cub3d)
{
	t_line			line;
	double			wall_x;

	ft_bzero(&line, sizeof(t_line));
	line.line_x = ray->pix;
	if (ray->side == 0 || ray->side == 1)
		wall_x = ply.pos_y + ray->perp_wall_dist * ray->ray_dir_y;
	else
		wall_x = ply.pos_x + ray->perp_wall_dist * ray->ray_dir_x;
	wall_x -= floor(wall_x);
	if (cub3d->mapinfo.map[ray->map_y][ray->map_x] == '1')
		draw_side(&line, wall_x, ray, cub3d);
	draw_ceiling_floor(&line, ray, cub3d);
}