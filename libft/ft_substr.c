/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:42:18 by xuwang            #+#    #+#             */
/*   Updated: 2021/05/25 16:54:01 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*tab;
	size_t	i;
	size_t	s_len;

	if (!s)
		return (NULL);
	s_len = ft_strlen(s);
	tab = (char *)malloc(sizeof(char) * len + 1);
	if (!tab)
		return (NULL);
	i = 0;
	while (i < len && s_len >= start)
	{
		tab[i] = s[start + i];
		++i;
	}
	tab[i] = '\0';
	return (tab);
}
