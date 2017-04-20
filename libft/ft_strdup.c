/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/05 17:25:17 by gphilips          #+#    #+#             */
/*   Updated: 2016/11/19 15:34:14 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strdup(const char *s)
{
	char	*dest;

	dest = (char*)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (dest == NULL)
		return (NULL);
	dest = ft_strcpy(dest, s);
	return (dest);
}
