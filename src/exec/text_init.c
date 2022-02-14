/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   text_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/10 14:21:30 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/14 15:11:37 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

static void	set_tex(t_img *img, int index, t_cub3d *cub3d)
{
	//printf("%s\n", cub3d->mapinfo.texture[index]);
	img->img_ptr = mlx_xpm_file_to_image(cub3d->mlx, cub3d->mapinfo.texture[index],
			&img->width, &img->height);
	if (NULL == img->img_ptr)
		exit_mlx("path error", FAILURE, cub3d);
	img->addr = mlx_get_data_addr(img->img_ptr, &img->bpp, &img->size, &img->endian);
}

void	tex_init(t_cub3d *cub3d)
{
	int	i;

	i = 0;
	while (i < TEXTURE_MAX)
	{
		printf("%d\n", cub3d->tex_img[i].width);
		set_tex(&cub3d->tex_img[i], i, cub3d);
		++i;
	}
}