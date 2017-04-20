/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:51:12 by gphilips          #+#    #+#             */
/*   Updated: 2016/11/18 16:04:43 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	len;

	len = ft_strlen(s2);
	if (*s2 == '\0')
		return ((char*)s1);
	while (*s1 && n >= len)
	{
		if (*s1 == *s2 && ft_memcmp(s1, s2, len) == 0)
			return ((char*)s1);
		s1++;
		n--;
	}
	return (NULL);
}
