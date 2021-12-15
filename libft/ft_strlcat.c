/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/18 16:13:46 by xuwang            #+#    #+#             */
/*   Updated: 2021/05/22 15:35:20 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	j;
	size_t	len_src;

	i = 0;
	j = 0;
	len_src = ft_strlen(src);
	while (dst[i] && i < dstsize)
		i++;
	if (dstsize > 0)
	{
		while (src[j] && i < dstsize - 1)
			dst[i++] = src[j++];
	}
	if (j != 0)
	{
		dst[i] = '\0';
		return (len_src + (i - j));
	}
	return (len_src + i);
}
