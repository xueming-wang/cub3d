/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit_util.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/24 16:53:12 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/24 17:06:58 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	free_tab(char **tab)
{
	int	i;

	i = 0;
	while (tab[i])
	{
		free(tab[i]);
		i++;
	}
	_free((void **)&tab);
	tab = NULL;
}

void	_free(void **to_free)
{
	free(*to_free);
	*to_free = NULL;
}

void	free_tex(t_cub3d *cub, int i)
{
	i = 0;
	while (i < TEXTURE_MAX)
	{
		if (cub->tex_img[i].img_ptr)
			mlx_destroy_image(cub->mlx, cub->tex_img[i].img_ptr);
		i++;
	}
}

void	free_config(t_cub3d *cub, int i)
{
	i = 0;
	if (cub->config)
	{
		while (cub->config[i])
			_free((void **)&cub->config[i++]);
		free(cub->config);
	}
}

void	free_mapinfo(t_cub3d *cub, int i)
{
	i = 0;
	if (cub->mapinfo.map)
	{
		while (i < TEXTURE_MAX)
		{
			if (cub->mapinfo.texture[i])
				_free((void **)&cub->mapinfo.texture[i]);
			i++;
		}
		free(cub->mapinfo.map);
	}
}
