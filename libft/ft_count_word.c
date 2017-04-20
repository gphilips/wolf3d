/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_word.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gphilips <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/04/02 13:11:22 by gphilips          #+#    #+#             */
/*   Updated: 2017/04/02 13:11:24 by gphilips         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_word(const char *s, char c)
{
	int	i;
	int	count;
	int is_word;

	i = 0;
	count = 0;
	is_word = 0;
	while (s[i++])
	{
		if (is_word == 1 && s[i] == c)
			is_word = 0;
		if (is_word == 1 && s[i] != c)
		{
			is_word = 1;
			count++;
		}
	}
	return (count);
}
