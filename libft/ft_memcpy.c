/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 14:59:53 by gphilips          #+#    #+#             */
/*   Updated: 2016/11/18 15:58:08 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*cpy;
	char	*source;
	size_t	i;

	cpy = (char*)dest;
	source = (char*)src;
	i = 0;
	while (i < n)
	{
		cpy[i] = source[i];
		i++;
	}
	return (dest);
}
