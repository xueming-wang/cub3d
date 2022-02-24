/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exit.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/15 16:11:25 by xuwang            #+#    #+#             */
/*   Updated: 2022/02/24 15:38:03 by xuwang           ###   ########.fr       */
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

/* mlx_destroy_display() does not exist on macOS */
#if defined(__APPLE__) && defined(__MACH__)

void	exit_clean(t_cub3d *cub)
{
	int	i;

	if (cub)
	{
		i = 0;
		while (i < TEXTURE_MAX)
		{
			if (cub->tex_img[i].img_ptr)
				mlx_destroy_image(cub->mlx, cub->tex_img[i].img_ptr);
			i++;
		}
		if (cub->mlx_img.img_ptr)
			mlx_destroy_image(cub->mlx, cub->mlx_img.img_ptr);
		if (cub->mlx)
			mlx_destroy_window(cub->mlx, cub->win);
		_free((void **)&cub->mlx);
		if (cub->datamap)
			ft_lstclear(&cub->datamap, free);
		i = 0;
		if (cub->config)
		{
			while (cub->config[i])
				_free((void **)&cub->config[i++]);
			free(cub->config);
		}
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
		_free((void **)&cub);
	}
}

#else

void	exit_clean(t_cub3d *cub)
{
	int	i;

	if (cub)
	{
		i = 0;
		while (i < TEXTURE_MAX)
		{
			if (cub->tex_img[i].img_ptr)
				mlx_destroy_image(cub->mlx, cub->tex_img[i].img_ptr);
			i++;
		}
		if (cub->mlx_img.img_ptr)
			mlx_destroy_image(cub->mlx, cub->mlx_img.img_ptr);
		if (cub->mlx)
			mlx_destroy_window(cub->mlx, cub->win);
		mlx_destroy_display(cub->mlx);
		_free((void **)&cub->mlx);
		if (cub->datamap)
			ft_lstclear(&cub->datamap, free);
		i = 0;
		if (cub->config)
		{
			while (cub->config[i])
				_free((void **)&cub->config[i++]);
			free(cub->config);
		}
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
		_free((void **)&cub);
	}
}

#endif

void	_exit_(char *s1, char *s2, int ret, t_cub3d *cub)
{
	if (s1)
		ft_putstr(s1);
	if (s2)
		ft_putstr(s2);
	exit_clean(cub);
	exit(ret);
}
