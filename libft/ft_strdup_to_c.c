/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup_to_c.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 13:12:00 by gphilips          #+#    #+#             */
/*   Updated: 2017/04/02 13:12:03 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup_to_c(char *str, char c)
{
	char	*dest;
	int		i;
	int		len;

	len = ft_strlen(str);
	dest = ft_strnew(len);
	i = 0;
	while (str[i] != c && i < len)
	{
		dest[i] = str[i];
		i++;
	}
	return (dest);
}
