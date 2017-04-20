/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:52:21 by gphilips          #+#    #+#             */
/*   Updated: 2016/11/18 16:05:23 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t	i;

	i = 0;
	if (s2[i] == '\0' || !s2)
		return ((char*)s1);
	while (s1[i])
	{
		if (ft_memcmp(&s1[i], s2, ft_strlen(s2)) == 0)
			return ((char*)(&s1[i]));
		i++;
	}
	return (NULL);
}
