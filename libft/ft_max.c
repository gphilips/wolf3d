/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_max.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/18 21:05:52 by gphilips          #+#    #+#             */
/*   Updated: 2016/11/19 15:32:56 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_max(int *tab, unsigned int len)
{
	unsigned int	i;
	int				max;

	i = 0;
	max = -214748348;
	if (tab)
	{
		while (i < len)
		{
			if (tab[i] > max)
				max = tab[i];
		}
		return (max);
	}
	else
		return (0);
}
