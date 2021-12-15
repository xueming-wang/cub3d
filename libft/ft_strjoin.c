/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: xuwang <xuwang@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/24 21:42:57 by xuwang            #+#    #+#             */
/*   Updated: 2021/07/01 20:06:43 by xuwang           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*tab;
	size_t	len;
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (!s1 || !s2)
		return (NULL);
	len = ft_strlen(s1) + ft_strlen(s2) + 1;
	tab = (char *)malloc(sizeof(char) * len);
	if (!tab)
		return (NULL);
	while (i < len && s1[i])
	{
		tab[i] = s1[i];
		i++;
	}
	while (i < len && s2[j])
		tab[i++] = s2[j++];
	tab[i] = '\0';
	return (tab);
}
