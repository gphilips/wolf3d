/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:51:22 by gphilips          #+#    #+#             */
/*   Updated: 2016/11/19 15:23:39 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strnew(size_t size)
{
	char	*str;

	if ((int)size < 0)
		return (NULL);
	if (!(str = ft_memalloc(size + 1)))
		return (NULL);
	ft_bzero(str, size);
	str[size] = '\0';
	return (str);
}
