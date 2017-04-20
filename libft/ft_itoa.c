/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/08 15:47:17 by gphilips          #+#    #+#             */
/*   Updated: 2016/11/19 15:26:01 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static size_t	ft_get_len(int n)
{
	size_t	i;

	i = 0;
	if (n == 0)
		return (1);
	if (n < 0)
		i += 1;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char			*ft_itoa(int n)
{
	char			*dest;
	size_t			len;
	size_t			i;

	len = ft_get_len(n);
	if (!(dest = ft_strnew(len)))
		return (NULL);
	if (n == 0)
		return (ft_strcpy(dest, "0"));
	if (n == -2147483648)
		return (ft_strcpy(dest, "-2147483648"));
	i = 0;
	if (n < 0)
	{
		dest[i] = '-';
		n = -n;
	}
	while (n > 0)
	{
		dest[len - 1] = (n % 10) + '0';
		n /= 10;
		len--;
	}
	return (dest);
}
